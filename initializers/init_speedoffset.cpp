#include "init_speedoffset.h"

#include <stdlib.h>

#include "particle.h"

Init_SpeedOffset::Init_SpeedOffset(float min, float max) :
  Initializer(),
  _min(min),
  _range(max - min) {
}

Init_SpeedOffset::~Init_SpeedOffset() {
}

void Init_SpeedOffset::apply(Particle *p, Emitter *e) {
  float speed = p->velocity.length();
  Vector4D direction = p->velocity.normalized();

  speed += _min + _range * (float)rand()/(float)RAND_MAX;

  p->velocity = direction * speed;
}
