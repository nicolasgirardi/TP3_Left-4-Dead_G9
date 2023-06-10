#include "server_cliente_handler.h"

ClienteHandler::ClienteHandler(Socket socket, ListaPartidas* partidas, int id) :
    protocol(std::move(socket)), partidas(partidas), running(true), keep_running(true), id(id) {}

bool ClienteHandler::is_running() {
    return running;
}

void ClienteHandler::start() {
    run();
}

void ClienteHandler::run() {
    while(keep_running) {
        if (reciever.is_running()) {
            // Mando lo de la queue
        } else {
            uint32_t codigoPartida = iniciar_partida();
            protocol.enviar_codigo_partida(codigoPartida);
            // Recibo mensaje del protocolo

            // Me fijo si es create o join
            // Si es create, creo una partida y la agrego a la lista de partidas
            // Si es join, busco la partida en la lista de partidas y me agrego a la partida
            // Si es create, le mando el id de la partida al cliente
            // Si es join, le mando el id de la partida al cliente
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

void ClienteHandler::create_reciever(Queue<Evento*>* queue) {
    //Reciever reciever(&socket, queue);
    //this->reciever = reciever;
    //this->reciever.start();
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
    Partida* partida = new Partida(std::move(nombrePartida));
    partida->addClient(id);
    partidas->agregarPartida(partida);
    return partida->getCodigoPartida();
}

void ClienteHandler::joinPartida(uint32_t codigoPartida) {
    Partida* partida = partidas->getPartida(codigoPartida);
    if (partida == nullptr) {
        //
    } else {
        partida->addClient(id);
        protocol.enviar_codigo_partida(partida->getCodigoPartida());
        //TODO: Revisar esto, ya que una Partida deberia tener un map<ClientId, Queue<Evento*>*>, para que entonces
        // cuando se agrege una nueva queue, se pueda enviar el estado de la partida a todos los clientes
    }
}
