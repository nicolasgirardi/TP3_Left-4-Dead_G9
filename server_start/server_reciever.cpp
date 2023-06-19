#include "server_reciever.h"

Reciever::Reciever(Protocolo* protocol, Queue<Evento*>* queue) :
        protocolo(protocol), queue(queue), running(true), keep_running(true) {}

        //TODO : REVISAR RECIEVER
void Reciever::run() {
    while (keep_running) {
        uint8_t codigo = protocolo->recibir_codigo();
        switch (codigo) {
            case 0x03: {
                // move
                std::pair<int32_t, int32_t> coordenadas = protocolo->move();
                Evento* evento = CreadorEventos::crearEvento(0, id, coordenadas.first, coordenadas.second);
                queue->push(evento);
                break;
            }
            case 0x04: {
                // stop move
                Evento* evento = CreadorEventos::crearEvento(1, id, 0, 0);
                queue->push(evento);
                break;
            }
            case 0x05: {
                // shoot
                Evento* evento = CreadorEventos::crearEvento(2, id);
                queue->push(evento);
                break;
            }
            case 0x06: {
                // stop shoot
                Evento* evento = CreadorEventos::crearEvento(3, id);
                queue->push(evento);
                break;
            }
            default: {
                // no deberia llegar aca
                break;
            }
        }
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
