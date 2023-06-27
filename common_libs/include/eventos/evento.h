#ifndef EVENTO_H_
#define EVENTO_H_

// Me incluyo las partidas asi puedo ejecutar los eventos
#include "../common_personaje.h"

class Evento {
    // Esta clase va a ser va a temer de hijo a todos los eventos
    // que se puedan dar en el juego
    // Por ejemplo: mover, disparar, dejar de mover, dejar de disparar
    // 0 = mover
    // 1 = disparar
    // 2 = dejar de mover
    // 3 = dejar de disparar

 protected:
  int id_personaje{};

 public:
  virtual ~Evento();
  virtual void ejecutar(Personaje* personaje);
  int get_id_personaje();
};

#endif  // EVENTO_H_