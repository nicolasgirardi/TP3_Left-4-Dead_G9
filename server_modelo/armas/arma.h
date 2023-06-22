#ifndef LEFT4DEAD_ARMA_H
#define LEFT4DEAD_ARMA_H

// las armas tienen un tipo de arma, una cantidad de municiones y una velocidad de disparo
// el tipo de arma es un entero que representa el tipo de arma
// 0: IDF
// 1: P90
// 2: Scout

#include <string>

class Arma {
 protected:
  int danio = 10;
  int tipo_arma;
  int municion_maxima;
  int municion_actual;
  int velocidad_disparo;
  bool disparando;
  int tiempo_disparo = 0;

 public:
  Arma();
  virtual ~Arma();
  int get_tipo_arma();
  int get_danio();
  int get_municiones();
  int get_velocidad_disparo();
  int iniciar_disparo();
  int finalizar_disparo();
  int disparar();
  int recargar();
  std::string get_estado();
};


#endif //LEFT4DEAD_ARMA_H
