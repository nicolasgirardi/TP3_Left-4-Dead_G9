#ifndef ESTADOJUEGO_H_
#define ESTADOJUEGO_H_

#include <cstdint>
#include "../include/common_personaje.h"
#include "../include/zombies/zombie.h"


class EstadoJuego {
private:
    uint8_t game_over;
    uint8_t id;
    uint8_t id_character; //revisar el valor
    uint32_t x;
    uint32_t y;
    uint8_t ABM;
    uint8_t accion;
    uint8_t vida;
public:
    EstadoJuego(Personaje& personaje, uint8_t abm);
    EstadoJuego(Zombie* zombie);
    EstadoJuego(int idCliente, int idPersonaje);
    ~EstadoJuego() = default;
    uint8_t setAccion(int movimiento, bool disparando);
    //getters and setters
    uint8_t get_id() const;
    uint8_t get_id_character() const;
    uint8_t get_x() const;
    uint8_t get_y() const;
    uint8_t get_ABM() const;
    uint8_t get_accion() const;
    uint8_t get_vida() const;

    uint8_t get_game_over() const;
};

#endif // ESTADOJUEGO_H_
