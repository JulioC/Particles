#include "init_positionring.h"

#include <stdlib.h>
#include <math.h>

#include "particle.h"

const float Init_PositionRing::TWOPI = M_PI * 2;

Init_PositionRing::Init_PositionRing(const Vector3D &center, const Vector3D &normal, float maxRadius, float minRadius) :
  Initializer(),
  _center(center),
  _axis(),
  _min(minRadius),
  _range(maxRadius - minRadius) {
  // Get the perpendicular vectors
  if(normal.x == 0) {
    _axis[0] = Vector3D(1, 0, 0);
  }
  else {
    _axis[0] = Vector3D(normal.y, -normal.x, 0);
    _axis[0].normalize();
  }
  _axis[1] = normal.cross(_axis[0]);
  _axis[1].normalize();
}

Init_PositionRing::~Init_PositionRing() {
}

void Init_PositionRing::apply(Particle *p, Emitter *e) {
  Vector3D res = _center;
  float theta = TWOPI * (float)rand()/(float)RAND_MAX;
  float radius = _min + _range * (float)rand()/(float)RAND_MAX;

  res += _axis[0] * radius * cos(theta);
  res += _axis[1] * radius * sin(theta);

  p->position = res;
}
