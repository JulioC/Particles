#ifndef DECAY_H
#define DECAY_H

#include "operator.h"

class Decay : public Operator {
public:
  Decay();
  virtual ~Decay();

  virtual void apply(Particle *p, float elapsed);
};

#endif // DECAY_H
