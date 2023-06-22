#include "../include/partida.h"
#include "../include/juego.h"

Partida::Partida(int id, std::string nombre) : id(id), nombre(nombre) {}

void Partida::addClient(Queue<std::string>* queue, int id) {
    clientes[id] = queue;
}

void Partida::removeClient(int id) {
    clientes.erase(id);
}

bool Partida::isFull() {
    std::lock_guard<std::mutex> lock(m);
    return clientes.size() == maxClientes;
}

bool Partida::addPersonaje(int id, int arma = 0) {
    // Poner un mutex aca
    Personaje* personaje = new Personaje(id, arma);
    personajes.push_back(personaje);
    return true;
}

void Partida::start() {
    Juego juego;
    juego.launch(&clientes, personajes, modo);
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
