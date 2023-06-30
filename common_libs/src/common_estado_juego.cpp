#include "../include/common_estado_juego.h"

//Codigo repetido se podria haber solucionado con herencia
//Tener un Character que Personaje y Zombie hereden atributos comunes que son los que se serializan al cliente.
EstadoJuego::EstadoJuego(Personaje &personaje, uint8_t abm) : id(personaje.get_id()) {
    this->game_over = 0x00;
    this->x = personaje.get_posicion()[0];
    this->y = personaje.get_posicion()[1];
    this->id_character = static_cast<uint8_t>(personaje.get_tipo_arma()); // 0: IDF 1: P90, 2: SCOUT
    this->accion = setAccion(personaje.get_estado_movimiento(), personaje.get_disparando());
    this->ABM = abm;
    this->vida = personaje.get_vida();
}

EstadoJuego::EstadoJuego(Zombie *zombie, uint8_t abm) : id(zombie->get_tipo_zombie()){
    this->game_over = 0x00;
    this->x = zombie->get_x();
    this->y = zombie->get_y();
    this->id_character = zombie->get_tipo_zombie();
    this->ABM = abm;
    this->accion = 0x07; // Attack hardcodeado
    this->vida = zombie->get_vida();
}
//TODO: Revisar
EstadoJuego::EstadoJuego(int idCliente, int idPersonaje) : id(idCliente), id_character(idPersonaje) {
    this->game_over = 0x01;
}

uint8_t EstadoJuego::setAccion(int movimiento, bool disparando) {
    if (movimiento == 0 && !disparando) {
        return 0x00; //IDLE
    } else if (movimiento == 0 && disparando) {
        return 0x01; //DISPARANDO EN EL LUGAR
    } else if (movimiento == 1 && !disparando) {
        return 0x02; // velocidad solo en y
    } else if (movimiento == 1 && disparando) {
        return 0x03; // velocidad solo en y y disparando
    } else if (movimiento == 2 && !disparando) {
        return 0x04; //velocidad solo en x y no disparando
    } else if (movimiento == 2 && disparando) {
        return 0x05; //velocidad solo en x y disparando
    } else if (movimiento == 3 && !disparando) {
        return 0x06; //velocidad en x e y y no disparando
    } else if (movimiento == 3 && disparando) {
        return 0x07; //velocidad en x e y y disparando
    }
    return 0x00;
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

