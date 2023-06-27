#ifndef SERVER_RECIEVER_H
#define SERVER_RECIEVER_H

#include "../../common_libs/include/common_thread.h"
#include "../../common_libs/include/common_queue.h"
#include "../../common_libs/include/common_socket.h"
#include "../../common_libs/include/eventos/evento.h"
#include "../../common_libs/include/eventos/creador_eventos.h"
#include "../../common_libs/include/common_protocolo.h"

class Reciever : public Thread {
private:
    bool running;
    bool keep_running;
    int id;
    Queue<Evento*>* queueJuego;
    Protocolo& protocolo;

public:
    Reciever& operator=(Reciever&);
    explicit Reciever(Protocolo& protocolo, Queue<Evento*>* queueJuego, int id);
    Reciever();
    ~Reciever() override;
    bool is_running();
    void run() override;
    void stop();
    //copy delete
    //move delete
    //copy assignment delete
    //move assignment delete
    Reciever (const Reciever&) = delete;
    Reciever (Reciever&&) = delete;
    Reciever& operator=(const Reciever&) = delete;
};


#endif // SERVER_RECIEVER_H
