#ifndef SPEEDOFFSETRANDOM_H
#define SPEEDOFFSETRANDOM_H

#include "vector4d.h"
#include "initializer.h"

class SpeedOffsetRandom : public Initializer {
public:
  SpeedOffsetRandom(const Vector4D &min, const Vector4D &max);
  virtual ~SpeedOffsetRandom();

  virtual void apply(Particle *p, Emitter *e = 0);

protected:
  Vector4D _min;
  Vector4D _range;
};

#endif // SPEEDOFFSETRANDOM_H
