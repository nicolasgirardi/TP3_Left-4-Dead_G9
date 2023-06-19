#include "server_cliente_handler.h"

ClienteHandler::ClienteHandler(Socket socket, ListaPartidas* pPartidas, int i) :
        protocolo(std::move(socket)), partidas(pPartidas), running(true), keep_running(true), id(i),
        eventosSender(2000) {}

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
    Partida* partida = partidas->getPartida(codigoPartida);
    while(!partida->isFull()) {
    }
    Reciever reciever(&protocolo, partida->getEventos());
    reciever.start();
    while (keep_running) {
        Evento* evento;
        if (eventosSender.try_pop(evento)) {
            protocolo.enviar_evento(evento);
        }
    }
    reciever.stop();
    running = false;
}

void ClienteHandler::stop() {
    //TODO: Revisar este stop
    keep_running = false;
    // Fuerzo a un cierre total del socket
    //socket.shutdown(2);
    //socket.close();
    reciever.stop();
    reciever.join();
}

uint32_t ClienteHandler::iniciar_partida() {
    uint32_t codigoPartida;
    std::string inicio_partida = protocolo.recibir_inicio_partida();
    if (inicio_partida == CREAR) {
        std::string nombrePartida = protocolo.recibir_nombre_partida();
        codigoPartida = crearPartida(nombrePartida);
    } else if (inicio_partida == JOIN) {
        codigoPartida = protocolo.recibir_codigo_partida();
        joinPartida(codigoPartida);
    } else {
    }
    return codigoPartida;
}

uint32_t ClienteHandler::crearPartida(std::string nombrePartida) {
    Partida* partida = partidas->crearPartida(std::move(nombrePartida));
    partida->addClient(id, &eventosSender);
    partidas->addPartida(partida);
    return partida->getCodigoPartida();
}

uint32_t ClienteHandler::joinPartida(uint32_t codigoPartida) {
    Partida* partida = partidas->getPartida(codigoPartida);
    if (partida == nullptr) {
        return PARTIDA_INVALIDA;
    } else {
        partida->addClient(id, &eventosSender);
        return partida->getCodigoPartida();
    }
}