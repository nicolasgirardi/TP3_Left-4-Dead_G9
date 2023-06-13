#include "evento_no_mover.h"

EventoNoMover::EventoNoMover(int id_personaje) {
    this->id_personaje = id_personaje;
}

EventoNoMover::~EventoNoMover() {}

void EventoNoMover::ejecutar(Personaje* personaje) {
    personaje->modificar_velocidad(0, 0);
}
