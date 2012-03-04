#ifndef LIFETIMERANDOM_H
#define LIFETIMERANDOM_H

#include "initializer.h"

class LifetimeRandom : public Initializer {
public:
  LifetimeRandom(float max, float min = .0);
  virtual ~LifetimeRandom();

  virtual void apply(Particle *p, Emitter *e = 0);

protected:
  float _min;
  float _range;
};

#endif // LIFETIMERANDOM_H
