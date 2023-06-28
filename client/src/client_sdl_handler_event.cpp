#include <SDL_events.h>
#include "../include/client_sdl_handler_event.h"

SDLHandlerEvent::SDLHandlerEvent() : eventosUsuario(2000), running(true) {}

void SDLHandlerEvent::run() {
    while (running) {
        SDL_Event event;
        SDL_WaitEvent(&event);
        if (event.type == SDL_QUIT) {
            running.store(false);
            break;
        }
        /*if (event.type == SDL_KEYDOWN) {
            EventoUsuario evento;
            evento.set_tecla(event.key.keysym.sym);
            eventosUsuario.push(evento);
        }*/
        //Preguntar prioridad de eventos (apagar sonidos, brillo) no enviar al server.
        // 1 colas, ewventos a servidor.
        // 1 cola, eventos locales pusheas sin blocking. Comunica con gameloop/renderer
        EventoUsuario evento(0x01, 0x01010101, 0x01010101);
        eventosUsuario.push(evento);
    }
}

void SDLHandlerEvent::stop() {
    running.store(false);
}

SDLHandlerEvent::~SDLHandlerEvent() {
    eventosUsuario.close();
}

Queue<EventoUsuario>& SDLHandlerEvent::get_eventos_usuario() {
    return std::ref(eventosUsuario);
}
