#include "particle.h"

#include <float.h>

Particle::Particle(const Vector4D &p, const Vector4D &v) :
  position(p),
  velocity(v),
  color(255, 255, 255, 255),
  radius(5.0),
  lifetime(FLT_MAX),
  dead(false) {
}

void Particle::update(float elapsed) {
  lifetime -= elapsed;
  position += velocity * elapsed;
}