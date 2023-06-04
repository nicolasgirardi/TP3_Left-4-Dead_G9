#include "arma.h"

Arma::Arma() {}

Arma::~Arma() {}

int Arma::iniciar_disparo() {
  this->disparando = true;
  return 0;
}

int Arma::finalizar_disparo() {
  this->disparando = false;
  return 0;
}

void Arma::disparar() {
  if (this->disparando) {
    this->municion_actual--;
  }
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
