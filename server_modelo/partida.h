#ifndef PARTIDA_H_
#define PARTIDA_H_


#include <map>
#include <string>
#include <unordered_map>

#include "./../common_libs/common_queue.h"
#include "./../common_libs/common_socket.h"

#include "./eventos/evento.h"
#include "./personaje.h"
#include "./juego.h"
#include "./personaje.h"
#include "./generador_id.h"

#define MAX_CLIENTES 3

class Partida {
 private:
    int id;
    int modo;
    std::string nombre;
    std::unordered_map<int, Queue<Evento*>*> clientesSender;
    Queue<Evento*> eventos;
    int clientesPermitidos = MAX_CLIENTES;
    std::list<Personaje*> personajes;
    std::mutex mutex;

 public:
    Partida(std::string nombre, int modo);
    void addClient(int id, Queue<Evento*>* queueSender);
    bool addPersonaje(int id, int arma);
    void removeClient(int id);
    bool isFull();
    void start();
    std::string getEstado();
    uint32_t getCodigoPartida();
    Queue<Evento*>* getEventos();
    std::string getNombre();
    int getId();
    ~Partida();
};

#endif // PARTIDA_H_