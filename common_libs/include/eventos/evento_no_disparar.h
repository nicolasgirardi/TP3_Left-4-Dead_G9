#ifndef EVENTO_NO_DISPARAR_H_
#define EVENTO_NO_DISPARAR_H_

#include "evento.h"

class EventoNoDisparar : public Evento {
 public:
  explicit EventoNoDisparar(int id_personaje);
  ~EventoNoDisparar() override;
  void ejecutar(Personaje* personaje) override;
};

#endif // EVENTO_NO_DISPARAR_H_