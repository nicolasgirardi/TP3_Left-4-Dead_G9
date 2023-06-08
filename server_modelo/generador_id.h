#ifndef GENERADOR_ID_H
#define GENERADOR_ID_H

#include <iostream>
#include <cstdlib>
#include <ctime>

class GeneradorID {
 private:

 public:
    static int get_id() {
        int id = 0;
        srand(time(0)); // Semilla para generar números aleatorios basados en la hora actual

        for (int i = 0; i < 6; ++i) {
            // Genera un dígito aleatorio entre 0 y 9 y lo agrega al ID
            int digito = rand() % 10;
            id = id * 10 + digito;
        }
    }
};

#endif  // GENERADOR_ID_H