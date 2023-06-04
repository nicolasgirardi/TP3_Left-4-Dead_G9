// El main levanta este thread que levanta el socket y espera a que se conecte un cliente.
// Guarda en la lista del protocolo el socket del cliente.

#ifndef SERVER_ACEPTADOR_H
#define SERVER_ACEPTADOR_H

#include <string.h>
#include <list>
#include <utility>

#include "./../common_libs/common_thread.h"
#include "./../common_libs/common_socket.h"
#include "./../server_modelo/partida.h"

class Aceptador : public Thread {
 private:
    Socket socket;
    bool running;
    bool keep_running;
    ListaPartidas* partidas;

 public:
    explicit Aceptador(const char* port);
    void run() override;
    void stop();
};

#endif  // SERVER_ACEPTADOR_H
