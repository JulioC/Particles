#ifndef POSITIONOFFSETRANDOM_H
#define POSITIONOFFSETRANDOM_H

#include "vector4d.h"
#include "initializer.h"

class PositionOffsetRandom : public Initializer {
public:
  PositionOffsetRandom(const Vector4D &min, const Vector4D &max);
  virtual ~PositionOffsetRandom();

  virtual void apply(Particle *p, Emitter *e = 0);

protected:
  Vector4D _min;
  Vector4D _range;
};

#endif // POSITIONOFFSETRANDOM_H
