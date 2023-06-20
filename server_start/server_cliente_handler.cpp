#include "server_cliente_handler.h"

ClienteHandler::ClienteHandler(Socket socket, ListaPartidas* partidas, int id) :
    socket(std::move(socket)), partidas(partidas), running(true), keep_running(true), id(id), mensajes(20), eventos(20)
    ,protocolo(&this->socket, &eventos, id) {
    }

ClienteHandler::~ClienteHandler() {}

bool ClienteHandler::is_running() {
    return running;
}

void ClienteHandler::start() {
    run();
}

void ClienteHandler::run() {
    // Creo el protocolo
    while(keep_running) {
        if (reciever.is_running()) {
            std::string mensaje = mensajes.pop();
            protocolo.enviar_estado_juego(mensaje);
        } else {
            uint8_t codigo = protocolo.recibir_codigo();
            switch (codigo) {
                case 0x01: {
                    std::string nombre = protocolo.create();
                    Partida* partida = partidas->addPartida(nombre, 0);
                    id = partidas->addClient(&mensajes, partida->getId());
                    create_reciever(&eventos);
                    break;
                }
                case 0x02: {
                    uint32_t codigo = protocolo.join();
                    id = partidas->addClient(&mensajes, codigo);
                    create_reciever(&eventos);
                    break;
                }
                default: {
                    break;
                }
            }

        }
    }
    running = false;
}

void ClienteHandler::stop() {
    keep_running = false;
    // Fuerzo a un cierre total del socket
    socket.shutdown(2);
    socket.close();
    reciever.stop();
    reciever.join();
}

void ClienteHandler::create_reciever(Queue<Evento*>* queue) {
    // Inicializo el reciever
    reciever = Reciever(&socket, queue, id);
    reciever.start();
}
