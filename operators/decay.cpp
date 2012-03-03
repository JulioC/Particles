#include "decay.h"

#include "particle.h"

Decay::Decay() :
  Operator() {
}

Decay::~Decay() {
}

void Decay::apply(Particle *p, float elapsed) {
  if(p->lifetime < 0.0) {
    p->dead = true;
  }
}
