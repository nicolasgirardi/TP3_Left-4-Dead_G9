#ifndef PERSONAJE_H_
#define PERSONAJE_H_

// los personajes son los jugadores, tienen posicion en x e y, un id y un arma

#include "./armas/arma.h"
#include "./armas/creador_armas.h"

#include <vector>

class Personaje {
 private:
  int id;
  int x, y;
  int velocidad_x;
  int velocidad_y;
  bool disparando = false;
  int vidas = 3;
  Arma* arma;

 public:
  Personaje(int id, int arma);
  ~Personaje();
  int get_id();
  int modificar_velocidad(int x, int y);
  std::vector<int> mover(int largo, int ancho);
  int recargar();
  int iniciar_disparo();
  int finalizar_disparo();
};

#endif  // PERSONAJE_H_