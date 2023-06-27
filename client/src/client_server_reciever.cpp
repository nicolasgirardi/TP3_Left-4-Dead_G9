#include "../include/client_server_reciever.h"

ServerReciever::ServerReciever(Protocolo &protocolo, Queue<Message> &estadosDelJuego) :
        protocolo(protocolo), estadosDelJuego(estadosDelJuego), running(true) {}

void ServerReciever::run() {
    while (running) {
        Message msg = protocolo.recibir_estado_juego();
        estadosDelJuego.push(msg);
    }
}

void ServerReciever::stop() {
    running.store(false);
}
