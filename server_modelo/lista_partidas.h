#ifndef LISTA_PARTIDAS_H
#define LISTA_PARTIDAS_H

#include <map>
#include <unordered_map>
#include "partida.h"

class ListaPartidas {
private:
    std::mutex m;
    std::unordered_map<uint32_t, Partida*> partidas;
    int id = 0;

public:
    ListaPartidas();
    uint32_t crearPartida(std::string nombre);
    void addClient(int id);
    void removeClient(int id);
    bool addPersonaje(int id, int arma);
    ~ListaPartidas();
    Partida *getPartida(uint32_t codigoPartida);
};

#endif // LISTA_PARTIDAS_H
