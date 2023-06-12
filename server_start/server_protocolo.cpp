#include "server_protocolo.h"

Protocolo::Protocolo(Socket* socket, Queue<Evento*>* queue, int id) :
    socket(socket), queue(queue), id(id) {}

Protocolo::~Protocolo() {}

uint8_t Protocolo::recibir_codigo() {
    uint8_t codigo;
    socket->recvall(&codigo, 1, 0);
    return codigo;
}

std::string Protocolo::recibir_nombre() {
    uint8_t largo_nombre;
    socket->recvall(&largo_nombre, 1, 0);
    char nombre[largo_nombre + 1];
    socket->recvall(nombre, largo_nombre, 0);
    nombre[largo_nombre] = '\0';
    std::string nombre_str(nombre);
    return nombre_str;
}

uint32_t Protocolo::recibir_codigo_partida() {
    uint32_t codigo;
    socket->recvall(&codigo, 4, 0);
    return codigo;
}

std::pair<int32_t, int32_t> Protocolo::recibir_coordenadas() {
    int32_t x;
    int32_t y;
    socket->recvall(&x, 4, 0);
    socket->recvall(&y, 4, 0);
    return std::make_pair(x, y);
}

void Protocolo::enviar_codigo_partida(uint32_t codigo) {
    socket->sendall(&codigo, 4, 0);
}

void Protocolo::enviar_estado_juego(std::string estado) {
    uint32_t largo = estado.length();
    socket->sendall(&largo, 4, 0);
    socket->sendall(estado.c_str(), largo, 0);
}