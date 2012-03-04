#ifndef INIT_POSITIONOFFSET_H
#define INIT_POSITIONOFFSET_H

#include "vector4d.h"
#include "initializer.h"

class Init_PositionOffset : public Initializer {
public:
  Init_PositionOffset(const Vector4D &min, const Vector4D &max);
  virtual ~Init_PositionOffset();

  virtual void apply(Particle *p, Emitter *e = 0);

protected:
  Vector4D _min;
  Vector4D _range;
};

#endif // INIT_POSITIONOFFSET_H
