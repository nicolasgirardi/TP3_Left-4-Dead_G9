#ifndef CLIENT_SDL_HANDLER_EVENT_H_
#define CLIENT_SDL_HANDLER_EVENT_H_

#include <atomic>
#include "../../common_libs/include/common_thread.h"
#include "../../common_libs/include/evento_usuario.h"
#include "../../common_libs/include/common_queue.h"

class SDLHandlerEvent : public Thread {
private:
    /* data necesaria para que pueda leer acciones por teclado y pushear a la queue */
    Queue<EventoUsuario> eventosUsuario; //owner
    std::atomic<bool> running;

 public:
    SDLHandlerEvent();
    virtual void run() override;
    void stop();
    Queue<EventoUsuario>& get_eventos_usuario();
    ~SDLHandlerEvent() override;
};


#endif // CLIENT_SDL_HANDLER_EVENT_H_
