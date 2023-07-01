#ifndef ZOMBIE_H_
#define ZOMBIE_H_

#include <list>
#include <string>
#include "../common_personaje.h"

class Zombie {
 private:
    int x;
    int y;
    int vida = 50;
    float velocidad = 0.5;
    int danio = 10;
    int tipo_zombie = 0;
    uint8_t abm;

 public:
        Zombie(int x, int y);
        int get_x();
        int get_y();
        int get_vida();
        int get_velocidad();
        int get_danio();
        int get_tipo_zombie();
        ~Zombie();
        void mover(std::list<Personaje>& personajes);
        bool esta_vivo();
        void recibir_danio(int danio);
        bool choco_con_personaje(Personaje& personaje);

    uint8_t get_abm() const;

    void morir();
};

#endif  // ZOMBIE_H_
