#ifndef EVENTO_DISPARAR_H_
#define EVENTO_DISPARAR_H_

#include "evento.h"

class EventoDisparar : public Evento {
 private:

 public:
  EventoDisparar(int id_personaje);
  ~EventoDisparar();
  void ejecutar(Personaje* personaje);
};

#endif // EVENTO_DISPARAR_H_