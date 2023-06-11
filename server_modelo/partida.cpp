#include "partida.h"

Partida::Partida(int id, std::string nombre) : id(id), nombre(nombre) {}

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
    juego.launch(&clientes, personajes);
}

Partida::~Partida() {
    for (auto& cliente : clientes) {
        delete cliente.second;
    }
}

std::string Partida::getEstado() {
    std::string estado = "";
    for (auto& personaje : personajes) {
        estado += personaje->get_estado() + " ";
    }
    return estado;
}

int Partida::getId() {
    return id;
}

ListaPartidas::ListaPartidas() {}

Partida* ListaPartidas::addPartida(std::string nombre) {
    std::lock_guard<std::mutex> lock(m);
    Partida* partida = new Partida(id, nombre);
    partidas[id] = partida;
    // El mutex se libera aca
    return partida;
}

void ListaPartidas::addClient(Queue<Evento*>* queue, int id) {
    std::lock_guard<std::mutex> lock(m);
    for (auto& partida : partidas) {
        if (!partida.second->isFull()) {
            partida.second->addClient(queue, id);
            return;
        }
    }
    partidas[id]->addClient(queue, id);
}

void ListaPartidas::removeClient(int id) {
    std::lock_guard<std::mutex> lock(m);
    for (auto& partida : partidas) {
        partida.second->removeClient(id);
    }
}

bool ListaPartidas::addPersonaje(int id, int arma) {
    std::lock_guard<std::mutex> lock(m);
    for (auto& partida : partidas) {
        if (partida.second->addPersonaje(id, arma)) {
            return true;
        }
    }
    return false;
}

ListaPartidas::~ListaPartidas() {
    for (auto& partida : partidas) {
        delete partida.second;
    }
}
