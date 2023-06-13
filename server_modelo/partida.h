#ifndef PARTIDA_H_
#define PARTIDA_H_


#include <string>
#include <unordered_map>
#include <map>
#include <list>
#include "./../common_libs/common_queue.h"
#include "./../common_libs/common_socket.h"
#include "./eventos/evento.h"
#include "./personaje.h"
//#include "./juego.h"
#include "./personaje.h"

#define MAX_CLIENTES 3

class Partida {
 private:
    std::unordered_map<int, Queue<Evento*>*> clientesSender; // Hay paserle como referencia al Game ID es el id que recibe el clienthandler
    Queue<Evento*> eventos;
    int id;
    int maxClientes = MAX_CLIENTES;
    std::list<Personaje*> personajes;

 public:
    Partida(uint32_t id);
    void addClient(int idCliente);
    bool addPersonaje(int id, int arma);
    void removeClient(int id);
    bool isFull();
    void start();
    std::string getEstado();
    int getId();
    Queue<Evento*>* getEventos();
    uint32_t getCodigoPartida();
    ~Partida();
};

#endif // PARTIDA_H_