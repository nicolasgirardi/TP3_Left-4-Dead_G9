#include "server_sender.h"

Sender::Sender(Partida* partida) {
    this->running = true;
    this->keep_running = true;
    this->partida = partida;
}

void Sender::run() {
    while (keep_running) {
        // Partida.estado()
        // Protocolo send
    }
    running = false;
}

void Sender::stop() {
    keep_running = false;
}

Sender::~Sender() {
    stop();
}