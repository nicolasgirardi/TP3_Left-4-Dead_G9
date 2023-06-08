#ifndef EVENTO_H_
#define EVENTO_H_

// Me incluyo las partidas asi puedo ejecutar los eventos
#include "../partida.h"

class Evento {
    // Esta clase va a ser va a temer de hijo a todos los eventos
    // que se puedan dar en el juego
    // Por ejemplo: mover, disparar, dejar de mover, dejar de disparar
    // 0 = mover
    // 1 = disparar
    // 2 = dejar de mover
    // 3 = dejar de disparar

 protected:
  int id_personaje;

 public:
  virtual ~Evento();
  void ejecutar(Partida* partida);
};

#endif  // EVENTO_H_