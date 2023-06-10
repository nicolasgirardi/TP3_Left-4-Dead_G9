#include <netinet/in.h>
#include <string>
#include "protocol.h"
#include "inicio_partida.h"

Protocol::Protocol(Socket &&peer) : socket(std::move(peer)), wasClosed(false){}

void Protocol::sendAction(const UserAction& action) {
    sendByte(action.getIdAction());
    sendFourBytes(action.getParam1());
    sendFourBytes(action.getParam2());
}

private void Protocol::sendByte(const uint8_t byte) {
    this->socket.sendall(&byte, 1, &wasClosed);
}

void Protocol::sendFourBytes(const int32_t param1) {
    uint32_t aux = htonl(param1);
    this->socket.sendall(&aux, 4, &wasClosed);
}

void Protocol::receiveUpdate(GameUpdate &update) {
    update.setTypeCharacter((CHARACTER) recvByte());
    update.setOwner(recvByte());
    update.setAction((ACTION) recvByte());
    update.setPosX(recvFourBytes());
    update.setPosY(recvFourBytes());
    update.setDirection(recvByte());
}

uint8_t Protocol::recvByte() {
    uint8_t byte;
    this->socket.recvall(&byte, 1, &wasClosed);
    return byte;
}

uint16_t Protocol::recvTwoBytes() {
    uint16_t aux;
    this->socket.recvall(&aux, 2, &wasClosed);
    return ntohs(aux);
}

uint32_t Protocol::recvFourBytes() {
    uint32_t aux;
    this->socket.recvall(&aux, 4, &wasClosed);
    return ntohl(aux);
}

void Protocol::closeConection() {
    this->socket.shutdown(SHUT_RDWR);
    this->socket.close();
}

std::string Protocol::recibir_inicio_partida() {
    switch (recvByte()) {
        case InicioPartida::crear:
            return InicioPartida::crearStr;
        case InicioPartida::join:
            return InicioPartida::joinStr;
        default:
            return InicioPartida::error;
    }
}

std::string Protocol::recibir_nombre_partida() {
    uint16_t lenNombre = recvTwoBytes();
    std::string nombre(lenNombre, '\0');
    uint32_t bytesName = recvFourBytes();
    for (int i = 0; i < lenNombre; ++i) {
        nombre[i] = (char) (bytesName >> (8 * i));
    }
    return nombre;
}

uint32_t Protocol::recibir_codigo_partida() {

}

void Protocol::enviar_codigo_partida(uint32_t codigoPartida) {
    sendFourBytes(codigoPartida);
}
