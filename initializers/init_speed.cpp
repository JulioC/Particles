#include "init_speed.h"

#include <stdlib.h>

#include "particle.h"

Init_Speed::Init_Speed(float min, float max) :
  Initializer(),
  _min(min),
  _range(max - min) {
}

Init_Speed::~Init_Speed() {
}

void Init_Speed::apply(Particle *p, Emitter *e) {
  Vector3D direction = p->velocity.normalized();

  float speed = _min + _range * (float)rand()/(float)RAND_MAX;

  p->velocity = direction * speed;
}
