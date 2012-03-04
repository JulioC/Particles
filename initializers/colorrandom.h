#ifndef COLORRANDOM_H
#define COLORRANDOM_H

#include "initializer.h"
#include "vector4d.h"

class ColorRandom : public Initializer {
public:
  ColorRandom(const Vector4D &min, const Vector4D &max);
  virtual ~ColorRandom();

  virtual void apply(Particle *p, Emitter *e = 0);

protected:
  Vector4D _min;
  Vector4D _range;
};

#endif // COLORRANDOM_H
