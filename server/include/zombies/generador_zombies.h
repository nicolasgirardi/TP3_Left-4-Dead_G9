#ifndef GENERADOR_ZOMBIES_H_
#define GENERADOR_ZOMBIES_H_

#include <list>

#include "../../../common_libs/include/common_thread.h"
#include "./zombie.h"
#include "./witch.h"

class GeneradorZombies {
 private:
    int frames_creacion = 0;
    int cantidad_zombies;
    int modo;
    int tiempo_creacion = 10;
    std::list<Zombie*>* zombies;
    std::list<Witch*>* witches;
    int contador_witches = 0;
    std::list<Personaje*>* personajes;
    int max_x;
    int max_y;
    bool apurado = false;

 public:
    GeneradorZombies(int cantidad_zombies, std::list<Zombie*>* zombies, std::list<Witch*>* witches,
                     std::list<Personaje*>* personajes, int max_x, int max_y, int modo);
    ~GeneradorZombies();
    void generar_zombie();
    void stop();
    void apurar();
    void desapurar();
    bool isApurado();
};

#endif // GENERADOR_ZOMBIES_H_
