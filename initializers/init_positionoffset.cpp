#include "init_positionoffset.h"

#include <stdlib.h>

#include "particle.h"

Init_PositionOffset::Init_PositionOffset(const Vector4D &max, const Vector4D &min) :
  Initializer(),
  _min(min),
  _range(max - min) {
}

Init_PositionOffset::~Init_PositionOffset() {
}

void Init_PositionOffset::apply(Particle *p, Emitter *e) {
  Vector4D res;
  for(int i = 0; i < 4; i++) {
    res[i] = _min[i] + _range[i] * (float)rand()/(float)RAND_MAX;
  }

  p->position += res;
}
