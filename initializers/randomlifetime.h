#ifndef RANDOMLIFETIME_H
#define RANDOMLIFETIME_H

#include "initializer.h"

class RandomLifetime : public Initializer {
public:
  RandomLifetime(float max, float min = .0);
  virtual ~RandomLifetime();

  virtual void apply(Particle *p, Emitter *e = 0);

protected:
  float _min;
  float _range;
};

#endif // RANDOMLIFETIME_H
