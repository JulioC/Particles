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
  Vector4D vel = Vector4D(0, 0, 0, 1);
  vel.x = _min.x + _range.x * (float)rand()/(float)RAND_MAX;
  vel.y = _min.y + _range.y * (float)rand()/(float)RAND_MAX;
  vel.z = _min.z + _range.z * (float)rand()/(float)RAND_MAX;
  vel.w = _min.w + _range.w * (float)rand()/(float)RAND_MAX;

  p->velocity += vel;
}
