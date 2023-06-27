#include "../include/cliente_server_sender.h"

ServerSender::ServerSender(Protocolo &protocolo, Queue<EventoUsuario> &eventosUsuario) : protocolo(protocolo),
    eventosUsuario(eventosUsuario), running(true) {}

void ServerSender::run() {
    while (running) {
        EventoUsuario evento = eventosUsuario.pop();
        protocolo.enviar_evento(evento);
    }
}

void ServerSender::stop() {
    running.store(false);
}
