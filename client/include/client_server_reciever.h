#ifndef CLIENT_SERVER_HANDLER_H_
#define CLIENT_SERVER_HANDLER_H_

#include <atomic>
#include "../../common_libs/include/common_thread.h"
#include "../../common_libs/include/common_queue.h"
#include "../../common_libs/include/common_protocolo.h"

class ServerReciever : public Thread {
private:
    Protocolo& protocolo;
    Queue<Message>& estadosDelJuego; //Esta queue la crea el cliente renderer... el que se encarga de popear mensajes para dibujar
    std::atomic<bool> running;

public:
    virtual void run() override;
    ServerReciever(Protocolo& protocolo, Queue<Message>& estadosDelJuego);
    void stop();
    ~ServerReciever() override = default; //TODO: ver si hay que hacer delete de algo

    ServerReciever(const ServerReciever&) = delete;
    ServerReciever(ServerReciever&&) = delete;
    ServerReciever& operator=(const ServerReciever&) = delete;
    ServerReciever& operator=(ServerReciever&&) = delete;

    bool isAlive();
};


#endif // CLIENT_SERVER_HANDLER_H_
