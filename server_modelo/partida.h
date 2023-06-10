#ifndef PARTIDA_H_
#define PARTIDA_H_

// Me traigo un map para poder guardarme las queues de los clientes y su id

#include <map>
#include <string>

#include "./../common_libs/common_queue.h"
#include "./../common_libs/common_socket.h"

#include "./eventos/evento.h"
#include "./personaje.h"
#include "./juego.h"
#include "./personaje.h"

#define MAX_CLIENTES 3

/*
class Match  {
    Queue<?> gameQueue;
    // esto o un reference_wrapper para poder ir holdeando las referencias std::vector<Queue<?>*> clientQueues;
    Game game;

    Queue<?>& addPlayer(Queue<?>& clientQueue) {
        clientQueues.push_back(&clientQueue);
        maybeStart();
        return ...
    }

    void maybeStart() {
        if (...)
            game.launch(gameQueue, clientQueues);
    }
};
*/

class Partida {
 private:
    std::map<int, Queue<Evento*>*> clientes;
    int id;
    std::string nombre;
    int maxClientes = MAX_CLIENTES;
    std::list<Personaje*> personajes;

 public:
    Partida(int id, std::string nombre);
    void addClient(Queue<Evento*>* queue, int id);
    bool addPersonaje(int id, int arma);
    void removeClient(int id);
    bool isFull();
    void start();
    std::string getEstado();
    int getId();
    ~Partida();
};

class ListaPartidas {
    private:
        std::mutex m;
        std::map<int, Partida*> partidas;
        int id = 0;
    
    public:
        ListaPartidas();
        Partida* addPartida(std::string nombre);
        void addClient(Queue<Evento*>* queue, int id);
        void removeClient(int id);
        bool addPersonaje(int id, int arma);
        ~ListaPartidas();
};

#endif // PARTIDA_H_