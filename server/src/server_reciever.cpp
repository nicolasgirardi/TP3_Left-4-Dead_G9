#include "../include/server_reciever.h"


Reciever::Reciever(Protocolo& protocolo, Queue<Evento*>* queueJuego, int id) :
        protocolo(protocolo), running(true), keep_running(true), id(id), queueJuego(queueJuego) {}

void Reciever::run() {
    while (keep_running) {
        Evento* evt = protocolo.recibir_evento(std::ref(id));
        queueJuego->push(evt);
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
    this->protocolo = other.protocolo;
    this->running = other.running;
    this->keep_running = other.keep_running;
    this->id = other.id;
    this->queueJuego = other.queueJuego;
    return *this;
}

Reciever& Reciever::operator=(const Reciever &) {
    return *this;
}*/
