#include "../include/client_server_reciever.h"

ServerReciever::ServerReciever(Protocolo &protocolo, Queue<Message> &estadosDelJuego) :
        protocolo(protocolo), estadosDelJuego(estadosDelJuego), running(true) {}

void ServerReciever::run() {
    int i = 0;
    while (i < 3) {
        Message msg = protocolo.recibir_estado_juego();
        ++i;
        std::cout << "id: " << msg.get_id() << " x: " << msg.get_x() << " y: " << msg.get_y() << std::endl;
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
