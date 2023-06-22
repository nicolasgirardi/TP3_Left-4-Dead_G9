#ifndef PERSONAJE_H
#define PERSONAJE_H


#include "armas/arma.h"
#include "armas/creador_armas.h"

#include <vector>
#include <string>

class Personaje {
 private:
  int id;
  int x, y;
  int velocidad_x;
  int velocidad_y;
  int direccion_x;
  bool disparando = false;
  int vida = 100;
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
  int recibir_danio(int danio);
  int get_danio();
  int get_vida();
  int get_vidas();
  int get_tipo_arma();
  int get_disparando();
  int get_estado_movimiento();
  std::string get_estado();
};


#endif // PERSONAJE_H
