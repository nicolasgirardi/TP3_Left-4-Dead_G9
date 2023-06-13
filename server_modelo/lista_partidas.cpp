#include "lista_partidas.h"

ListaPartidas::ListaPartidas() {}

uint32_t ListaPartidas::crearPartida(std::string nombre) {
    std::lock_guard<std::mutex> lock(m);
    std::hash<std::string> hasher;
    uint32_t idPartida = static_cast<uint32_t>(hasher(nombre));
    partidas[idPartida] = new Partida(idPartida);
    return idPartida;
}

void ListaPartidas::addClient(int id) {
    std::lock_guard<std::mutex> lock(m);
    for (auto& partida : partidas) {
        if (!partida.second->isFull()) {
            partida.second->addClient(id);
            return;
        }
    }
    partidas[id]->addClient(id);
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