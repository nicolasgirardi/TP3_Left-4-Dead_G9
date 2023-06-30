#include "../include/cliente_server_sender.h"

/*ServerSender::ServerSender(Protocolo &protocolo, Queue<EventoUsuario> &eventosUsuario) : protocolo(protocolo),
    eventosUsuario(eventosUsuario), running(true) {}*/
ServerSender::ServerSender(Protocolo &protocolo) : protocolo(protocolo), running(true) {}

void ServerSender::run() {
    while (running) {
        //EventoUsuario evento = eventosUsuario.pop();
        EventoUsuario evento(0x03, 0x00000000, 0x00000001);
        protocolo.enviar_evento(evento);
    }
}

void ServerSender::stop() {
    running.store(false);
}

