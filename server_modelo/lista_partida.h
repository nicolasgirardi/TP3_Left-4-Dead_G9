#ifndef LEFT4DEAD_LISTA_PARTIDA_H
#define LEFT4DEAD_LISTA_PARTIDA_H

#include <unordered_map>
#include "partida.h"

class ListaPartidas {
private:
    std::mutex m;
    std::unordered_map<uint32_t, Partida*> partidas;
    int id = 0;

public:
    ListaPartidas();
    Partida* crearPartida(std::string nombre, int modo);
    void addPartida(Partida* partida);
    Partida* getPartida(uint32_t codigoPartida);
    void printCodigoPartida();
    ~ListaPartidas();
};


#endif // LEFT4DEAD_LISTA_PARTIDA_H
