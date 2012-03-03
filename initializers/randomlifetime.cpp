#include "randomlifetime.h"

#include "stdlib.h"

#include "particle.h"

RandomLifetime::RandomLifetime(float max, float min) :
  Initializer(),
  _min(min),
  _range(max - min) {
}

RandomLifetime::~RandomLifetime() {
}

void RandomLifetime::apply(Particle *p, Emitter *e) {
  p->lifetime = _min + (float)rand()/(float)RAND_MAX * _range;
}
