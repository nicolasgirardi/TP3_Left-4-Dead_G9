
#include "../include/common_protocolo.h"

Protocolo::Protocolo(Socket socket) : socket(std::move(socket)), wasClosed(false) {}

Protocolo::Protocolo(const std::string &hostname, const std::string &servname)
        : socket(hostname.c_str(), servname.c_str()), wasClosed(false) {}

//Protocolo::Protocolo(Socket &&peer) : socket(std::move(peer)), wasClosed(false){}

Protocolo::~Protocolo() {}

void Protocolo::sendByte(uint8_t byte) {
    socket.sendall(&byte, 1, &wasClosed);
}

void Protocolo::sendDosBytes(uint16_t dosBytes) {
    uint16_t dosBytesNet = htons(dosBytes);
    socket.sendall(&dosBytesNet, 2, &wasClosed);
}

void Protocolo::sendCuatroBytes(int32_t param1) {
    uint32_t aux = htonl(param1);
    socket.sendall(&aux, 4, &wasClosed);
}

int Protocolo::sendData(const std::string &data) {
    return socket.sendall(data.c_str(), data.size(), &wasClosed);
}

uint16_t Protocolo::recvDosBytes() {
    uint16_t aux;
    socket.recvall(&aux, 2, &wasClosed);
    return ntohs(aux);
}

uint32_t Protocolo::recvCuatroBytes() {
    uint32_t aux;
    socket.recvall(&aux, 4, &wasClosed);
    return ntohl(aux);
}

uint8_t Protocolo::recvByte() {
    uint8_t aux;
    socket.recvall(&aux, 1, &wasClosed);
    return aux;
}

void Protocolo::enviar_codigo_partida(uint32_t codigo) {
    sendCuatroBytes(codigo);
}

void Protocolo::enviar_estado_juego(EstadoJuego& estadoJuego) {
    uint32_t result = 0;
    result |= static_cast<uint32_t>(estadoJuego.get_game_over()) << 24;
    result |= static_cast<uint32_t>(estadoJuego.get_id()) << 16;
    result |= static_cast<uint32_t>(estadoJuego.get_id_character()) << 8;
    result |= static_cast<uint32_t>(estadoJuego.get_ABM());
    sendCuatroBytes(result);
    sendCuatroBytes(estadoJuego.get_x());
    sendCuatroBytes(estadoJuego.get_y());
    uint16_t aux =
            (static_cast<uint16_t>(estadoJuego.get_accion()) << 8) | static_cast<uint16_t>(estadoJuego.get_vida());
    sendDosBytes(aux);
}

std::string Protocolo::recibir_inicio_partida() {
    uint8_t inicioPartida = recvByte();
    switch (inicioPartida) {
        case CMensaje::ClienteMensaje::CREAR:
            return "crear";
        case CMensaje::ClienteMensaje::JOIN:
            return "join";
        default:
            return "0";
    }
}

uint32_t Protocolo::recibir_codigo_partida() {
    return recvCuatroBytes();
}
//TODO: DEBERIA QUEDAR ASI
/*std::vector<Message> Protocolo::recibir_estado_juego(){
    uint32_t largo;
    socket.recvall(&largo, 4, &wasClosed);
    char estado[largo + 1];
    socket.recvall(estado, largo, &wasClosed);
    estado[largo] = '\0';
    std::string estado_str(estado);

    return getMessage(std::ref(estado_str));
}*/

Message Protocolo::recibir_estado_juego(){
    uint32_t aux = recvCuatroBytes();
    uint8_t game_over, id, id_character, ABM, posX, posY, accion, vida;
    game_over = (aux >> 24) & 0xFF;
    id = (aux >> 16) & 0xFF;
    id_character = (aux >> 8) & 0xFF;
    ABM = aux & 0xFF;

    posX = recvCuatroBytes();
    posY = recvCuatroBytes();
    uint16_t dosBytes = recvDosBytes();
    accion = (dosBytes >> 8) & 0xFF;
    vida = dosBytes & 0xFF;
    Type_of_character character = get_character(id_character);
    Type_of_AMB abm = get_AMB(ABM);
    if (game_over == 0x01) {
        return {id, character, abm};
    }
    Type_of_action action = get_action(accion);
    return {id, action, posX, posY, character, abm, 0x00000000, vida};
}

