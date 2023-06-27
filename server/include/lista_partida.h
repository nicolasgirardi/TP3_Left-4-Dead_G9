#ifndef LISTA_PARTIDA_H
#define LISTA_PARTIDA_H

#include <unordered_map>
#include <map>
#include "partida.h"
#include "generador_id.h"

class ListaPartidas {
private:
    std::mutex m;
    std::map<int, Partida> partidas;

public:
    ListaPartidas();
    int addPartida(std::string nombre, int modo);
    //int addClient(Queue<std::string>* queue, int id, Personaje personaje);
    void removeClient(int id);
    bool addPersonaje(int id, int arma);
    ~ListaPartidas();

    Partida& getPartida(uint32_t codigoPartida);

    std::map<int, Partida>& getPartidas();

    void iniciarPartida(uint32_t codigoPartida);
};


#endif // LISTA_PARTIDA_H
