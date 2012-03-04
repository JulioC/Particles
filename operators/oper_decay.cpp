#include "oper_decay.h"

#include "particle.h"

Oper_Decay::Oper_Decay() :
  Operator() {
}

Oper_Decay::~Oper_Decay() {
}

void Oper_Decay::apply(Particle *p, float elapsed) {
  if(p->lifetime < 0.0) {
    p->dead = true;
  }
}
