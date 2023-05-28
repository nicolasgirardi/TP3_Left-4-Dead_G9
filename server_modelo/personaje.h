#ifndef PERSONAJE_H_
#define PERSONAJE_H_

// los personajes son los jugadores, tienen posicion en x e y, un id y un arma

#include "arma.h"
#include "creador_armas.h"

#include <vector>

class Personaje {
 private:
  int id;
  int x;
  int y;
  int velocidad_x;
  int velocidad_y;
  Arma* arma;

 public:
  Personaje(int id, int arma);
  ~Personaje();
  int get_id();
  int modificar_velocidad(int x, int y);
  std::vector<int> mover(int largo, int ancho);
  int disparar();
};

#endif  // PERSONAJE_H_