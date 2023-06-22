#ifndef LEFT4DEAD_ESTADO_ZOMBIE_H
#define LEFT4DEAD_ESTADO_ZOMBIE_H


#include "zombies/zombie.h"

class EstadoZombie{
private:
    int id_zombie;
    int x;
    int y;

public:
    EstadoZombie(Zombie* zombie);
    ~EstadoZombie();
    std::string serializar();
};

#endif //LEFT4DEAD_ESTADO_ZOMBIE_H
