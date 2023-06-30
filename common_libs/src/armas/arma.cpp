#include <iostream>
#include "../../include/armas/arma.h"

Arma::Arma() {}

int Arma::iniciar_disparo() {
  this->disparando = true;
  return 0;
}

int Arma::finalizar_disparo() {
  this->disparando = false;
  return 0;
}

int Arma::disparar() {
  // Simulo el paso del tiempo asi disparo velocidad_disparo veces por segundo
  if (this->disparando) {
    if (this->tiempo_disparo == 0) {
      this->tiempo_disparo = this->velocidad_disparo;
      this->municion_actual--;
      return 1;
    } else {
      this->tiempo_disparo--;
      return 0;
    }
  } else {
    this->tiempo_disparo = 0;
    return 0;
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

int Arma::get_danio() {
  return this->danio;
}

int Arma::get_velocidad_disparo() {
  return this->velocidad_disparo;
}

std::string Arma::get_estado() {
  std::string estado = "";
  estado += std::to_string(this->tipo_arma) + " ";
  estado += std::to_string(this->municion_actual) + " ";
  estado += std::to_string(this->velocidad_disparo) + " ";
  estado += std::to_string(this->disparando) + " ";
  return estado;
}

Arma::Arma(Arma &&other) noexcept {
    this->danio = other.danio;
    this->tipo_arma = other.tipo_arma;
    this->municion_maxima = other.municion_maxima;
    this->municion_actual = other.municion_actual;
    this->velocidad_disparo = other.velocidad_disparo;
    this->disparando = other.disparando;
    this->tiempo_disparo = other.tiempo_disparo;
}

Arma &Arma::operator=(Arma &&other) {
    this->danio = other.danio;
    this->tipo_arma = other.tipo_arma;
    this->municion_maxima = other.municion_maxima;
    this->municion_actual = other.municion_actual;
    this->velocidad_disparo = other.velocidad_disparo;
    this->disparando = other.disparando;
    this->tiempo_disparo = other.tiempo_disparo;
    return *this;
}

Arma::~Arma() {
    std::cout << "Se elimina arma principal" << std::endl;
}