std::string Protocolo::recibir_nombre() {
    uint8_t largo_nombre;
    socket.recvall(&largo_nombre, 1, &wasClosed);
    char nombre[largo_nombre + 1];
    socket.recvall(nombre, largo_nombre, &wasClosed);
    nombre[largo_nombre] = '\0';
    std::string nombre_str(nombre);
    return nombre_str;
}

Personaje Protocolo::recibir_personaje() {
    uint8_t idPersonaje = recvByte();
    uint8_t idArma = recvByte();
    return {static_cast<int>(idPersonaje), static_cast<int>(idArma)};
}

uint8_t Protocolo::recibir_modo() {
    return recvByte();
}

Evento *Protocolo::recibir_evento(int& idPersonaje) {
    uint8_t codigo = recvByte();
    switch (codigo) {
        case CMensaje::ClienteMensaje::MOVE: {
            int32_t param1 = recvCuatroBytes();
            int32_t param2 = recvCuatroBytes();
            return CreadorEventos::crearEvento(0, idPersonaje, param1, param2);
        }
        case CMensaje::ClienteMensaje::STOP_MOVE: {
            return CreadorEventos::crearEvento(1, idPersonaje);
        }
        case CMensaje::ClienteMensaje::SHOOT: {
            return CreadorEventos::crearEvento(2, idPersonaje);
        }
        case CMensaje::ClienteMensaje::STOP_SHOOT: {
            return CreadorEventos::crearEvento(3, idPersonaje);
        }
        default: {
            return nullptr;
        }
    }
}

void Protocolo::enviar_inicio_partida(std::vector<std::string> inicioPartida) {
    std::string inicio = inicioPartida[0];
    if (inicio == "crear") {
        sendByte(0x01);
        uint8_t lenNombre = strlen(inicioPartida.at(1).c_str());
        sendByte(lenNombre);
        sendData(inicioPartida.at(1));
        uint8_t modo = atoi(inicioPartida.at(2).c_str());
        sendByte(modo);
    } else if (inicio == "join") {
        sendByte(0x02);
        sendCuatroBytes(atoi(inicioPartida.at(1).c_str()));
    } else {
        std::cout << "Error en el envio de inicio de partida" << std::endl;
    }
}

void Protocolo::enviar_info(std::string info) {
    if(info == "soldier1") {
        sendByte(0x01);
        sendByte(0x00);

    } else if (info == "soldier2") {
        sendByte(0x02);
        sendByte(0x01);
    } else if (info == "soldier3") {
        sendByte(0x03);
        sendByte(0x02);
    } else {std::cout << "Error en el envio de info" << std::endl;}
}

