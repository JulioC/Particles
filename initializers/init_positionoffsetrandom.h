#ifndef INIT_POSITIONOFFSETRANDOM_H
#define INIT_POSITIONOFFSETRANDOM_H

#include "vector4d.h"
#include "initializer.h"

class Init_PositionOffsetRandom : public Initializer {
public:
  Init_PositionOffsetRandom(const Vector4D &min, const Vector4D &max);
  virtual ~Init_PositionOffsetRandom();

  virtual void apply(Particle *p, Emitter *e = 0);

protected:
  Vector4D _min;
  Vector4D _range;
};

#endif // INIT_POSITIONOFFSETRANDOM_H
