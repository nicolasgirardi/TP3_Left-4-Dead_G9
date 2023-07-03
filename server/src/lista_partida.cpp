#include <iostream>
#include "../include/lista_partida.h"

ListaPartidas::ListaPartidas() {}

int ListaPartidas::addPartida(std::string nombre, int modo = 0) {
    std::lock_guard<std::mutex> lock(m);
    int id = partidas.size();
    Partida partida(id, nombre, modo);
    partidas.emplace(id, std::move(partida));
    return id;
}

void ListaPartidas::removeClient(int id) {
    std::lock_guard<std::mutex> lock(m);
    for (auto& partida : partidas) {
        partida.second.removeClient(id);
    }
}

bool ListaPartidas::addPersonaje(int id, int arma) {
    std::lock_guard<std::mutex> lock(m);
    for (auto& partida : partidas) {
        if (partida.second.addPersonaje(id, arma)) {
            return true;
        }
    }
    return false;
}

ListaPartidas::~ListaPartidas() {
    for (auto& partida : partidas) {
        //delete partida.second;
    }
}

Partida& ListaPartidas::getPartida(uint32_t codigoPartida) {
    std::lock_guard<std::mutex> lock(m);
    for (auto& partida : partidas) {
        if (partida.second.getId() == codigoPartida) {
            return partida.second;
        }
    }
    throw std::runtime_error("Partida no encontrada");
}

std::map<int, Partida>& ListaPartidas::getPartidas() {
    return partidas;
}

void ListaPartidas::iniciarPartida(uint32_t codigoPartida) {
    std::lock_guard<std::mutex> lock(m);
    for (auto& partida : partidas) {
        if (partida.second.getId() == codigoPartida) {
            //partida.second.iniciar();
            return;
        }
    }

}
