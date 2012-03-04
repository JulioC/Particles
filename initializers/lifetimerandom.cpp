#include "lifetimerandom.h"

#include <stdlib.h>

#include "particle.h"

LifetimeRandom::LifetimeRandom(float max, float min) :
  Initializer(),
  _min(min),
  _range(max - min) {
}

LifetimeRandom::~LifetimeRandom() {
}

void LifetimeRandom::apply(Particle *p, Emitter *e) {
  p->lifetime = _min + _range * (float)rand()/(float)RAND_MAX;
}
