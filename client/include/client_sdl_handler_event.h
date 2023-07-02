#ifndef CLIENT_SDL_HANDLER_EVENT_H_
#define CLIENT_SDL_HANDLER_EVENT_H_

#include <atomic>
#include "../../common_libs/include/common_thread.h"
#include "../../common_libs/include/evento_usuario.h"
#include "../../common_libs/include/common_queue.h"
#include "../include/key_binds/key_bind_enum.h"

class SDLHandlerEvent : public Thread {
private:
    /* data necesaria para que pueda leer acciones por teclado y pushear a la queue */
    Queue<EventoUsuario>& eventosUsuario;
    std::atomic<bool> running;

 public:
    explicit SDLHandlerEvent(Queue<EventoUsuario>& eventosUsuario);
    virtual void run() override;
    void stop();
    ~SDLHandlerEvent() override = default;

    bool isRunning();
};


#endif // CLIENT_SDL_HANDLER_EVENT_H_
