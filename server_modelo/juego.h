#ifndef JUEGO_H_
#define JUEGO_H_

// 0 = modo normal
// 1 = modo supervivencia

#include <list>

#include "./../common_libs/common_thread.h"
// El cliente va a tener una queue para recibir y una para mandar
#include "./../common_libs/common_queue.h"
#include "./eventos/evento.h"
#include "./eventos/creador_eventos.h"
#include "./partida.h"
#include "./personaje.h"
#include "./zombies/zombie.h"
#include "./estado_jugador.h"

#define MAX_EVENTOS 100
#define MAX_X 1000
#define MAX_Y 200

// La partida va a levantar a un juego
class Juego : public Thread {
 private:
    bool running;
    bool keep_running;
    int modo;
    int cantidad_zombies = 10;
    Queue<Evento*> ejecutar;
    std::map<int, Queue<std::string>*>* clientes;
    std::list<Personaje*> personajes;
    std::list<Zombie*> zombies;

 public:
    Juego();
    ~Juego();
    Queue<Evento*>* getQueue();
    Personaje* getPersonaje(int id);
    std::list<Personaje*> getPersonajes();
    void launch(std::map<int, Queue<std::string>*>* clientes, std::list<Personaje*> personajes, int modo);
    void run() override;
    void stop();
};

#endif  // JUEGO_H_