#include "../include/partida.h"
#include "../include/juego.h"

Partida::Partida(int id, std::string nombre) : id(id), nombre(nombre), isRunning(true),
    queueJuego(new Queue<Evento*>(200)) {}

void Partida::addClient(Queue<std::string>& mensajes, int id, Personaje& personaje) {
    std::lock_guard<std::mutex> lock(m);
    bool exists = false;
    for (auto& pj : personajes) {
        if (pj.get_id() == personaje.get_id()) {
            exists = true;
        }
    }
    if (!exists) {
        personajes.push_back(std::move(personaje));
        clientes.insert(std::pair<int, Queue<std::string>&>(id, mensajes));
    } else {
        std::cout << "throw error: personaje ya existe en la partida" << std::endl;
    }
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
    return true;
}

/*void Partida::start() {
    Juego juego(std::ref(clientes), std::ref(personajes), modo);
    juego.start();
}*/

Partida::~Partida() {
    for (auto& cliente : clientes) {
        cliente.second.close();
    }
}

std::string Partida::getEstado() {
    std::string estado = "";
    for (auto& personaje : personajes) {
        estado += personaje.get_estado() + " ";
    }
    return estado;
}

int Partida::getId() {
    return id;
}

Partida::Partida(Partida &&other) {
    this->id = other.id;
    this->modo = other.modo;
    this->nombre = other.nombre;
    this->maxClientes = other.maxClientes;
    this->personajes = std::move(other.personajes);
    this->clientes = std::move(other.clientes);
    this->isRunning = other.isRunning.load();
    this->queueJuego = other.queueJuego;
}

std::map<int, Queue<std::string> &> &Partida::getClientes() {
    return clientes;
}

std::list<Personaje> &Partida::getPersonajes() {
    return personajes;
}

int Partida::getModo() {
    return modo;
}

std::atomic<bool> &Partida::getRunning() {
    std::lock_guard<std::mutex> lock(m);
    bool todosMuertos = false;
    for (auto &personaje : personajes) {
        if (personaje.get_vida() <= 0) {
            todosMuertos = true;
        } else {
            todosMuertos = false;
            break;
        }
    }
    if (todosMuertos) {
        isRunning.store(false);
    }
    return isRunning;
}

Queue<Evento *> *Partida::getQueueJuego() {
    return queueJuego;
}

