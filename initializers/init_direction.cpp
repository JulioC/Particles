#include "init_direction.h"

#include "particle.h"
#include "zone.h"

Init_Direction::Init_Direction(Zone *zone, bool offset) :
  Initializer(),
  _zone(zone),
  _offset(offset) {
}

Init_Direction::~Init_Direction() {
  if(_zone) {
    delete _zone;
  }
}

void Init_Direction::apply(Particle *p, Emitter *e) {
  if(!_zone) {
    return;
  }

  float speed = p->velocity.length();
  Vector3D res(0, 0, 0);
  if(_offset) {
    res = _zone->point();
  }

  res += _zone->point();
  res.normalize();

  p->velocity = res * speed;
}
