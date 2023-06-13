// Se encarga de la comunicacion con el cliente.
// Recibe los create y los join.

// En un principio es el encargado de recibir los create/join y devolver los mensajes correspondientes
// Cuando arranca el juego se convierte en el reciever

#ifndef SERVER_CLIENTE_HANDLER_H
#define SERVER_CLIENTE_HANDLER_H

#include <atomic>
#include "./../common_libs/common_thread.h"
#include "./../common_libs/common_queue.h"
#include "./../common_libs/common_socket.h"

#include "./../server_modelo/partida.h"
#include "./server_reciever.h"
#include "../common_libs/protocol.h"
#include "../common_libs/inicio_partida.h"
#include "../server_modelo/lista_partidas.h"

class ClienteHandler : public Thread {
 private:
    bool running;
    bool keep_running;
    std::atomic<bool> recieverOn;
    int id;
    Protocol protocol;
    ListaPartidas* partidas;
    //Partida tiene que tener una cola de eventos que pushea al juego.
    Partida* partida;

 public:
    ClienteHandler(Socket socket, ListaPartidas* partidas, int id);
    ~ClienteHandler();
    Queue<std::string>* get_mensajes();
    bool is_running();
    void start();
    void run() override;
    void stop();
    uint32_t iniciar_partida();

    uint32_t crearPartida(std::string nombrePartida);

    void joinPartida(uint32_t codigoPartida);
};

#endif