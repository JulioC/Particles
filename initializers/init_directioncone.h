#ifndef INIT_DIRECTIONCONE_H
#define INIT_DIRECTIONCONE_H

#include "vector3d.h"
#include "initializer.h"

class Init_DirectionCone : public Initializer {
public:
  Init_DirectionCone(const Vector3D &center, float maxRadius, float minRadius = 0.0);
  virtual ~Init_DirectionCone();

  virtual void apply(Particle *p, Emitter *e = 0);

protected:
  Vector3D _center;
  Vector3D _axis[2];
  float _min;
  float _range;

  static const float TWOPI;
};

#endif // INIT_DIRECTIONCONE_H
