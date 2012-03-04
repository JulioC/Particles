#include "speedoffsetrandom.h"

#include <stdlib.h>

#include "particle.h"

SpeedOffsetRandom::SpeedOffsetRandom(const Vector4D &max, const Vector4D &min) :
  Initializer(),
  _min(min),
  _range(max - min) {
}

SpeedOffsetRandom::~SpeedOffsetRandom() {
}

void SpeedOffsetRandom::apply(Particle *p, Emitter *e) {
  Vector4D res;
  for(int i = 0; i < 4; i++) {
    res[i] = _min[i] + _range[i] * (float)rand()/(float)RAND_MAX;
  }

  p->velocity += res;
}
