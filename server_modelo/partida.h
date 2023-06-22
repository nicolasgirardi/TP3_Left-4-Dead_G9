#ifndef LEFT4DEAD_PARTIDA_H
#define LEFT4DEAD_PARTIDA_H

#include <string>
#include <list>
#include <unordered_map>
#include <map>
#include "personaje.h"
#include "eventos/evento.h"
#include "../common_libs/common_queue.h"
//#include "juego.h"

#define MAX_CLIENTES 3

class Partida {
private:
    std::map<int, Queue<std::string>*> clientes;
    int id;
    int modo;
    std::string nombre;
    int maxClientes = MAX_CLIENTES;
    std::list<Personaje*> personajes;
    std::mutex m;

public:
    Partida(int id, std::string nombre);
    void addClient(Queue<std::string>* queue, int id);
    bool addPersonaje(int id, int arma);
    void removeClient(int id);
    bool isFull();
    void start();
    std::string getEstado();
    int getId();
    ~Partida();
};


#endif //LEFT4DEAD_PARTIDA_H
