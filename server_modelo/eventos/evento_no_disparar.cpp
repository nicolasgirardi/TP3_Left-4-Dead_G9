#include "evento_no_disparar.h"

EventoNoDisparar::EventoNoDisparar(int id_personaje) {
    this->id_personaje = id_personaje;
}

EventoNoDisparar::~EventoNoDisparar() {}

void EventoNoDisparar::ejecutar(Partida* partida) {
    Personaje* personaje = partida->get_personaje(this->id_personaje);
    personaje->finalizar_disparo();
}
