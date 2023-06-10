#ifndef LEFT4DEAD_LISTA_PARTIDAS_H
#define LEFT4DEAD_LISTA_PARTIDAS_H

#include <map>
#include <unordered_map>
#include "partida.h"

class ListaPartidas {
private:
    std::mutex m;
    std::unordered_map<int, Partida*> partidas;
public:
    ListaPartidas() {}
    void agregarPartida(Partida* partida);
    void eliminarPartida(int id);
    Partida* obtenerPartida(int id);

    Partida *getPartida(uint32_t codigoPartida);
};

#endif // LEFT4DEAD_LISTA_PARTIDAS_H
