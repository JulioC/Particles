#include "oper_drag.h"

#include "particle.h"

Oper_Drag::Oper_Drag(float drag) :
  Operator(),
  _drag(drag) {
}

Oper_Drag::~Oper_Drag() {
}

void Oper_Drag::apply(Particle *p, float elapsed) {
  p->velocity *= 1. - _drag * elapsed;
}
