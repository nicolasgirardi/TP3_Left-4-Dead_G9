#ifndef EVENTO_NO_DISPARAR_H_
#define EVENTO_NO_DISPARAR_H_

#include "evento.h"

class EventoNoDisparar : public Evento {
 public:
  EventoNoDisparar(int id_personaje);
  ~EventoNoDisparar();
  void ejecutar(Partida* partida);
};

#endif // EVENTO_NO_DISPARAR_H_