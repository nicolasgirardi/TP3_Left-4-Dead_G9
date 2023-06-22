#ifndef EVENTO_NO_MOVER_H_
#define EVENTO_NO_MOVER_H_

#include "evento.h"

class EventoNoMover : public Evento {
 public:
  explicit EventoNoMover(int id_personaje);
  ~EventoNoMover() override;
  void ejecutar(Personaje* personaje) override;
};

#endif // EVENTO_NO_MOVER_H_