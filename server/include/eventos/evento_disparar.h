#ifndef EVENTO_DISPARAR_H_
#define EVENTO_DISPARAR_H_

#include "evento.h"

class EventoDisparar : public Evento {
 private:

 public:
  explicit EventoDisparar(int id_personaje);
  ~EventoDisparar() override;
  void ejecutar(Personaje* personaje) override;
};

#endif // EVENTO_DISPARAR_H_