#ifndef PARTIDA_H_
#define PARTIDA_H_

// Me traigo un map para poder guardarme las queues de los clientes y su id

#include <map>
#include <unordered_map>

#include "./../common_libs/common_queue.h"
#include "./../common_libs/common_socket.h"

#include "./eventos/evento.h"
#include "./personaje.h"

#define MAX_CLIENTES 4

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
    std::unordered_map<int, Personaje*> personajes;
    
 public:
    Partida(int id);
    void addClient(int id, Queue<Evento*>* queue);
    void removeClient(int id);
    Personaje* getPersonaje(int id);
    void addPersonaje(int id, Personaje* personaje);
    ~Partida();
};

class ListaPartidas {

};

#endif // PARTIDA_H_