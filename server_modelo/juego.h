#ifndef JUEGO_H_
#define JUEGO_H_

#include "./../common_libs/common_thread.h"
// El cliente va a tener una queue para recibir y una para mandar
#include "./../common_libs/common_queue.h"
#include "./eventos/evento.h"
#include "./eventos/creador_eventos.h"
#include "./partida.h"

#define MAX_EVENTOS 100

// La partida va a levantar a un juego
class Juego : public Thread {
 private:
    bool running;
    bool keep_running;
    Queue<Evento*> ejecutar;
    Queue<Queue<Evento>*>* clientes;
    Partida* partida;

 public:
    Juego();
    ~Juego();
    Queue<Evento*>* getQueue();
    void launch(Partida* partida, Queue<Queue<Evento*>*>* clientes);
    void run() override;
    void stop();
};

#endif  // JUEGO_H_