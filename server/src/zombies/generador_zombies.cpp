#include "../../include/zombies/generador_zombies.h"

#include <unistd.h>

#include <iostream>

GeneradorZombies::GeneradorZombies(int cantidad_zombies,
                                   std::list<Zombie*>* zombies,
                                   std::list<Witch*>* witches,
                                   std::list<Personaje*>* personajes,
                                   int max_x, int max_y, int modo) :
                                   cantidad_zombies(cantidad_zombies),
                                   modo(modo),
                                   zombies(zombies),
                                   personajes(personajes),
                                   max_x(max_x),
                                   max_y(max_y) {}

GeneradorZombies::~GeneradorZombies() {}

void GeneradorZombies::generar_zombie() {
    int contador_zombies = 0;
        // Me fijo el modo de juego
        // Si es supervivencia, genero zombies cada 5 segundos
    if (frames_creacion >= tiempo_creacion) {
        if (modo == 1) {
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
        frames_creacion = 0;
    } else {
        frames_creacion++;
    }
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