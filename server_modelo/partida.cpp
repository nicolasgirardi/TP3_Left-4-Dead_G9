#include "partida.h"

Partida::Partida(int id) :
    id(id) {}

int Partida::addClient(Queue<Evento*>* queue) {
    int id = GeneradorID::get_id();
    clientes[id] = queue;
    return id;
}

void Partida::removeClient(int id) {
    clientes.erase(id);
}

bool Partida::isFull() {
    return clientes.size() == maxClientes;
}

void Partida::start() {
    Juego juego;
    Queue<Queue<Evento*>*>* clientes_queue = new Queue<Queue<Evento*>*>(10);
    for (auto& cliente : clientes) {
        clientes_queue->push(cliente.second);
    }
    juego.launch(this, std::move(clientes_queue));
}

Partida::~Partida() {
    for (auto& cliente : clientes) {
        delete cliente.second;
    }
}