#include "init_radius.h"

#include <stdlib.h>

#include "particle.h"

Init_Radius::Init_Radius(float max, float min) :
  Initializer(),
  _min(min),
  _range(max - min) {
}

Init_Radius::~Init_Radius() {
}

void Init_Radius::apply(Particle *p, Emitter *e) {
  p->radius = _min + _range * (float)rand()/(float)RAND_MAX;
}
