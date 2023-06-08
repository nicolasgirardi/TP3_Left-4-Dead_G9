#include "partida.h"

Partida::Partida(int id) :
    id(id) {}

void Partida::addClient(Queue<Evento*>* queue, int id) {
    clientes[id] = queue;
}

void Partida::removeClient(int id) {
    clientes.erase(id);
}

bool Partida::isFull() {
    // Poner un mutex aca
    return clientes.size() == maxClientes;
}

bool Partida::addPersonaje(int id, int arma = 0) {
    // Poner un mutex aca
    Personaje* personaje = new Personaje(id, arma);
    personajes.push_back(personaje);
    return true;
}

void Partida::start() {
    // Poner un mutex aca
    Juego juego;
    juego.launch(this, &clientes, personajes);
}

Partida::~Partida() {
    for (auto& cliente : clientes) {
        delete cliente.second;
    }
}