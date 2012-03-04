#include "init_lifetime.h"

#include <stdlib.h>

#include "particle.h"

Init_Lifetime::Init_Lifetime(float max, float min) :
  Initializer(),
  _min(min),
  _range(max - min) {
}

Init_Lifetime::~Init_Lifetime() {
}

void Init_Lifetime::apply(Particle *p, Emitter *e) {
  p->lifetime = _min + _range * (float)rand()/(float)RAND_MAX;
}
