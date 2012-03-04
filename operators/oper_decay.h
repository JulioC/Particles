#ifndef OPER_DECAY_H
#define OPER_DECAY_H

#include "operator.h"

class Oper_Decay : public Operator {
public:
  Oper_Decay();
  virtual ~Oper_Decay();

  virtual void apply(Particle *p, float elapsed);
};

#endif // DECAY_H
