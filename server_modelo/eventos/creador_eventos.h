#ifndef CREAR_EVENTOS_H_
#define CREAR_EVENTOS_H_

#include "evento.h"
#include "evento_disparar.h"
#include "evento_no_disparar.h"
#include "evento_mover.h"
#include "evento_no_mover.h"

class CreadorEventos {
 public:
  static Evento* crearEvento(int id, int id_personaje);
  static Evento* crearEvento(int id, int id_personaje, int x, int y);
};

#endif // CREAR_EVENTOS_H_