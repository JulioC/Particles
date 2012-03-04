#include "oper_fade.h"

#include "particle.h"

Oper_Fade::Oper_Fade(float start) :
  Operator(),
  _start(start) {
}

Oper_Fade::~Oper_Fade() {
}

void Oper_Fade::apply(Particle *p, float elapsed) {
  if(p->lifetime < _start) {
    p->color.a = 1.0 - (_start - p->lifetime) / _start;
  }
}
