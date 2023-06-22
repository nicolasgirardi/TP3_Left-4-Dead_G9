#ifndef SERVER_RECIEVER_H
#define SERVER_RECIEVER_H

#include "../../common_libs/include/common_thread.h"
#include "../../common_libs/include/common_queue.h"
#include "../../common_libs/include/common_socket.h"

#include "eventos/evento.h"
#include "eventos/creador_eventos.h"

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


#endif // SERVER_RECIEVER_H
