#include "arma.h"

Arma::Arma() {}

Arma::~Arma() {}

int Arma::disparar() {
  if (this->municion_actual > 0) {
    this->municion_actual--;
    return 0;
  }
  return 1;
}

int Arma::recargar() {
  this->municion_actual = this->municion_maxima;
  return this->municion_actual;
}

int Arma::get_tipo_arma() {
  return this->tipo_arma;
}

int Arma::get_municiones() {
  return this->municion_actual;
}

int Arma::get_velocidad_disparo() {
  return this->velocidad_disparo;
}
