#ifndef PARTIDA_H
#define PARTIDA_H

#include <string>
#include <atomic>
#include "../../common_libs/include/common_queue.h"
#include "../../common_libs/include/common_socket.h"
#include "../../common_libs/include/eventos/evento.h"
#include "../../common_libs/include/common_personaje.h"
#include "../../common_libs/include/common_estado_juego.h"
#include "./juego.h"
#include "./generador_id.h"

#define MAX_CLIENTES 2

class Partida {
 private:
    std::map<int, Queue<EstadoJuego>&> clientes;
    int id;
    int modo;
    std::string nombre;
    int maxClientes = MAX_CLIENTES;
    std::list<Personaje> personajes;
    std::atomic<bool> isRunning;
    Queue<Evento*>* queueJuego;
    std::mutex m;

 public:
    Partida(int id, std::string nombre);
    void addClient(Queue<EstadoJuego>& mensajes, int id, Personaje personaje);
    bool addPersonaje(int id, int arma);
    void removeClient(int id);
    bool isFull();
    std::map<int, Queue<EstadoJuego> &> & getClientes();
    std::list<Personaje>& getPersonajes();
    std::string getEstado();
    int getId();
    int getModo();
    std::atomic<bool> &getRunning();
    Queue<Evento*>* getQueueJuego();

    Partida(Partida&& other);
    ~Partida();
};

#endif // PARTIDA_H
