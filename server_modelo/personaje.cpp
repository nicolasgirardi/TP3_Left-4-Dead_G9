#include "./personaje.h"

Personaje::Personaje(int id, int arma): id(id) {
  this->x = 0;
  this->y = 0;
  this->velocidad_x = 0;
  this->velocidad_y = 0;
  this->arma = CreadorArmas::crear_arma(arma);
}

Personaje::~Personaje() {
  delete this->arma;
}

int Personaje::get_id() {
  return this->id;
}

int Personaje::modificar_velocidad(int x, int y) {
  this->velocidad_x = x;
  this->velocidad_y = y;
  if (x > 0) {
    this->direccion_x = 1;
  } else if (x < 0) {
    this->direccion_x = -1;
  }
  return 0;
}

std::vector<int> Personaje::mover(int largo, int ancho) {
  int x = this->x + this->velocidad_x;
  int y = this->y + this->velocidad_y;
  if (x > 0 && x < largo) {
    this->x = x;
  } else {
    this->velocidad_x = 0;
  }
  if (y > 0 && y < ancho) {
    this->y = y;
  } else {
    this->velocidad_y = 0;
  }
  std::vector<int> pos = {this->x, this->y};
  return pos;
}

int Personaje::recargar() {
  return this->arma->recargar();
}

int Personaje::iniciar_disparo() {
  this->disparando = true;
  return 0;
}

int Personaje::finalizar_disparo() {
  this->disparando = false;
  return 0;
}

std::string Personaje::get_estado() {
  std::string estado = "";
  estado += std::to_string(this->id) + " ";
  estado += std::to_string(this->x) + " ";
  estado += std::to_string(this->y) + " ";
  estado += std::to_string(this->velocidad_x) + " ";
  estado += std::to_string(this->velocidad_y) + " ";
  estado += std::to_string(this->disparando) + " ";
  estado += std::to_string(this->vidas) + " ";
  estado += this->arma->get_estado();
  return estado;
}