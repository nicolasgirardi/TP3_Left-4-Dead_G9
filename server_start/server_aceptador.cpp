#include "server_aceptador.h"

Aceptador::Aceptador(const char* port) : socket(port) {
    this->running = true;
    this->keep_running = true;
}

void Aceptador::run() {
    while (keep_running) {
        Socket peer = socket.accept();
        //Juego* juego = new Juego(std::move(peer), &juegos);
        //juego->start();
        //juegos.push(juego);
        //juegos.check_finished();
    }
    running = false;
    // Cierro los juegos que quedaron abiertos
    //juegos.end();
}

void Aceptador::stop() {
    keep_running = false;
    // Fuerzo a un cierre total del socket
    socket.shutdown(2);
    socket.close();
    //juegos.end();
}
