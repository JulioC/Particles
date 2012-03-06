#ifndef INIT_DIRECTION_H
#define INIT_DIRECTION_H

#include "initializer.h"
#include "vector3d.h"

class V3DGenerator;

class Init_Direction : public Initializer {
public:
  Init_Direction(V3DGenerator *generator, bool offset = false);
  virtual ~Init_Direction();

  virtual void apply(Particle *p, Emitter *e = 0);

protected:
  V3DGenerator *_generator;
  bool _offset;
};

#endif // INIT_DIRECTION_H
