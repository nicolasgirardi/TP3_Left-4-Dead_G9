// Se llama al servidor haciendo ./server 8082

#include <iostream>

#include "../include/server_aceptador.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Error: argumentos invalidos" << std::endl;
        return 1;
    }
    // Me creo el thread de aceptador
    Aceptador aceptador(argv[1]);
    aceptador.start();
    char c = 'a';
    while (c != 'q') {
        // Si me ingresan una q, termino el programa
        std::cin >> c;
    }
    aceptador.stop();
    aceptador.join();
}
