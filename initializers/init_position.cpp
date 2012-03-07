#include "init_position.h"

#include "particle.h"
#include "v3dgenerator.h"

Init_Position::Init_Position(V3DGenerator *generator, bool offset) :
  Initializer(),
  _generator(generator),
  _offset(offset) {
}

Init_Position::~Init_Position() {
}

void Init_Position::apply(Particle *p, Emitter *e) {
  if(!_generator) {
    return;
  }

  Vector3D res(0, 0, 0);
  if(_offset) {
    res = p->position;
  }

  res += _generator->generate();

  p->position = res;
}
