#ifndef LEFT4DEAD_EVENTO_NO_MOVER_H_
#define LEFT4DEAD_EVENTO_NO_MOVER_H_

#include "evento.h"

class EventoNoMover : public Evento {
 public:
  explicit EventoNoMover(int id_personaje);
  ~EventoNoMover() override;
  void ejecutar(Personaje* personaje) override;
};

#endif // LEFT4DEAD_EVENTO_NO_MOVER_H_