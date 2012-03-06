#ifndef INIT_POSITION_H
#define INIT_POSITION_H

#include "initializer.h"
#include "vector3d.h"

class Zone;

class Init_Position : public Initializer {
public:
  Init_Position(Zone *zone, bool offset = false);
  virtual ~Init_Position();

  virtual void apply(Particle *p, Emitter *e = 0);

protected:
  Zone *_zone;
  bool _offset;
};

#endif // INIT_POSITION_H
