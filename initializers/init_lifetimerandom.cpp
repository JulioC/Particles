#include "init_lifetimerandom.h"

#include <stdlib.h>

#include "particle.h"

Init_LifetimeRandom::Init_LifetimeRandom(float max, float min) :
  Initializer(),
  _min(min),
  _range(max - min) {
}

Init_LifetimeRandom::~Init_LifetimeRandom() {
}

void Init_LifetimeRandom::apply(Particle *p, Emitter *e) {
  p->lifetime = _min + _range * (float)rand()/(float)RAND_MAX;
}
