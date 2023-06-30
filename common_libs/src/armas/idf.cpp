#include <iostream>
#include "../../include/armas/idf.h"

IDF::IDF() {
    this->tipo_arma = 3;
    this->municion_maxima = 10;
    this->municion_actual = 10;
    this->velocidad_disparo = 1;
}

IDF::~IDF() {
    std::cout << "Se elimina IDF" << std::endl;
}
