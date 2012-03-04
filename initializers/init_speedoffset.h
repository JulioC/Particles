#ifndef INIT_SPEEDOFFSET_H
#define INIT_SPEEDOFFSET_H

#include "vector4d.h"
#include "initializer.h"

class Init_SpeedOffset : public Initializer {
public:
  Init_SpeedOffset(float min, float max);
  virtual ~Init_SpeedOffset();

  virtual void apply(Particle *p, Emitter *e = 0);

protected:
  float _min;
  float _range;
};

#endif // INIT_SPEEDOFFSET_H
