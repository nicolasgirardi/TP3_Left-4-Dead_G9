#ifndef JUEGO_H_
#define JUEGO_H_

#include <list>

#include "./../common_libs/common_thread.h"
// El cliente va a tener una queue para recibir y una para mandar
#include "./../common_libs/common_queue.h"
#include "./eventos/evento.h"
#include "./eventos/creador_eventos.h"
#include "./partida.h"
#include "./personaje.h"

#define MAX_EVENTOS 100
#define MAX_X 1000
#define MAX_Y 200

// La partida va a levantar a un juego
class Juego : public Thread {
 private:
    bool running;
    bool keep_running;
    Queue<Evento*>* ejecutar;
    std::unordered_map<int, Queue<Evento*>*>* clientes;
    std::list<Personaje*> personajes;
    Partida* partida;

 public:
    Juego();
    ~Juego();
    Queue<Evento*>* getQueue();
    Personaje* getPersonaje(int id);
    void launch(Partida* partida, std::unordered_map<int, Queue<Evento*>*>* clientes, std::list<Personaje*> personajes);
    void run() override;
    void stop();
};

#endif  // JUEGO_H_