#include "../include/juego.h"

#define PIXELES_PARA_HIT 10

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
    // Creo el generador de zombies
    GeneradorZombies generador_zombies(cantidad_zombies, &zombies, &witches, &personajes, MAX_X, MAX_Y, modo);
    generador_zombies.start();
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

        // Veo si los zombies siguen vivos
        for (auto it = zombies.begin(); it != zombies.end(); ++it) {
            Zombie* zombie = *it;
            if (zombie->get_vida() <= 0) {
                zombies.erase(it);
                delete zombie;
            }
        }

        // Veo si los zombies chocaron con algun personaje
        for (auto it = zombies.begin(); it != zombies.end(); ++it) {
            Zombie* zombie = *it;
            for (auto it2 = personajes.begin(); it2 != personajes.end(); ++it2) {
                Personaje* personaje = *it2;
                if (zombie->choco_con_personaje(personaje)) {
                    // Si chocaron, le saco vida al personaje
                    personaje->recibir_danio(zombie->get_danio());
                    // Si el personaje se quedo sin vida, lo saco del juego
                    if (personaje->get_vida() <= 0) {
                        personajes.erase(it2);
                    }
                }
            }
        }

        // Veo si los personajes le dispararon a algun zombie o PIXELES_PARA_HIT pixeles alrededor
        for (auto it = personajes.begin(); it != personajes.end(); ++it) {
            Personaje* personaje = *it;
            if (personaje->get_disparando()) {
                std::vector<int> posicion = personaje->mover(0, 0);
                for (auto it2 = zombies.begin(); it2 != zombies.end(); ++it2) {
                    Zombie* zombie = *it2;
                    int x_zombie = zombie->get_x();
                    int y_zombie = zombie->get_y();
                    if (x_zombie >= posicion[0] - PIXELES_PARA_HIT && x_zombie <= posicion[0] + PIXELES_PARA_HIT &&
                        y_zombie >= posicion[1] - PIXELES_PARA_HIT && y_zombie <= posicion[1] + PIXELES_PARA_HIT) {
                        zombie->recibir_danio(personaje->get_danio());
                    }
                }
            }
        }

        // Muevo a los zombies
        for (auto it = zombies.begin(); it != zombies.end(); ++it) {
            Zombie* zombie = *it;
            zombie->mover(personajes);
        }

        // Veo si hay witches vivas
        if (witches.size() > 0) {
            if (generador_zombies.isApurado())
                generador_zombies.apurar();
        } else {
            generador_zombies.desapurar();
        }

        // Mando el estado del juego a todos los clientes
        std::string estado = "";
        for (auto it = personajes.begin(); it != personajes.end(); ++it) {
            EstadoJugador estado_jugador(*it);
            estado += estado_jugador.serializar();
        }
        for (auto it = zombies.begin(); it != zombies.end(); ++it) {
            EstadoZombie estado_zombie(*it);
            estado += estado_zombie.serializar();
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
    generador_zombies.stop();
    generador_zombies.join();
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