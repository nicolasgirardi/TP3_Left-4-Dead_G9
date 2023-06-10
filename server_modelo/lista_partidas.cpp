//
// Created by santipira on 08/06/23.
//

#include "lista_partidas.h"

void ListaPartidas::agregarPartida(Partida *partida) {
    std::lock_guard<std::mutex> lock(m);
    partidas[partida->getId()] = partida;
}

void ListaPartidas::eliminarPartida(int id) {
    std::lock_guard<std::mutex> lock(m);
    auto it = partidas.find(id);
    if (it != partidas.end()) {
        delete it->second;
        partidas.erase(it);
    }
}

Partida *ListaPartidas::obtenerPartida(int id) {
    std::lock_guard<std::mutex> lock(m);
    auto it = partidas.find(id);
    return (it != partidas.end()) ? it->second : nullptr;
}

Partida *ListaPartidas::getPartida(uint32_t codigoPartida) {
    std::lock_guard<std::mutex> lock(m);
    for (auto& partida : partidas) {
        if (partida.second->getCodigoPartida() == codigoPartida) {
            return partida.second;
        }
    }
    return nullptr;
}
