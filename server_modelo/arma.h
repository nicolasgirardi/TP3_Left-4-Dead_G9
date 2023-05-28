#ifndef ARMA_H_
#define ARMA_H_

// las armas tienen un tipo de arma, una cantidad de municiones y una velocidad de disparo
// el tipo de arma es un entero que representa el tipo de arma
// 0: IDF
// 1: P90
// 2: Scout

class Arma {
 private:
  int tipo_arma;
  int municiones;
  int municion_actual;
  int velocidad_disparo;

 public:
  virtual void crear(int tipo_arma);
  int get_tipo_arma();
  int get_municiones();
  int get_velocidad_disparo();
  int disparar();
  void recargar();
};
#endif  // ARMA_H_