#include "evento_disparar.h"

EventoDisparar::EventoDisparar(int id_personaje) {
    this->id_personaje = id_personaje;
}

EventoDisparar::~EventoDisparar() {}

void EventoDisparar::ejecutar(Partida* partida) {
    Personaje* personaje = partida->get_personaje(this->id_personaje);
    personaje->iniciar_disparo();
}