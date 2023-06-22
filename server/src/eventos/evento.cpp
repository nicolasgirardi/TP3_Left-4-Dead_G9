#include "../../include/eventos/evento.h"

int Evento::get_id_personaje() {
    return this->id_personaje;
}

void Evento::ejecutar(Personaje *personaje) {

}

Evento::~Evento() = default;
