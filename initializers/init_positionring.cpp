#include "init_positionring.h"

#include <stdlib.h>
#include <math.h>

#include "particle.h"

const float Init_PositionRing::PI = 3.14159265;

Init_PositionRing::Init_PositionRing(const Vector4D &center, float maxRadius, float minRadius) :
  Initializer(),
  _center(center),
  _min(minRadius),
  _range(maxRadius - minRadius) {
}

Init_PositionRing::~Init_PositionRing() {
}

void Init_PositionRing::apply(Particle *p, Emitter *e) {
  Vector4D res = _center;

  //@TODO: the ring plane should have the particle direction as normal, not (0, 1, 0)

  float theta = 2.0 * PI * (float)rand()/(float)RAND_MAX;
  float r = _min + _range * (float)rand()/(float)RAND_MAX;

  res.x += r * cos(theta);
  res.z += r * sin(theta);

  p->position = res;
}
