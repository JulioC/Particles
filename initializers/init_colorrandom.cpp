#include "init_colorrandom.h"

#include <stdlib.h>

#include "particle.h"

Init_ColorRandom::Init_ColorRandom(const Vector4D &min, const Vector4D &max) :
  Initializer(),
  _min(min),
  _range(max - min) {
}

Init_ColorRandom::~Init_ColorRandom() {
}

void Init_ColorRandom::apply(Particle *p, Emitter *e) {
  Vector4D res;
  for(int i = 0; i < 4; i++) {
    res[i] = _min[i] + _range[i] * (float)rand()/(float)RAND_MAX;
  }

  p->color = res;
}
