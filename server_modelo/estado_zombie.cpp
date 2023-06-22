#include "estado_zombie.h"

EstadoZombie::EstadoZombie(Zombie* zombie){
    this->id_zombie = zombie->get_tipo_zombie();
    this->x = zombie->get_x();
    this->y = zombie->get_y();
}

EstadoZombie::~EstadoZombie(){}

std::string EstadoZombie::serializar(){
    std::string estado = "";
    estado += this->id_zombie;
    estado += ",";
    estado += this->x;
    estado += ",";
    estado += this->y;
    //
    return estado;
}