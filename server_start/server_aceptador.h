// El main levanta este thread que levanta el socket y espera a que se conecte un cliente.
// Guarda en la lista del protocolo el socket del cliente.

#ifndef SERVER_ACEPTADOR_H
#define SERVER_ACEPTADOR_H

#include <string.h>
#include <list>
#include <utility>

#include "./common_thread.h"
#include "./common_socket.h"

class Aceptador : public Thread {
 private:
    Socket socket;
    bool running;
    bool keep_running;

 public:
    explicit Aceptador(const char* port);
    void run() override;
    void stop();
};

#endif  // SERVER_ACEPTADOR_H
