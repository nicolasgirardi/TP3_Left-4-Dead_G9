#include <netinet/in.h>
#include <string>
#include "../include/Protocol.h"

Protocol::Protocol(const std::string port) : socket(port.c_str()), wasClosed(false) {}

void Protocol::sendAction(const UserAction& action) {
    sendByte(action.getIdAction());
    sendFourBytes(action.getParam1());
    sendFourBytes(action.getParam2());
}

void Protocol::sendByte(const uint8_t byte) {
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

int32_t Protocol::recvFourBytes() {
    uint32_t aux;
    this->socket.recvall(&aux, 4, &wasClosed);
    return ntohl(aux);
}

void Protocol::closeConection() {
    this->socket.shutdown(SHUT_RDWR);
    this->socket.close();
}
