#include <iostream>
#include "lista_partida.h"

ListaPartidas::ListaPartidas() {}

void ListaPartidas::addPartida(Partida* partida) {
    std::lock_guard<std::mutex> lock(m);
    partidas[partida->getCodigoPartida()] = partida;
}

Partida* ListaPartidas::crearPartida(std::string nombre, int modo) {
    std::lock_guard<std::mutex> lock(m);
    return new Partida(std::move(nombre), std::move(modo));
}

Partida *ListaPartidas::getPartida(uint32_t codigoPartida) {
    std::lock_guard<std::mutex> lock(m);
    return partidas[codigoPartida];
}

void ListaPartidas::printCodigoPartida() {
    std::lock_guard<std::mutex> lock(m);
    for (auto& partida : partidas) {
        std::cout << "codigoPartida: " << partida.first << " , Nombre: " << partida.second->getNombre() << std::endl;
    }
}

ListaPartidas::~ListaPartidas() {
    for (auto& partida : partidas) {
        delete partida.second;
    }
}