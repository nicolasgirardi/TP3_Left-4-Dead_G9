// Se encarga de la comunicacion con el cliente.
// Recibe los create y los join.

// En un principio es el encargado de recibir los create/join y devolver los mensajes correspondientes
// Cuando arranca el juego se convierte en el reciever

#ifndef SERVER_CLIENTE_HANDLER_H
#define SERVER_CLIENTE_HANDLER_H

#include "./../common_libs/common_thread.h"
#include "./../common_libs/common_queue.h"
#include "./../common_libs/common_socket.h"

#include "./../server_modelo/partida.h"
#include "./server_reciever.h"

class ClienteHandler : public Thread {
 private:
    bool running;
    bool keep_running;
    Socket socket;
    ListaPartidas* partidas;
    Partida* partida;
    Reciever reciever;
    // Queue<GameStatus> queue;

 public:
    ClienteHandler(Socket socket, ListaPartidas* partidas);
    // get puntero a la queue
    bool is_running();
    void start();
    void run() override;
    void stop();
    void create_reciever(Queue<Evento*>* queue);
};

#endif