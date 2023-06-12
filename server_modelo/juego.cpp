#include "juego.h"

Juego::Juego() : ejecutar(MAX_EVENTOS) {
    this->running = true;
    this->keep_running = true;
}

void Juego::launch(std::map<int, Queue<std::string>*>* clientes, std::list<Personaje*> personajes, int modo) {
    this->clientes = clientes;
    this->personajes = personajes;
    this->modo = modo;
    start();
}

void Juego::run() {
    while (keep_running) {
        // Me fijo de ejecutar eventos
        // Le mando a todos los clientes el estado del juego
        // Espero para poder mandarlo más o menos cada 1/60 segundos
        Evento* evento;
        while (ejecutar.try_pop(evento)) {
            int id = evento->get_id_personaje();
            Personaje* personaje = getPersonaje(id);
            evento->ejecutar(personaje);
        }

        // Me fijo el modo de juego

        // Mando el estado del juego a todos los clientes
        std::string estado = "";
        for (auto it = personajes.begin(); it != personajes.end(); ++it) {
            EstadoJugador estado_jugador(*it);
            estado += estado_jugador.serializar();
        }
        for (auto& cliente : *clientes) {
            cliente.second->push(estado);
        }

        // Simulo el paso del tiempo
        std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
        
        // Espero hasta que pase 1/60 segundos
        std::chrono::steady_clock::time_point end_time = start_time;
        std::chrono::duration<double> elapsed_seconds = end_time - start_time;
        double target_frame_time = 1.0 / 60.0;  // 1/60 segundos
        while (elapsed_seconds.count() < target_frame_time) {
            end_time = std::chrono::steady_clock::now();
            elapsed_seconds = end_time - start_time;
        }
    }
}

void Juego::stop() {
    keep_running = false;
}

Juego::~Juego() {
    stop();
}

Queue<Evento*>* Juego::getQueue() {
    return &ejecutar;
}

Personaje* Juego::getPersonaje(int id) {
    for (auto& personaje : personajes) {
        if (personaje->get_id() == id) {
            return personaje;
        }
    }
    return nullptr;
}
