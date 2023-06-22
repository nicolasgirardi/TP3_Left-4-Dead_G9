#include <iostream>
#include "lista_partida.h"

ListaPartidas::ListaPartidas() {}

Partida* ListaPartidas::addPartida(std::string nombre, int modo = 0) {
    std::lock_guard<std::mutex> lock(m);
    int id = partidas.size();
    Partida* partida = new Partida(id, nombre);
    partidas[id] = partida;
    return partida;
}
//Esta mal
int ListaPartidas::addClient(Queue<std::string>* queue, int id) {
    std::lock_guard<std::mutex> lock(m);
    for (auto& partida : partidas) {
        if (!partida.second->isFull()) {
            partida.second->addClient(queue, id);
            return partida.second->getId();
        }
    }
    partidas[id]->addClient(queue, id);
    return GeneradorID::get_id();
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

Partida *ListaPartidas::getPartida(uint32_t codigoPartida) {
    std::lock_guard<std::mutex> lock(m);
    for (auto& partida : partidas) {
        if (partida.second->getId() == codigoPartida) {
            return partida.second;
        }
    }
    return nullptr;
}

std::map<int, Partida*> ListaPartidas::getPartidas() {
    return partidas;
}
