#ifndef DECAYOPERATOR_H
#define DECAYOPERATOR_H

#include "operator.h"

class DecayOperator : public Operator {
public:
  DecayOperator();
  virtual ~DecayOperator();

  virtual void apply(Particle *p, float elapsed);
};

#endif // DECAYOPERATOR_H
