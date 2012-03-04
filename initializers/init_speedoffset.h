#ifndef INIT_SPEEDOFFSET_H
#define INIT_SPEEDOFFSET_H

#include "vector4d.h"
#include "initializer.h"

class Init_SpeedOffset : public Initializer {
public:
  Init_SpeedOffset(const Vector4D &min, const Vector4D &max);
  virtual ~Init_SpeedOffset();

  virtual void apply(Particle *p, Emitter *e = 0);

protected:
  Vector4D _min;
  Vector4D _range;
};

#endif // INIT_SPEEDOFFSET_H
