#include "../../include/zombies/generador_zombies.h"

#include <unistd.h>

#include <iostream>

GeneradorZombies::GeneradorZombies(int cantidad_zombies,
                                   std::list<Zombie*>* zombies,
                                   std::list<Witch*>* witches,
                                   std::list<Personaje*>* personajes,
                                   int max_x, int max_y, int modo) :
                                   running(false),
                                   keep_running(true),
                                   cantidad_zombies(cantidad_zombies),
                                   modo(modo),
                                   zombies(zombies),
                                   personajes(personajes),
                                   max_x(max_x),
                                   max_y(max_y) {}

GeneradorZombies::~GeneradorZombies() {}

void GeneradorZombies::run() {
    running = true;
    int contador_zombies = 0;
    while (keep_running) {
        // Me fijo el modo de juego
        // Si es supervivencia, genero zombies cada 5 segundos
        if (modo == 1) {
            // Genero un zombie cada 5 segundos
            std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
            // Espero hasta que pase 5 segundos
            std::chrono::steady_clock::time_point end_time = start_time;
            std::chrono::duration<double> elapsed_seconds = end_time - start_time;
            double target_frame_time = tiempo_creacion;  // 5 segundos
            while (elapsed_seconds.count() < target_frame_time) {
                end_time = std::chrono::steady_clock::now();
                elapsed_seconds = end_time - start_time;
            }

            // Genero un zombie
            int x = rand() % max_x;
            int y = rand() % max_y;
            Zombie* zombie = new Zombie(x, y);
            zombies->push_back(zombie);
            contador_witches++;
            if (contador_witches == 4) {
                contador_witches = 0;
                Witch* witch = new Witch(x, y);
            }
        } else if (modo == 0 && contador_zombies < cantidad_zombies) {
            // Genero un zombie cada 5 segundos
            std::chrono::steady_clock::time_point start_time = std::chrono::steady_clock::now();
            // Espero hasta que pase 5 segundos
            std::chrono::steady_clock::time_point end_time = start_time;
            std::chrono::duration<double> elapsed_seconds = end_time - start_time;
            double target_frame_time = 5.0;  // 5 segundos
            while (elapsed_seconds.count() < target_frame_time) {
                end_time = std::chrono::steady_clock::now();
                elapsed_seconds = end_time - start_time;
            }

            // Genero un zombie
            int x = rand() % max_x;
            int y = rand() % max_y;
            Zombie* zombie = new Zombie(x, y);
            zombies->push_back(zombie);
            contador_zombies++;
            contador_witches++;
            if (contador_witches == 4) {
                contador_witches = 0;
                Witch* witch = new Witch(x, y);
            }
        }
    }
    running = false;
}

void GeneradorZombies::stop() {
    keep_running = false;
}

void GeneradorZombies::apurar() {
    tiempo_creacion = tiempo_creacion / 2;
    apurado = true;
}

void GeneradorZombies::desapurar() {
    tiempo_creacion = tiempo_creacion * 2;
    apurado = false;
}

bool GeneradorZombies::isApurado() {
    return apurado;
}