void Protocolo::enviar_evento(const EventoUsuario &eventoUsuario) {
    sendByte(eventoUsuario.getIdEvento());
    if (eventoUsuario.getIdEvento() == CMensaje::ClienteMensaje::MOVE) {
        sendCuatroBytes(eventoUsuario.getParam1());
        sendCuatroBytes(eventoUsuario.getParam2());
    }
}
//TODO: DEBERIA QUEDAR ASI
/*
std::vector<Message> Protocolo::getMessage(std::string &estadoJuego) {

    //separar por /n
    std::string delimiter = ",";
    std::string token = estadoJuego.substr(0, estadoJuego.find(delimiter));
    int id = std::stoi(token);
    estadoJuego.erase(0, estadoJuego.find(delimiter) + delimiter.length());

    token = estadoJuego.substr(0, estadoJuego.find(delimiter));
    myenum::Type_of_action action = (myenum::Type_of_action) std::stoi(token);
    estadoJuego.erase(0, estadoJuego.find(delimiter) + delimiter.length());

    token = estadoJuego.substr(0, estadoJuego.find(delimiter));
    int pos_x = std::stoi(token);
    estadoJuego.erase(0, estadoJuego.find(delimiter) + delimiter.length());

    token = estadoJuego.substr(0, estadoJuego.find(delimiter));
    int pos_y = std::stoi(token);
    estadoJuego.erase(0, estadoJuego.find(delimiter) + delimiter.length());

    token = estadoJuego.substr(0, estadoJuego.find(delimiter));
    Type_of_character type = (Type_of_character) std::stoi(token);
    estadoJuego.erase(0, estadoJuego.find(delimiter) + delimiter.length());

    token = estadoJuego.substr(0, estadoJuego.find(delimiter));
    Type_of_AMB ABM = (Type_of_AMB) std::stoi(token);
    estadoJuego.erase(0, estadoJuego.find(delimiter) + delimiter.length());

    token = estadoJuego.substr(0, estadoJuego.find(delimiter));
    uint32_t ammo = std::stoi(token);
    estadoJuego.erase(0, estadoJuego.find(delimiter) + delimiter.length());

    token = estadoJuego.substr(0, estadoJuego.find(delimiter));
    uint32_t hp = std::stoi(token);
    estadoJuego.erase(0, estadoJuego.find(delimiter) + delimiter.length());
    //Problemas con el endiannes por mandar en String
    return {id, action, pos_x, pos_y, type, ABM, ammo, hp};
}

Message Protocolo::getMessage(std::string &estadoJuego) {

    //separar por /n
    std::string delimiter = ",";
    std::string token = estadoJuego.substr(0, estadoJuego.find(delimiter));
    int id = std::stoi(token);
    estadoJuego.erase(0, estadoJuego.find(delimiter) + delimiter.length());

    token = estadoJuego.substr(0, estadoJuego.find(delimiter));
    myenum::Type_of_action action = (myenum::Type_of_action) std::stoi(token);
    estadoJuego.erase(0, estadoJuego.find(delimiter) + delimiter.length());

    token = estadoJuego.substr(0, estadoJuego.find(delimiter));
    int pos_x = std::stoi(token);
    estadoJuego.erase(0, estadoJuego.find(delimiter) + delimiter.length());

    token = estadoJuego.substr(0, estadoJuego.find(delimiter));
    int pos_y = std::stoi(token);
    estadoJuego.erase(0, estadoJuego.find(delimiter) + delimiter.length());

    token = estadoJuego.substr(0, estadoJuego.find(delimiter));
    Type_of_character type = (Type_of_character) std::stoi(token);
    estadoJuego.erase(0, estadoJuego.find(delimiter) + delimiter.length());

    token = estadoJuego.substr(0, estadoJuego.find(delimiter));
    Type_of_AMB ABM = (Type_of_AMB) std::stoi(token);
    estadoJuego.erase(0, estadoJuego.find(delimiter) + delimiter.length());

    token = estadoJuego.substr(0, estadoJuego.find(delimiter));
    uint32_t ammo = std::stoi(token);
    estadoJuego.erase(0, estadoJuego.find(delimiter) + delimiter.length());

    token = estadoJuego.substr(0, estadoJuego.find(delimiter));
    uint32_t hp = std::stoi(token);
    estadoJuego.erase(0, estadoJuego.find(delimiter) + delimiter.length());
    //Problemas con el endiannes por mandar en String
    return {id, action, pos_x, pos_y, type, ABM, ammo, hp};
}*/

std::string Protocolo::recvData() {
    uint32_t largo = recvCuatroBytes();
    std::vector<char> estado(largo + 1);
    socket.recvall(&estado[0], largo, &wasClosed);
    estado[largo + 1] = '\0';
    return estado.data();
}
