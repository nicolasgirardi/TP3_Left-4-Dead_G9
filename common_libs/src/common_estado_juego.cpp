#include <iostream>
#include "../include/common_estado_juego.h"
#include "../include/common_myenum.h"

EstadoJuego::EstadoJuego(Personaje &personaje, uint8_t abm) : id(personaje.get_id()) {
    this->game_over = 0x00;
    this->x = personaje.get_posicion()[0];
    this->y = personaje.get_posicion()[1];
    int tipoArma = personaje.get_tipo_arma();
    switch (tipoArma) {
        case 1:
            this->id_character = 0x04;
            break;
        case 2:
            this->id_character = 0x03;
            break;
        case 3:
            this->id_character = 0x02;
            break;
        default:
            this->id_character = 0x02;
            break;
    }
    this->accion = setAccion(personaje.get_estado_movimiento(), personaje.get_disparando());
    this->ABM = abm;
    this->vida = personaje.get_vida();
}

EstadoJuego::EstadoJuego(Zombie *zombie) {
    this->id = zombie->get_id();
    this->game_over = 0x00;
    this->x = zombie->get_x();
    this->y = zombie->get_y();
    this->id_character = zombie->get_tipo_zombie();
    this->ABM = zombie->get_abm();
    this->accion = 0x00; // Attack hardcodeado
    this->vida = zombie->get_vida();
}
//TODO: Revisar
EstadoJuego::EstadoJuego(int idCliente, int idPersonaje) : id(idCliente), id_character(idPersonaje) {
    this->game_over = 0x01;
}

uint8_t EstadoJuego::setAccion(int movimiento, bool disparando) {
    //TODO : Setear bien las acciones en conjunto a las animaciones que espera el cliente.
    if (movimiento == 0 && !disparando) {
        return idle; //IDLE
    } else if (movimiento == 0 && disparando) {
        return shot_1; //DISPARANDO EN EL LUGAR
    } else if (movimiento == 1 && !disparando) {
        return run; // velocidad solo en y
    } else if (movimiento == 1 && disparando) {
        return shot_2; // velocidad solo en y y disparando
    } else if (movimiento == 2 && !disparando) {
        return run; //velocidad solo en x y no disparando
    } else if (movimiento == 2 && disparando) {
        return shot_1; //velocidad solo en x y disparando
    } else if (movimiento == 3 && !disparando) {
        return walk; //velocidad en x e y y no disparando
    } else if (movimiento == 3 && disparando) {
        return shot_1; //velocidad en x e y y disparando
    }
    return idle;
}

uint8_t EstadoJuego::get_id() const {
    return this->id;
}

uint8_t EstadoJuego::get_id_character() const {
    return this->id_character;
}

uint8_t EstadoJuego::get_x() const {
    return this->x;
}

uint8_t EstadoJuego::get_y() const {
    return this->y;
}

uint8_t EstadoJuego::get_ABM() const {
    return this->ABM;
}

uint8_t EstadoJuego::get_accion() const {
    return this->accion;
}

uint8_t EstadoJuego::get_vida() const {
    return this->vida;
}

uint8_t EstadoJuego::get_game_over() const {
    return this->game_over;
}

