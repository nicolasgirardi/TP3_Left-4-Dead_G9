#include "estado_jugador.h"

EstadoJugador::EstadoJugador(Personaje* personaje) {
    this->id_soldado = personaje->get_tipo_arma();
    std::vector<int> posiciones = personaje->mover(0, 0);
    this->x = posiciones[0];
    this->y = posiciones[1];
    this->actualmente_disparando = personaje->get_disparando();
    this->actualmente_moviendo = personaje->get_estado_movimiento();
}

EstadoJugador::~EstadoJugador() {}
