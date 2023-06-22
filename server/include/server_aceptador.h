#ifndef SERVER_ACEPTADOR_H
#define SERVER_ACEPTADOR_H


#include <string.h>
#include <list>

#include "../../common_libs/include/common_thread.h"
#include "../../common_libs/include/common_socket.h"
#include "./partida.h"
#include "./server_cliente_handler.h"
#include "./generador_id.h"

class Aceptador : public Thread {
private:
    Socket socket;
    bool running;
    bool keep_running;
    ListaPartidas* partidas;
    std::list<ClienteHandler*> clientes;

public:
    explicit Aceptador(const char* port);
    ~Aceptador();
    void run() override;
    void stop();
};


#endif //SERVER_ACEPTADOR_H
