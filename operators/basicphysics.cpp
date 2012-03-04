#include "basicphysics.h"

#include "particle.h"

BasicPhysics::BasicPhysics(const Vector4D &gravity, float drag) :
  Operator(),
  _drag(drag),
  _gravity(gravity) {
}

BasicPhysics::~BasicPhysics() {
}

void BasicPhysics::apply(Particle *p, float elapsed) {
  p->velocity *= 1. - _drag * elapsed;
  p->velocity += _gravity * elapsed;
}
