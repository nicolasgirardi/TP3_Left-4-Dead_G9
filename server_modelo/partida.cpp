#include "partida.h"
#include "juego.h"

Partida::Partida(uint32_t id) : id(id), eventos(2000) {}

void Partida::addClient(int idCliente) {
    Queue<Evento*>* queueSender = new Queue<Evento*>(2000);
    clientesSender[idCliente] = queueSender;
}

void Partida::removeClient(int id) {
    clientesSender.erase(id);
}

bool Partida::isFull() {
    // Poner un mutex aca
    return clientesSender.size() == maxClientes;
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
    juego.launch(this, &clientesSender, personajes);
}

Partida::~Partida() {
    for (auto& cliente : clientesSender) {
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

Queue<Evento *> *Partida::getEventos() {
    return &eventos;
}

uint32_t Partida::getCodigoPartida() {
    return id;
}

