#include "../include/server_cliente_handler.h"

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
    uint32_t codigoPartida = PARTIDA_INVALIDA;
    while (codigoPartida == PARTIDA_INVALIDA) {
        codigoPartida = iniciar_partida();
        protocolo.enviar_codigo_partida(codigoPartida);
    }
    create_reciever(&eventos);
    std::string mensaje = "2,1,0,0,1,0";
    protocolo.enviar_estado_juego(mensaje);
    while(keep_running) {
        std::string msg = mensajes.pop();
        protocolo.enviar_estado_juego(msg);
    }
    running = false;
}

uint32_t ClienteHandler::iniciar_partida() {
    uint32_t codigoPartida;
    std::string inicio_partida = protocolo.recibir_inicio_partida();
    if (inicio_partida == CREAR) {
        std::string nombrePartida = protocolo.recibir_nombre();
        codigoPartida = crearPartida(nombrePartida);
    } else if (inicio_partida == JOIN) {
        codigoPartida = protocolo.recibir_codigo_partida();
        joinPartida(codigoPartida);
    } else {
        return PARTIDA_INVALIDA;
    }
    return codigoPartida;
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

uint32_t ClienteHandler::crearPartida(std::string nombrePartida) {
    Partida* partida = partidas->addPartida(nombrePartida, 0);
    id = partidas->addClient(&mensajes, partida->getId());
    return partida->getId();
}

uint32_t ClienteHandler::joinPartida(uint32_t codigoPartida) {
    id = partidas->addClient(&mensajes, codigoPartida);
    Partida* partida = partidas->getPartida(codigoPartida);
    if (partida == nullptr) {
        return PARTIDA_INVALIDA;
    } else {
        partida->addClient(&mensajes, id);
        if (partida->isFull()) {
            partida->start();
        }
        return partida->getId();
    }
}
