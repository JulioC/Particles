#ifndef INIT_SPEEDOFFSETRANDOM_H
#define INIT_SPEEDOFFSETRANDOM_H

#include "vector4d.h"
#include "initializer.h"

class Init_SpeedOffsetRandom : public Initializer {
public:
  Init_SpeedOffsetRandom(const Vector4D &min, const Vector4D &max);
  virtual ~Init_SpeedOffsetRandom();

  virtual void apply(Particle *p, Emitter *e = 0);

protected:
  Vector4D _min;
  Vector4D _range;
};

#endif // INIT_SPEEDOFFSETRANDOM_H
