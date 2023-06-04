#ifndef SERVER_SENDER_H
#define SERVER_SENDER_H

#include "./../common_libs/common_thread.h"
#include "./../common_libs/common_queue.h"

#include "./../server_modelo/eventos/evento.h"
#include "./../server_modelo/eventos/creador_eventos.h"

class Sender : public Thread {
 private:
    bool running;
    bool keep_running;
    // Protocolo para recibir
    Partida* partida;

 public:
    explicit Sender(Partida* partida);
    void run() override;
    void stop();
};

#endif  // SERVER_SENDER_H
