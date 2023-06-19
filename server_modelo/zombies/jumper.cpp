#include "jumper.h"

#include <cmath>

Jumper::Jumper(int x, int y) : x(x), y(y) {}

int Jumper::get_x() {
    return x;
}

int Jumper::get_y() {
    return y;
}

int Jumper::get_vida() {
    return vida;
}

int Jumper::get_velocidad() {
    return velocidad;
}

Jumper::~Jumper() {}

void Jumper::mover(std::list<Personaje*> personajes) {
    // Busco el personaje mas cercano
    Personaje* personaje_mas_cercano = nullptr;
    int distancia_personaje_mas_cercano = 0;
    for (auto it = personajes.begin(); it != personajes.end(); ++it) {
        Personaje* personaje = *it;
        std::vector<int> posicion_personaje = personaje->mover(0, 0);
        int distancia = sqrt(pow(posicion_personaje[0] - x, 2) +
                             pow(posicion_personaje[1] - y, 2));
        if (personaje_mas_cercano == nullptr ||
            distancia < distancia_personaje_mas_cercano) {
            personaje_mas_cercano = personaje;
            distancia_personaje_mas_cercano = distancia;
        }
    }
    // Si no hay personajes, no hago nada
    if (personaje_mas_cercano == nullptr) {
        return;
    }
    // Como ya tengo el personaje mas cercano, me muevo hacia el
    // Si esta a menos de 10 de distancia en, salto
    if (distancia_personaje_mas_cercano < 10) {
        // Salto
        return;
    }
    std::vector<int> posicion_personaje = personaje_mas_cercano->mover(0, 0);
    if (x < posicion_personaje[0]) {
        x += velocidad;
    } else if (x > posicion_personaje[0]) {
        x -= velocidad;
    }
    if (y < posicion_personaje[1]) {
        y += velocidad;
    } else if (y > posicion_personaje[1]) {
        y -= velocidad;
    }
}