#include "zombie.h"

#include <cmath>

Zombie::Zombie(int x, int y) : x(x), y(y) {}

int Zombie::get_x() {
    return x;
}

int Zombie::get_y() {
    return y;
}

int Zombie::get_vida() {
    return vida;
}

int Zombie::get_velocidad() {
    return velocidad;
}

int Zombie::get_danio() {
    return danio;
}

Zombie::~Zombie() {}

void Zombie::mover(std::list<Personaje*> personajes) {
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

bool Zombie::esta_vivo() {
    return vida > 0;
}

void Zombie::recibir_danio(int danio) {
    vida -= danio;
}

bool Zombie::choco_con_personaje(Personaje* personaje) {
    std::vector<int> posicion_personaje = personaje->mover(0, 0);
    int distancia = sqrt(pow(posicion_personaje[0] - x, 2) +
                         pow(posicion_personaje[1] - y, 2));
    return distancia <= 1;
}

std::string Zombie::serializar() {
    std::string serializacion = "Z " + std::to_string(x) + " " +
                                std::to_string(y) + " "  ;
    return serializacion;
}