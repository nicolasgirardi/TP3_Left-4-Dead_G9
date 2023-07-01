#ifndef JUEGO_H
#define JUEGO_H


#include <map>
#include <list>
#include "../../common_libs/include/common_thread.h"
#include "../../common_libs/include/eventos/evento.h"
#include "../../common_libs/include/common_queue.h"
#include "partida.h"

// 0 = modo normal
// 1 = modo supervivencia

// 0 = modo normal
// 1 = modo supervivencia

#include <list>
#include <atomic>
#include "../../common_libs/include/common_thread.h"
#include "../../common_libs/include/common_queue.h"
#include "../../common_libs/include/eventos/evento.h"
#include "../../common_libs/include/eventos/creador_eventos.h"
#include "./partida.h"
#include "../../common_libs/include/common_personaje.h"
#include "../../common_libs/include/zombies/zombie.h"
#include "../../common_libs/include/zombies/witch.h"
#include "../../common_libs/include/zombies/generador_zombies.h"
#include "./estado_jugador.h"
#include "../../common_libs/include/zombies/estado_zombie.h"
#include "../../common_libs/include/common_estado_juego.h"

#define MAX_EVENTOS 100
#define MAX_X 1000
#define MAX_Y 200

// La partida va a levantar a un juego
class Juego : public Thread {
private:
    bool keep_running;
    std::atomic<bool> kpPartida;
    int modo;
    int cantidad_zombies = 10;
    Queue<Evento*>* ejecutar;
    std::map<int, Queue<EstadoJuego>&>& clientes;
    std::list<Personaje>& personajes;
    std::list<Zombie*> zombies;
    std::list<Witch*> witches;
    std::mutex m;

public:
    //Juego(Partida& partida);
    Juego(std::map<int, Queue<EstadoJuego>&>& clientes, std::list<Personaje>& personajes, int modo,
          Queue<Evento*>* queueJuego);
    ~Juego();
    Queue<Evento*>* getQueue();
    Personaje* getPersonaje(int id);
    std::list<Personaje*> getPersonajes();
    void run() override;
    void stop();
    bool gameRunning();
    void initGame();
};

#endif // JUEGO_H
