#include "init_position.h"

#include "particle.h"
#include "zone.h"

Init_Position::Init_Position(Zone *zone, bool offset) :
  Initializer(),
  _zone(zone),
  _offset(offset) {
}

Init_Position::~Init_Position() {
  if(_zone) {
    delete _zone;
  }
}

void Init_Position::apply(Particle *p, Emitter *e) {
  if(!_zone) {
    return;
  }

  Vector3D res(0, 0, 0);
  if(_offset) {
    res = p->position;
  }

  res += _zone->point();

  p->position = res;
}
