#include "positionoffsetrandom.h"

#include <stdlib.h>

#include "particle.h"

PositionOffsetRandom::PositionOffsetRandom(const Vector4D &max, const Vector4D &min) :
  Initializer(),
  _min(min),
  _range(max - min) {
}

PositionOffsetRandom::~PositionOffsetRandom() {
}

void PositionOffsetRandom::apply(Particle *p, Emitter *e) {
  Vector4D pos = Vector4D(0, 0, 0, 1);
  pos.x = _min.x + _range.x * (float)rand()/(float)RAND_MAX;
  pos.y = _min.y + _range.y * (float)rand()/(float)RAND_MAX;
  pos.z = _min.z + _range.z * (float)rand()/(float)RAND_MAX;
  pos.w = _min.w + _range.w * (float)rand()/(float)RAND_MAX;

  p->position += pos;
}
