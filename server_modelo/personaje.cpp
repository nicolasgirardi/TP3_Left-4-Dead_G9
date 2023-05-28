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

int Personaje::disparar() {
  return this->arma->disparar();
}