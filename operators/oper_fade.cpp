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
    //@TODO: the calculation could be cheaper
    p->color[3] = 255.0 - (255.0 * (_start - p->lifetime) / _start);
  }
}
