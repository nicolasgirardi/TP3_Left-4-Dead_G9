#include "server_cliente_handler.h"

ClienteHandler::ClienteHandler(Socket socket, ListaPartidas* partidas, int id) :
    protocol(std::move(socket)), partidas(partidas), running(true), keep_running(true), id(id),
    recieverOn(false){}

bool ClienteHandler::is_running() {
    return running;
}

void ClienteHandler::start() {
    run();
}

void ClienteHandler::run() {
    while(keep_running) {
        if (recieverOn) {
            Reciever reciever(std::ref(protocol), partida->getEventos());
            reciever.start();
            reciever.join();
        } else {
            uint32_t codigoPartida = iniciar_partida();
            protocol.enviar_codigo_partida(codigoPartida);
            recieverOn.store(true);
        }
    }
    running = false;
}

void ClienteHandler::stop() {
    keep_running = false;
    // Fuerzo a un cierre total del socket
    //socket.shutdown(2);
    //socket.close();
    //reciever.stop();
}

uint32_t ClienteHandler::iniciar_partida() {
    uint32_t codigoPartida;
    std::string inicio_partida = protocol.recibir_inicio_partida();
    if (inicio_partida == InicioPartida::crearStr) {
       std::string nombrePartida = protocol.recibir_nombre_partida();
       codigoPartida = crearPartida(nombrePartida);
    } else if (inicio_partida == InicioPartida::joinStr) {
        codigoPartida = protocol.recibir_codigo_partida();
        joinPartida(codigoPartida);
    } else {
        // Error
    }
    return codigoPartida;
}

uint32_t ClienteHandler::crearPartida(std::string nombrePartida) {
    uint32_t codigoPartida = partidas->crearPartida(std::move(nombrePartida));
    partida = partidas->getPartida(codigoPartida);
    partida->addClient(id);
    return codigoPartida;
}

void ClienteHandler::joinPartida(uint32_t codigoPartida) {
    Partida* partida = partidas->getPartida(codigoPartida);
    if (partida == nullptr) {
        //
    } else {
        partida->addClient(id);
        protocol.enviar_codigo_partida(partida->getCodigoPartida());
    }
}
