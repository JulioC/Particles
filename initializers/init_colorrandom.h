#ifndef INIT_COLORRANDOM_H
#define INIT_COLORRANDOM_H

#include "initializer.h"
#include "vector4d.h"

class Init_ColorRandom : public Initializer {
public:
  Init_ColorRandom(const Vector4D &min, const Vector4D &max);
  virtual ~Init_ColorRandom();

  virtual void apply(Particle *p, Emitter *e = 0);

protected:
  Vector4D _min;
  Vector4D _range;
};

#endif // INIT_COLORRANDOM_H
