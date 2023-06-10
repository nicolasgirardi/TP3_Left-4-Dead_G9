#include "evento_no_disparar.h"

EventoNoDisparar::EventoNoDisparar(int id_personaje) {
    this->id_personaje = id_personaje;
}

EventoNoDisparar::~EventoNoDisparar() {}

void EventoNoDisparar::ejecutar(Personaje* personaje) {
    personaje->finalizar_disparo();
}
