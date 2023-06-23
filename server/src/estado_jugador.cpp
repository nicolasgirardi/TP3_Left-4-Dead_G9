#include "../include/estado_jugador.h"

EstadoJugador::EstadoJugador(Personaje* personaje) {
    this->id_soldado = personaje->get_tipo_arma();
    std::vector<int> posiciones = personaje->get_posicion();
    this->x = posiciones[0];
    this->y = posiciones[1];
    this->actualmente_disparando = personaje->get_disparando();
    this->actualmente_moviendo = personaje->get_estado_movimiento();
}

EstadoJugador::~EstadoJugador() {}

std::string EstadoJugador::serializar(){
    std::string estado = "";
    estado += this->id_soldado;
    estado += ",";
    estado += this->x;
    estado += ",";
    estado += this->y;
    estado += ",";
    estado += this->actualmente_disparando;
    estado += ",";
    estado += this->actualmente_moviendo;
    return estado;
}
