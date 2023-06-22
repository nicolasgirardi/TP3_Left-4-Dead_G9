#ifndef SERVER_CLIENTE_HANDLER_H
#define SERVER_CLIENTE_HANDLER_H


#include <atomic>
#include "../common_libs/common_thread.h"
#include "../common_libs/common_socket.h"
#include "../common_libs/common_queue.h"
#include "../server_modelo/partida.h"
#include "server_reciever.h"
#include "../server_modelo/lista_partida.h"
#include "../common_libs/protocol.h"

#include "./../common_libs/common_thread.h"
#include "./../common_libs/common_queue.h"
#include "./../common_libs/common_socket.h"

#include "./../server_modelo/partida.h"
#include "./../server_modelo/eventos/evento.h"
#include "./../server_modelo/eventos/creador_eventos.h"
#include "./server_reciever.h"
#include "./server_protocolo.h"

#define PARTIDA_INVALIDA 0xFFFFFFFF
#define CREAR "crear"
#define JOIN "join"

class ClienteHandler : public Thread {
private:
    bool running;
    bool keep_running;
    int id;
    Socket socket;
    Protocolo protocolo;

    ListaPartidas* partidas;
    Partida* partida;
    Reciever reciever;
    Queue<std::string> mensajes;
    Queue<Evento*> eventos;


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
    uint32_t joinPartida(uint32_t codigoPartida);
};

#endif // SERVER_CLIENTE_HANDLER_H
