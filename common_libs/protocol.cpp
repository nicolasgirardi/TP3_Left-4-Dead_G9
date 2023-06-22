#include "protocol.h"

Protocol::Protocol(Socket &&peer) : socket(std::move(peer)), wasClosed(false){}

void Protocol::sendByte(uint8_t byte) {
    this->socket.sendall(&byte, 1, &wasClosed);
}

void Protocol::sendCuatroBytes(int32_t param1) {
    uint32_t aux = htonl(param1);
    this->socket.sendall(&aux, 4, &wasClosed);
}

uint8_t Protocol::recvByte() {
    uint8_t byte;
    this->socket.recvall(&byte, 1, &wasClosed);
    return byte;
}

uint16_t Protocol::recvDosBytes() {
    uint16_t aux;
    this->socket.recvall(&aux, 2, &wasClosed);
    return ntohs(aux);
}

uint32_t Protocol::recvCuatroBytes() {
    uint32_t aux;
    this->socket.recvall(&aux, 4, &wasClosed);
    return ntohl(aux);
}

std::string Protocol::recvData(std::vector<char>& buff) {
    this->socket.recvall(buff.data(), buff.size(), &wasClosed);
    return std::string(buff.begin(), buff.end());
}

void Protocol::sendEvento(const EventoUsuario &evento) {
    sendByte(evento.getIdEvento());
    sendCuatroBytes(evento.getParam1());
    sendCuatroBytes(evento.getParam2());
}

void Protocol::cerrarConexion() {
    this->socket.shutdown(SHUT_RDWR);
    this->socket.close();
}

std::string Protocol::recibir_inicio_partida() {
    switch (recvByte()) {
        case 0x01:
            return "crear";
        case 0x02:
            return "join";
        default:
            return "error";
    }
}

std::string Protocol::recibir_nombre_partida() {
    uint8_t lenNombre = recvByte();
    std::vector<char> buff(lenNombre);
    return recvData(std::ref(buff));
}

uint32_t Protocol::recibir_codigo_partida() {
    return 0x01010101;
}

void Protocol::enviar_codigo_partida(uint32_t codigoPartida) {
    sendCuatroBytes(codigoPartida);
}

void Protocol::enviar_evento(Evento *evento) {
    sendByte(evento->get_id_personaje());
    sendCuatroBytes(0x00000000);
    sendCuatroBytes(0x00000000);
}
