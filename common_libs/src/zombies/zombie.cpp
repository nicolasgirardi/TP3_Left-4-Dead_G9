#include "../../include/zombies/zombie.h"

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

int Zombie::get_tipo_zombie() {
    return tipo_zombie;
}

Zombie::~Zombie() {}

void Zombie::mover(std::list<Personaje>& personajes) {
    // Busco el personaje mas cercano
    Personaje* personaje_mas_cercano = nullptr;
    int distancia_personaje_mas_cercano = 0;
    for (auto it = personajes.begin(); it != personajes.end(); ++it) {
        //Personaje& personaje = it.operator*();
        std::vector<int> posicion_personaje = it->get_posicion();
        int distancia = sqrt(pow(posicion_personaje[0] - x, 2) +
                             pow(posicion_personaje[1] - y, 2));
        if (personaje_mas_cercano == nullptr ||
            distancia < distancia_personaje_mas_cercano) {
            personaje_mas_cercano = it.operator->();
            distancia_personaje_mas_cercano = distancia;
        }
    }
    // Si no hay personajes, no hago nada
    if (personaje_mas_cercano == nullptr) {
        return;
    }
    // Como ya tengo el personaje mas cercano, me muevo hacia el
    // Si el personaje mas cercano esta a mas de 200 pixeles, no me muevo
    std::vector<int> posicion_personaje = personaje_mas_cercano->get_posicion();
    int distancia = sqrt(pow(posicion_personaje[0] - x, 2) +
                         pow(posicion_personaje[1] - y, 2));
    if (distancia > 200) {
        return;
    }
    // Si el personaje mas cercano esta a menos de 50 pixeles, me muevo en sentido contrario
    if (distancia < 50) {
        x = x - (posicion_personaje[0] - x);
        y = y - (posicion_personaje[1] - y);
    }
}

bool Zombie::esta_vivo() {
    return vida > 0;
}

void Zombie::recibir_danio(int danio) {
    vida -= danio;
}

bool Zombie::choco_con_personaje(Personaje& personaje) {
    std::vector<int> posicion_personaje = personaje.get_posicion();
    int distancia = sqrt(pow(posicion_personaje[0] - x, 2) +
                         pow(posicion_personaje[1] - y, 2));
    return distancia <= 1;
}

std::string Zombie::serializar() {
    std::string serializacion = "Z " + std::to_string(x) + " " +
                                std::to_string(y) + " "  ;
    return serializacion;
}