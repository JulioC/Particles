#ifndef INIT_COLOR_H
#define INIT_COLOR_H

#include "initializer.h"
#include "vector4d.h"

class Init_Color : public Initializer {
public:
  Init_Color(const Vector4D &min, const Vector4D &max);
  virtual ~Init_Color();

  virtual void apply(Particle *p, Emitter *e = 0);

protected:
  Vector4D _min;
  Vector4D _range;
};

#endif // INIT_COLOR_H
