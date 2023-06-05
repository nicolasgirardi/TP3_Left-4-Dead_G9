#include "server_cliente_handler.h"

ClienteHandler::ClienteHandler(Socket socket, ListaPartidas* partidas) :
    socket(std::move(socket)), partidas(partidas), running(true), keep_running(true) {}

bool ClienteHandler::is_running() {
    return running;
}

void ClienteHandler::start() {
    // Me creo la queue
    run();
}

void ClienteHandler::run() {
    while(keep_running) {
        // Recibo mensaje del protocolo

        // Me fijo si es create o join
        // Si es create, creo una partida y la agrego a la lista de partidas
        // Si es join, busco la partida en la lista de partidas y me agrego a la partida
        // Si es create, le mando el id de la partida al cliente
        // Si es join, le mando el id de la partida al cliente

        // Le pregunto a la partida si esta para arrancar
    }
    running = false;
}

void ClienteHandler::stop() {
    keep_running = false;
    // Fuerzo a un cierre total del socket
    socket.shutdown(2);
    socket.close();
    reciever.stop();
}

void ClienteHandler::create_reciever(Queue<Evento*>* queue) {
    Reciever reciever(&socket, queue);
    this->reciever = reciever;
    this->reciever.start();
}