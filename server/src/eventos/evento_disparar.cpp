#include "../../include/eventos/evento_disparar.h"

EventoDisparar::EventoDisparar(int id_personaje) {
    this->id_personaje = id_personaje;
}

EventoDisparar::~EventoDisparar() = default;

void EventoDisparar::ejecutar(Personaje* personaje) {
    personaje->iniciar_disparo();
}