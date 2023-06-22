#ifndef ESTADO_ZOMBIE_H
#define ESTADO_ZOMBIE_H

#include "./zombies/zombie.h"

class EstadoZombie{
        private:
        int id_zombie;
        int x;
        int y;

    public:
        EstadoZombie(Zombie* zombie);
        ~EstadoZombie();
        std::string serializar();
}

#endif // ESTADO_ZOMBIE_H
