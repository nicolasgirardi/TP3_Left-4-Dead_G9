#ifndef SERVER_RECIEVER_H
#define SERVER_RECIEVER_H

#include "./../common_libs/common_thread.h"
#include "./../common_libs/common_queue.h"
#include "./../common_libs/common_socket.h"

#include "./../server_modelo/eventos/evento.h"
#include "./../server_modelo/eventos/creador_eventos.h"
#include "../common_libs/protocol.h"

class Reciever : public Thread {
 private:
    bool running;
    bool keep_running;
    Queue<Evento*>* queue;
    Protocol& protocol;
    // Protocolo para recibir

 public:
    Reciever& operator=(Reciever&) = delete;
    explicit Reciever(Protocol& socket, Queue<Evento*>* queue);
    bool is_running();
    void run() override;
    void stop();
    virtual ~Reciever();
};

#endif  // SERVER_RECIEVER_H
