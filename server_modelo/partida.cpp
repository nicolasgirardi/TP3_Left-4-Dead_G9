#include "partida.h"

Partida::Partida(std::string nombre, int modo) : nombre(std::move(nombre)), modo(modo),
                                       eventos(2000) {
    this->id = static_cast<uint32_t>(std::hash<std::string>{}(nombre));
}

void Partida::addClient(int id, Queue<Evento*>* eventos) {
    std::lock_guard<std::mutex> lock(mutex);
    clientesSender[id] = eventos;
    --clientesPermitidos;
}

void Partida::removeClient(int id) {
    std::lock_guard<std::mutex> lock(mutex);
    clientesSender.erase(id);
}

bool Partida::isFull() {
    return clientesPermitidos == 0;
}

bool Partida::addPersonaje(int id, int arma = 0) {
    std::lock_guard<std::mutex> lock(mutex);
    Personaje* personaje = new Personaje(id, arma);
    personajes.push_back(personaje);
    return true;
}

void Partida::start() {
    // Poner un mutex aca
    Juego juego;
    //juego.launch(&clientesSender, personajes, modo);
    //TODO: Revisar esta parte
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

uint32_t Partida::getCodigoPartida() {
    return id;
}

Queue<Evento*>* Partida::getEventos() {
    return &eventos;
}

std::string Partida::getNombre() {
    return nombre;
}