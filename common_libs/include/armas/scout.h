#ifndef SCOUT_H_
#define SCOUT_H_

#include "arma.h"

class Scout : public Arma {
 public:
  Scout();
  ~Scout() override = default;
};

#endif  // SCOUT_H_