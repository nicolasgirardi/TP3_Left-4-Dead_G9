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
#include "../common_libs/protocol.h"
#include "../common_libs/inicio_partida.h"
#include "../server_modelo/lista_partidas.h"

class ClienteHandler : public Thread {
 private:
    bool running;
    bool keep_running;
    int id;
    //Socket socket;
    Protocol protocol;
    ListaPartidas* partidas;
    Partida* partida;
    //Reciever reciever;
    //Queue<std::string> mensajes = Queue<std::string>(10);

 public:
    ClienteHandler(Socket socket, ListaPartidas* partidas, int id);
    ~ClienteHandler();
    Queue<std::string>* get_mensajes();
    bool is_running();
    void start();
    void run() override;
    void stop();
    void create_reciever(Queue<Evento*>* queue);
    uint32_t iniciar_partida();

    uint32_t crearPartida(std::string nombrePartida);

    void joinPartida(uint32_t codigoPartida);
};

#endif