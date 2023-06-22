#ifndef LEFT4DEAD_EVENTO_NO_DISPARAR_H_
#define LEFT4DEAD_EVENTO_NO_DISPARAR_H_

#include "evento.h"

class EventoNoDisparar : public Evento {
 public:
  explicit EventoNoDisparar(int id_personaje);
  ~EventoNoDisparar() override;
  void ejecutar(Personaje* personaje) override;
};

#endif // LEFT4DEAD_EVENTO_NO_DISPARAR_H_