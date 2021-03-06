#ifndef INIT_POSITION_H
#define INIT_POSITION_H

#include "initializer.h"
#include "vector3d.h"

class V3DGenerator;

class Init_Position : public Initializer {
public:
  Init_Position(V3DGenerator *generator, bool offset = false);
  virtual ~Init_Position();

  virtual void apply(Particle *p, Emitter *e = 0);

protected:
  V3DGenerator *_generator;
  bool _offset;
};

#endif // INIT_POSITION_H
