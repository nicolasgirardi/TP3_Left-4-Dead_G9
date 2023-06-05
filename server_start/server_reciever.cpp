#include "server_reciever.h"

Reciever::Reciever(Socket* socket, Queue<Evento*>* queue) :
    socket(socket), queue(queue), running(true), keep_running(true) {}

void Reciever::run() {
    while (keep_running) {
        // Leo del protocolo y lo mando a la queue
    }
    running = false;
}

void Reciever::stop() {
    keep_running = false;
}

Reciever::~Reciever() {
    stop();
}

// Genero el = borrando el viejo asi no se genera una copia
Reciever& Reciever::operator=(Reciever& other) {
    this->socket = other.socket;
    this->queue = other.queue;
    this->running = other.running;
    this->keep_running = other.keep_running;
    other.socket = nullptr;
    other.queue = nullptr;
    return *this;
}