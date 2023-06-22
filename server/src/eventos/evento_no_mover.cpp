#include "../../include/eventos/evento_no_mover.h"
#include "../../include/partida.h"

EventoNoMover::EventoNoMover(int id_personaje) {
    this->id_personaje = id_personaje;
}

EventoNoMover::~EventoNoMover() = default;

void EventoNoMover::ejecutar(Personaje* personaje) {
    personaje->modificar_velocidad(0, 0);
}
