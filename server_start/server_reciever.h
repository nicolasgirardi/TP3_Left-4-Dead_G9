#ifndef SERVER_RECIEVER_H
#define SERVER_RECIEVER_H

#include "./../common_libs/common_thread.h"
#include "./../common_libs/common_queue.h"
#include "./../common_libs/common_socket.h"

#include "./../server_modelo/eventos/evento.h"
#include "./../server_modelo/eventos/creador_eventos.h"

#include "server_protocolo.h"

class Reciever : public Thread {
 private:
    bool running;
    bool keep_running;
    Queue<Evento*>* queue;
    Protocolo* protocolo;

 public:
    Reciever& operator=(Reciever&);
    explicit Reciever(Protocolo* protocolo, Queue<Evento*>* queue);
    Reciever();
    ~Reciever();
    bool is_running();
    void run() override;
    void stop();
    int operator=(const Reciever&);
};

#endif  // SERVER_RECIEVER_H
