#include <SDL_events.h>
#include "../include/client_sdl_handler_event.h"
#include "../../common_libs/include/common_mensaje_cliente.h"

SDLHandlerEvent::SDLHandlerEvent(Queue<EventoUsuario>& eventosUsuario) : eventosUsuario(eventosUsuario), running(true) {}

void SDLHandlerEvent::run() {
    while (running) {
        SDL_Event event;
        SDL_WaitEvent(&event);
        if (event.type == SDL_QUIT) {
            running.store(false);
            break;
        }
        SDL_Keycode key = event.key.keysym.sym;
        if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
            if (key == SDLK_d) {
                EventoUsuario evento(CMensaje::MOVE, 0x00000001, 0x00000000);
                eventosUsuario.push(evento);
            } else if (key == SDLK_a) {
                EventoUsuario evento(CMensaje::MOVE, 0xFFFFFFFF, 0x00000000);
                eventosUsuario.push(evento);
            } else if (key == SDLK_w) {
                EventoUsuario evento(CMensaje::MOVE, 0x00000000, 0xFFFFFFFF);
                eventosUsuario.push(evento);
            } else if (key == SDLK_s) {
                EventoUsuario evento(CMensaje::MOVE, 0x00000000, 0x00000001);
                eventosUsuario.push(evento);
            } else {
                std::cout << "key no mapeada: " << key << std::endl;
            }
        } else if (event.type == SDL_KEYUP && event.key.repeat == 0) {
            if (key == SDLK_d) {
                EventoUsuario evento(CMensaje::STOP_MOVE);
                eventosUsuario.push(evento);
            } else if (key == SDLK_a) {
                EventoUsuario evento(CMensaje::STOP_MOVE);
                eventosUsuario.push(evento);
            } else if (key == SDLK_w) {
                EventoUsuario evento(CMensaje::STOP_MOVE);
                eventosUsuario.push(evento);
            } else if (key == SDLK_s) {
                EventoUsuario evento(CMensaje::STOP_MOVE);
                eventosUsuario.push(evento);
            } else {
                std::cout << "key no mapeada: " << key << std::endl;
            }
        } else if (event.type == SDL_MOUSEBUTTONDOWN) {
            if (event.button.button == SDL_BUTTON_LEFT) {
                EventoUsuario evento(CMensaje::SHOOT, 0x00000000, 0x00000000);
                eventosUsuario.push(evento);
            }
        } else if (event.type == SDL_MOUSEBUTTONUP) {
            if (event.button.button == SDL_BUTTON_LEFT) {
                EventoUsuario evento(CMensaje::STOP_SHOOT);
                eventosUsuario.push(evento);
            }
        }
        //Preguntar prioridad de eventos (apagar sonidos, brillo) no enviar al server.
        // 1 colas, ewventos a servidor.
        // 1 cola, eventos locales pusheas sin blocking. Comunica con gameloop/renderer
        //EventoUsuario evento(0x01, 0x01010101, 0x01010101);
        //eventosUsuario.push(evento);
    }
}

void SDLHandlerEvent::stop() {
    running.store(false);
}

bool SDLHandlerEvent::isRunning() {
    return running.load();
}
