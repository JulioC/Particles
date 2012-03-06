#ifndef INIT_DIRECTION_H
#define INIT_DIRECTION_H

#include "initializer.h"
#include "vector3d.h"

class Zone;

class Init_Direction : public Initializer {
public:
  Init_Direction(Zone *zone, bool offset = false);
  virtual ~Init_Direction();

  virtual void apply(Particle *p, Emitter *e = 0);

protected:
  Zone *_zone;
  bool _offset;
};

#endif // INIT_DIRECTION_H
