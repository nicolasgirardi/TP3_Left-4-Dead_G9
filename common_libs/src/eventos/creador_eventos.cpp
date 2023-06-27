#include "../../include/eventos/creador_eventos.h"

Evento* CreadorEventos::crearEvento(int id, int id_personaje) {
  switch (id) {
    case 1:
      return new EventoNoMover(id_personaje);
    case 2:
      return new EventoDisparar(id_personaje);
    case 3:
      return new EventoNoDisparar(id_personaje);
    default:
      return nullptr;
  }
}

Evento* CreadorEventos::crearEvento(int id, int id_personaje, int x, int y) {
  switch (id) {
    case 0:
      return new EventoMover(id_personaje, x, y);
    default:
      return nullptr;
  }
}