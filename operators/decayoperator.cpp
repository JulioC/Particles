#include "decayoperator.h"

#include "particle.h"

DecayOperator::DecayOperator() :
  Operator() {
}

DecayOperator::~DecayOperator() {
}

void DecayOperator::apply(Particle *p, int elapsed) {
  if(p->lifetime < 0) {
    p->dead = true;
  }
}
