#include "../../include/armas/creador_armas.h"

Arma* CreadorArmas::crear_arma(int tipo_arma) {
  switch (tipo_arma) {
    case 0:
      return new IDF();
      break;
    case 1:
      return new P90();
      break;
    case 2:
      return new Scout();
      break;
    default:
      return new IDF();
      break;
  }
}