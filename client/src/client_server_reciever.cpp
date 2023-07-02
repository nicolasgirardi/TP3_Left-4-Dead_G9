#include "../include/client_server_reciever.h"

ServerReciever::ServerReciever(Protocolo &protocolo, Queue<Message> &estadosDelJuego) :
        protocolo(protocolo), estadosDelJuego(estadosDelJuego), running(true) {}

void ServerReciever::run() {
    while (running) {
        Message msg = protocolo.recibir_estado_juego();
        if (msg.es_fin_de_juego()) {
            running.store(false);
            break;
        }
        estadosDelJuego.push(msg);
    }
}

void ServerReciever::stop() {
    running.store(false);
}

bool ServerReciever::isAlive() {
    return running.load();
}
