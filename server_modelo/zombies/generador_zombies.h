#ifndef GENERADOR_ZOMBIES_H_
#define GENERADOR_ZOMBIES_H_

#include <list>

#include "./../../common_libs/common_thread.h"
#include "./zombie.h"
#include "./witch.h"

class GeneradorZombies : public Thread {
 private:
    bool running;
    bool keep_running;
    int cantidad_zombies;
    int modo;
    int tiempo_creacion = 5;
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
    void run() override;
    void stop();
    void apurar();
    void desapurar();
    bool isApurado();
};

#endif // GENERADOR_ZOMBIES_H_
