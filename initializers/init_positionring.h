#ifndef INIT_POSITIONRING_H
#define INIT_POSITIONRING_H

#include "vector4d.h"
#include "initializer.h"

class Init_PositionRing : public Initializer {
public:
  Init_PositionRing(const Vector4D &center, const Vector4D &normal, float maxRadius, float minRadius = 0.0);
  virtual ~Init_PositionRing();

  virtual void apply(Particle *p, Emitter *e = 0);

protected:
  Vector4D _center;
  Vector4D _axis[2];
  float _min;
  float _range;

  static const float TWOPI;
};

#endif // INIT_POSITIONRING_H
