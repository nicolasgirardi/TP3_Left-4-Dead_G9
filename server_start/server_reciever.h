#ifndef LEFT4DEAD_SERVER_RECIEVER_H
#define LEFT4DEAD_SERVER_RECIEVER_H

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
    int id;
    Queue<Evento*>* queue;
    Protocolo* protocolo;

public:
    Reciever& operator=(Reciever&);
    explicit Reciever(Socket* socket, Queue<Evento*>* queue, int id);
    Reciever();
    ~Reciever() override;
    bool is_running();
    void run() override;
    void stop();
    Reciever& operator=(const Reciever&);
};


#endif //LEFT4DEAD_SERVER_RECIEVER_H
