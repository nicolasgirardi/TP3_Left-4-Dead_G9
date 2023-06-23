#include "../include/server_reciever.h"

Reciever::Reciever() : queue(nullptr), running(false), keep_running(false) {}

Reciever::Reciever(Socket* socket, Queue<Evento*>* queue, int id) :
        running(true), keep_running(false), id(id), queue(queue) {
    protocolo = new Protocolo(socket, queue, id);
}

void Reciever::run() {
    while (keep_running) {
        Evento* evt = protocolo->recibir_evento(std::ref(id));
        queue->push(evt);
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
Reciever& Reciever::operator=(Reciever& other) {
    this->queue = other.queue;
    this->running = other.running;
    this->keep_running = other.keep_running;
    other.queue = nullptr;
    return *this;
}

Reciever& Reciever::operator=(const Reciever &) {
    return *this;
}
