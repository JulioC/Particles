#include "oper_acceleration.h"

#include "particle.h"

Oper_Acceleration::Oper_Acceleration(const Vector4D &acceleration) :
  _acceleration(acceleration) {
}

Oper_Acceleration::~Oper_Acceleration() {
}

void Oper_Acceleration::apply(Particle *p, float elapsed) {
  p->velocity += _acceleration * elapsed;
}
