#ifndef CLIENTE_SERVER_SENDER_H_
#define CLIENTE_SERVER_SENDER_H_

#include <atomic>
#include "../../common_libs/include/evento_usuario.h"
#include "../../common_libs/include/common_protocolo.h"
#include "../../common_libs/include/common_queue.h"
#include "../../common_libs/include/common_thread.h"

class ServerSender : public Thread {
 private:
    Protocolo& protocolo;
    //Queue<EventoUsuario>& eventosUsuario;
    std::atomic<bool> running;


 public:
    //ServerSender(Protocolo& protocolo, Queue<EventoUsuario>& eventosUsuario);
    ServerSender(Protocolo& protocolo);
    virtual void run() override;
    void stop();

    ~ServerSender() override = default; //TODO: ver si hay que hacer delete de algo
    ServerSender(const ServerSender&) = delete;
    ServerSender(ServerSender&&) = delete;
    ServerSender& operator=(const ServerSender&) = delete;
    ServerSender& operator=(ServerSender&&) = delete;
};

#endif // CLIENTE_SERVER_SENDER_H_
