#ifndef LEFT4DEAD_EVENTO_DISPARAR_H_
#define LEFT4DEAD_EVENTO_DISPARAR_H_

#include "evento.h"

class EventoDisparar : public Evento {
 private:

 public:
  explicit EventoDisparar(int id_personaje);
  ~EventoDisparar() override;
  void ejecutar(Personaje* personaje) override;
};

#endif // LEFT4DEAD_EVENTO_DISPARAR_H_