#include "server_reciever.h"
#include "../common_libs/protocol.h"

Reciever::Reciever(Protocol& protocol, Queue<Evento*>* queue) :
    protocol(protocol), queue(queue), running(true), keep_running(true) {}

void Reciever::run() {
    while (keep_running) {
        // Leo del protocolo y lo mando a la queue
    }
    running = false;
}

void Reciever::stop() {
    keep_running = false;
}

bool Reciever::is_running() {
    return running;
}

Reciever::~Reciever() {
    stop();
}

// Genero el = borrando el viejo asi no se genera una copia
/*Reciever& Reciever::operator=(Reciever& other) {
    this->socket = other.socket;
    this->queue = other.queue;
    this->running = other.running;
    this->keep_running = other.keep_running;
    other.socket = nullptr;
    other.queue = nullptr;
    return *this;
}*/