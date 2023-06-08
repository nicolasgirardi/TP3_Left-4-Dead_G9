#include "server_aceptador.h"

Aceptador::Aceptador(const char* port) : socket(port), running(true), keep_running(true) {
    partidas = new ListaPartidas();
}

void Aceptador::run() {
    while (keep_running) {
        Socket peer = socket.accept();
        ClienteHandler* cliente = new ClienteHandler(std::move(peer), partidas, GeneradorID::get_id());
        cliente->start();
        clientes.push_back(cliente);
        clientes.remove_if([](ClienteHandler* cliente) { return !cliente->is_running(); });
    }
    running = false;
    for (auto& cliente : clientes) {
        cliente->stop();
        cliente->join();
        delete cliente;
    }
}

void Aceptador::stop() {
    keep_running = false;
    // Fuerzo a un cierre total del socket
    socket.shutdown(2);
    socket.close();
    for (auto& cliente : clientes) {
        cliente->stop();
        cliente->join();
        delete cliente;
    }
}

Aceptador::~Aceptador() {
    delete partidas;
    stop();
}
