#include "witch.h"

#include <cmath>

Witch::Witch(int max_x, int max_y) : max_x(max_x), max_y(max_y) {
    x = rand() % max_x;
    y = rand() % max_y;
}

int Witch::get_x() {
    return x;
}

int Witch::get_y() {
    return y;
}

int Witch::get_vida() {
    return vida;
}

Witch::~Witch() {}

bool Witch::esta_vivo() {
    return vida > 0;
}

void Witch::recibir_danio(int danio) {
    vida -= danio;
}

std::string Witch::serializar() {
    return "W " + std::to_string(x) + " " + std::to_string(y) + " ";
}
