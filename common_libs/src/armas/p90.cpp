#include <iostream>
#include "../../include/armas/p90.h"

P90::P90() {
    this->tipo_arma = 2;
    this->municion_maxima = 50;
    this->municion_actual = 50;
    this->velocidad_disparo = 1;
}

P90::~P90() {
    std::cout << "Se elimina P90" << std::endl;
}
