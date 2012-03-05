#include "init_directioncone.h"

#include <stdlib.h>
#include <math.h>

#include "particle.h"

const float Init_DirectionCone::TWOPI = 6.283185307;

Init_DirectionCone::Init_DirectionCone(const Vector3D &center, float maxRadius, float minRadius) :
  Initializer(),
  _center(center),
  _axis(),
  _min(minRadius),
  _range(maxRadius - minRadius) {
  // Get the perpendicular vectors
  if(center.x == 0) {
    _axis[0] = Vector3D(1, 0, 0);
  }
  else {
    _axis[0] = Vector3D(center.y, -center.x, 0);
    _axis[0].normalize();
  }
  _axis[1] = center.cross(_axis[0]);
  _axis[1].normalize();
}

Init_DirectionCone::~Init_DirectionCone() {
}

void Init_DirectionCone::apply(Particle *p, Emitter *e) {
  float speed = p->velocity.length();
  Vector3D res = _center;

  float theta = TWOPI * (float)rand()/(float)RAND_MAX;
  float radius = _min + _range * (float)rand()/(float)RAND_MAX;

  res += _axis[0] * radius * cos(theta);
  res += _axis[1] * radius * sin(theta);

  res.normalize();

  p->velocity = res * speed;
}
