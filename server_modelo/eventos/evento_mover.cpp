#include "evento_mover.h"

EventoMover::EventoMover(int id_personaje, int x, int y) {
    this->id_personaje = id_personaje;
    this->x = x;
    this->y = y;
}

EventoMover::~EventoMover() {}

void EventoMover::ejecutar(Partida* partida) {
    Personaje* personaje = partida->get_personaje(this->id_personaje);
    personaje->modificar_velocidad(this->x, this->y);
}