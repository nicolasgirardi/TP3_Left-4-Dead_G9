#include <netinet/in.h>
#include "server_protocolo.h"
#include "../server_modelo/eventos/creador_eventos.h"

Protocolo::Protocolo(Socket* socket, Queue<Evento*>* queue, int id) :
        socket(socket), queue(queue), id(id), wasClosed(false){}

Protocolo::~Protocolo() {}

uint8_t Protocolo::recibir_codigo() {
    uint8_t codigo;
    socket->recvall(&codigo, 1, &wasClosed);
    return codigo;
}

std::string Protocolo::recibir_nombre() {
    uint8_t largo_nombre;
    socket->recvall(&largo_nombre, 1, &wasClosed);
    char nombre[largo_nombre + 1];
    socket->recvall(nombre, largo_nombre, &wasClosed);
    nombre[largo_nombre] = '\0';
    std::string nombre_str(nombre);
    return nombre_str;
}

uint32_t Protocolo::recibir_codigo_partida() {
    uint32_t codigo;
    socket->recvall(&codigo, 4, &wasClosed);
    return codigo;
}

std::pair<int32_t, int32_t> Protocolo::recibir_coordenadas() {
    int32_t x;
    int32_t y;
    socket->recvall(&x, 4, &wasClosed);
    socket->recvall(&y, 4, &wasClosed);
    return std::make_pair(x, y);
}

void Protocolo::enviar_codigo_partida(uint32_t codigo) {
    socket->sendall(&codigo, 4, &wasClosed);
}

void Protocolo::enviar_estado_juego(std::string estado) {
    uint32_t largo = estado.length();
    socket->sendall(&largo, 4, &wasClosed);
    socket->sendall(estado.c_str(), largo, &wasClosed);
}

Message Protocolo::recibir_estado_juego(){
    uint32_t largo;
    socket->recvall(&largo, 4, &wasClosed);
    char estado[largo + 1];
    socket->recvall(estado, largo, &wasClosed);
    estado[largo] = '\0';
    std::string estado_str(estado);
    //Parse String to Message
    Message message;
    message.ParseFromString(std::ref(estado_str));
    return message;
}

uint32_t Protocolo::join() {
    return 0;
}

std::pair<int32_t, int32_t> Protocolo::move() {
    int32_t param1 = recvCuatroBytes();
    int32_t param2 = recvCuatroBytes();
    return std::pair<int32_t, int32_t>(param1, param2);
}

uint16_t Protocolo::recvDosBytes() {
    uint16_t aux;
    socket->recvall(&aux, 2, &wasClosed);
    return ntohs(aux);
}

uint32_t Protocolo::recvCuatroBytes() {
    uint32_t aux;
    socket->recvall(&aux, 4, &wasClosed);
    return ntohl(aux);
}

uint8_t Protocolo::recvByte() {
    uint8_t aux;
    socket->recvall(&aux, 1, &wasClosed);
    return aux;
}

std::string Protocolo::recibir_inicio_partida() {
    uint8_t inicioPartida = recvByte();
    switch (inicioPartida) {
        case ClienteMensaje::CREAR:
            return "crear";
        case ClienteMensaje::JOIN:
            return "join";
        default:
            return "0";
    }
}

Evento *Protocolo::recibir_evento(int& idPersonaje) {
    uint8_t codigo = recvByte();
    switch (codigo) {
        case ClienteMensaje::MOVE: {
            int32_t param1 = recvCuatroBytes();
            int32_t param2 = recvCuatroBytes();
            return CreadorEventos::crearEvento(0, idPersonaje, param1, param2);
        }
        case ClienteMensaje::STOP_MOVE: {
            int32_t param1 = recvCuatroBytes();
            int32_t param2 = recvCuatroBytes();
            return CreadorEventos::crearEvento(1, idPersonaje, param1, param2);
        }
        case ClienteMensaje::SHOOT: {
            return CreadorEventos::crearEvento(2, idPersonaje);
        }
        case ClienteMensaje::STOP_SHOOT: {
            return CreadorEventos::crearEvento(3, idPersonaje);
        }
        default: {
            return nullptr;
        }
    }
}
