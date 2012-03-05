#include "init_directioncone.h"

#include <stdlib.h>
#include <math.h>

#include "particle.h"

const float Init_DirectionCone::TWOPI = 6.283185307;

Init_DirectionCone::Init_DirectionCone(const Vector3D &normal, float maxAngle, float minAngle) :
  Initializer(),
  _normal(normal),
  _axis(),
  _min(TWOPI * minAngle / 360.0),
  _range(TWOPI * (maxAngle - minAngle) / 360.0) {
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

Init_DirectionCone::~Init_DirectionCone() {
}

void Init_DirectionCone::apply(Particle *p, Emitter *e) {
  float speed = p->velocity.length();
  Vector3D res = _normal;

  float theta = TWOPI * (float)rand()/(float)RAND_MAX;
  float omega = _min + _range * (float)rand()/(float)RAND_MAX;
  float sin_omega = sin(omega);

  res *= cos(omega);
  res += _axis[0] * cos(theta) * sin_omega;
  res += _axis[1] * sin(theta) * sin_omega;

  // Is res already normalized?
  res.normalize();

  p->velocity = res * speed;
}
