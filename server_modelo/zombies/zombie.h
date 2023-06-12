#ifndef ZOMBIE_H_
#define ZOMBIE_H_

#include <list>
#include "./../personaje.h"

class Zombie {
 private:
    int x;
    int y;
    int vida = 50;
    float velocidad = 0.5;

    public:
        Zombie(int x, int y);
        int get_x();
        int get_y();
        int get_vida();
        int get_velocidad();
        ~Zombie();
        void mover(std::list<Personaje*> personajes);
        bool esta_vivo();
        void recibir_danio(int danio);
};

#endif  // ZOMBIE_H_