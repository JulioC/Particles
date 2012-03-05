#include "particle.h"

#include <float.h>

Particle::Particle(const Vector3D &p) :
  position(p),
  velocity(1, 1, 1),
  color(255, 255, 255, 255),
  radius(5.0),
  lifetime(FLT_MAX),
  dead(false) {
}

void Particle::update(float elapsed) {
  lifetime -= elapsed;
  position += velocity * elapsed;
}