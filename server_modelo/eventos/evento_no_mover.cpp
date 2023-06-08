#include "evento_no_mover.h"
#include "../partida.h"

EventoNoMover::EventoNoMover(int id_personaje) {
    this->id_personaje = id_personaje;
}

EventoNoMover::~EventoNoMover() {}

void EventoNoMover::ejecutar(Partida* partida) {
    Personaje* personaje = partida->get_personaje(this->id_personaje);
    personaje->modificar_velocidad(0, 0);
}
