#include "oper_basicphysics.h"

#include "particle.h"

Oper_BasicPhysics::Oper_BasicPhysics(const Vector4D &gravity, float drag) :
  Operator(),
  _drag(drag),
  _gravity(gravity) {
}

Oper_BasicPhysics::~Oper_BasicPhysics() {
}

void Oper_BasicPhysics::apply(Particle *p, float elapsed) {
  p->velocity *= 1. - _drag * elapsed;
  p->velocity += _gravity * elapsed;
}
