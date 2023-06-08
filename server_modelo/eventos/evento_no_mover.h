#ifndef EVENTO_NO_MOVER_H_
#define EVENTO_NO_MOVER_H_

#include "evento.h"

class EventoNoMover : public Evento {
 public:
  EventoNoMover(int id_personaje);
  ~EventoNoMover();
  void ejecutar(Partida* partida);
};

#endif // EVENTO_NO_MOVER_H_