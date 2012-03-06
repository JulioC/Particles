#include "init_direction.h"

#include "particle.h"
#include "v3dgenerator.h"

Init_Direction::Init_Direction(V3DGenerator *generator, bool offset) :
  Initializer(),
  _generator(generator),
  _offset(offset) {
}

Init_Direction::~Init_Direction() {
  if(_generator) {
    delete _generator;
  }
}

void Init_Direction::apply(Particle *p, Emitter *e) {
  if(!_generator) {
    return;
  }

  float speed = p->velocity.length();
  Vector3D res(0, 0, 0);
  if(_offset) {
    res = p->velocity.normalized();
  }

  res += _generator->point().normalized();
  res.normalize();

  p->velocity = res * speed;
}
