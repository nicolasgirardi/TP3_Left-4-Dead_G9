#ifndef LEFT4DEAD_CREADOR_ARMAS_H_
#define LEFT4DEAD_CREADOR_ARMAS_H_

// 0: IDF
// 1: P90
// 2: Scout

#include "arma.h"
#include "idf.h"
#include "p90.h"
#include "scout.h"

class CreadorArmas {
 public:
  // Hago crear arma estatico para no tener que instanciar un creador de armas
  static Arma* crear_arma(int tipo_arma);
};

#endif  // LEFT4DEAD_CREADOR_ARMAS_H_