#include "../include/juego.h"
#include "../../common_libs/include/common_estado_juego.h"

#define MARGEN_PARA_HIT 10

Juego::Juego(std::map<int, Queue<EstadoJuego>&>& clientes, std::list<Personaje>& personajes, int modo,
             Queue<Evento*>* queueJuego) : ejecutar(queueJuego), clientes(clientes), personajes(personajes),
             keep_running(true), kpPartida(true), modo(modo) {}

void Juego::run() {

    GeneradorZombies generador_zombies(cantidad_zombies, std::ref(zombies),
                                       std::ref(witches), std::ref(personajes),
                                       MAX_X, MAX_Y, modo);
    initGame();
    while (kpPartida) {
        std::vector<EstadoJuego> estados;
        // Me fijo de ejecutar eventos
        // Le mando a todos los clientes el estado del juego
        // Espero para poder mandarlo más o menos cada 1/60 segundos
        Evento* evento;
        while (ejecutar->try_pop(evento)) {
            int id = evento->get_id_personaje();
            Personaje* personaje = getPersonaje(id);
            evento->ejecutar(personaje);
        }

        // Veo si los zombies siguen vivos
        /*for (auto it = zombies.begin(); it != zombies.end(); ++it) {
            Zombie* zombie = *it;
            if (zombie->get_vida() <= 0) {
                zombie->morir();
                estados.emplace_back(zombie);
                zombies.erase(it);
                delete zombie;
            }
        }*/

        // Veo si los zombies chocaron con algun personaje
        /*for (auto zombie : zombies) {
            for (auto it2 = personajes.begin(); it2 != personajes.end(); ++it2) {
                if (zombie->choco_con_personaje(*it2)) {
                    // Si chocaron, le saco vida al personaje
                    it2->recibir_danio(zombie->get_danio());
                    // Si el personaje se quedo sin vida, lo saco del juego
                    if (it2->get_vida() <= 0) {
                        estados.emplace_back(*it2, 0x01);
                        personajes.erase(it2);
                    }
                }
            }
        }*/

        // Veo si los personajes le dispararon a algun zombie o MARGEN_PARA_HIT pixeles alrededor
        /*for (auto & personaje : personajes) {
            if (personaje.get_disparando()) {
                std::vector<int> posicion = personaje.get_posicion();
                for (auto it2 = zombies.begin(); it2 != zombies.end(); ++it2) {
                    Zombie* zombie = *it2;
                    int x_zombie = zombie->get_x();
                    int y_zombie = zombie->get_y();
                    if (x_zombie >= posicion[0] - MARGEN_PARA_HIT && x_zombie <= posicion[0] + MARGEN_PARA_HIT &&
                        y_zombie >= posicion[1] - MARGEN_PARA_HIT && y_zombie <= posicion[1] + MARGEN_PARA_HIT) {
                        zombie->recibir_danio(personaje.get_danio());
                    }
                }
            }
        }*/

        // Muevo a los zombies
       /* for (auto zombie : zombies) {
            zombie->mover(personajes);
        }*/

        // Veo si hay witches vivas
        //if (witches.size() > 0) {
            //if (generador_zombies.isApurado())
          //  generador_zombies.apurar();
       // } else {
        //    generador_zombies.desapurar();
      //  }

        // Genero zombies
        //generador_zombies.generar_zombie();

        // Mando el estado del juego a todos los clientes
        for (auto it = personajes.begin(); it != personajes.end(); ++it) {
            estados.emplace_back(*it, 0x02);
        }
        /*for (auto & zombie : zombies) {
            estados.emplace_back(zombie);
        }*/
        for (auto& cliente : clientes) {
            for (auto& estado : estados) {
                cliente.second.push(estado);
            }
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

void Juego::initGame() {
    std::vector<EstadoJuego> estados;
    for (auto & personaje : personajes) {
        estados.emplace_back(personaje, 0x00);
    }
    for (auto & cliente : clientes) {
        for (auto & it2 : estados) {
            cliente.second.push(it2);
        }
    }
}

void Juego::stop() {
    kpPartida.store(false);
}

Juego::~Juego() {
    stop();
}

Queue<Evento*>* Juego::getQueue() {
    return ejecutar;
}

Personaje* Juego::getPersonaje(int id) {
    for (auto it = personajes.begin(); it != personajes.end(); ++it) {
        Personaje* personaje = &(*it);
        if (personaje->get_id() == id) {
            return personaje;
        }
    }
    return nullptr;
}

bool Juego::gameRunning() {
    std::lock_guard<std::mutex> lock(m);
    //return isRunning.load();
    return true;
}

