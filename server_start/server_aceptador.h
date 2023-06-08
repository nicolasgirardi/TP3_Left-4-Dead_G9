// El main levanta este thread que levanta el socket y espera a que se conecte un cliente.
// Guarda en la lista del protocolo el socket del cliente.

#ifndef SERVER_ACEPTADOR_H
#define SERVER_ACEPTADOR_H

#include <string.h>
#include <list>

#include "./../common_libs/common_thread.h"
#include "./../common_libs/common_socket.h"
#include "./../server_modelo/partida.h"
#include "./server_cliente_handler.h"
#include "./../server_modelo/generador_id.h"

class Aceptador : public Thread {
 private:
    Socket socket;
    bool running;
    bool keep_running;
    ListaPartidas* partidas;
    std::list<ClienteHandler*> clientes;

 public:
    explicit Aceptador(const char* port);
    void run() override;
    void stop();
};

#endif  // SERVER_ACEPTADOR_H
