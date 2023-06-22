#include "evento_mover.h"

EventoMover::EventoMover(int id_personaje, int x, int y) {
    this->id_personaje = id_personaje;
    this->x = x;
    this->y = y;
}

EventoMover::~EventoMover() = default;

void EventoMover::ejecutar(Personaje* personaje) {
    personaje->modificar_velocidad(x, y);
}