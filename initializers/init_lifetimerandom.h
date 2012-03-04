#ifndef INIT_LIFETIMERANDOM_H
#define INIT_LIFETIMERANDOM_H

#include "initializer.h"

class Init_LifetimeRandom : public Initializer {
public:
  Init_LifetimeRandom(float max, float min = .0);
  virtual ~Init_LifetimeRandom();

  virtual void apply(Particle *p, Emitter *e = 0);

protected:
  float _min;
  float _range;
};

#endif // INIT_LIFETIMERANDOM_H
