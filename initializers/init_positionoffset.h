#ifndef INIT_POSITIONOFFSET_H
#define INIT_POSITIONOFFSET_H

#include "vector3d.h"
#include "initializer.h"

class Init_PositionOffset : public Initializer {
public:
  Init_PositionOffset(const Vector3D &min, const Vector3D &max);
  virtual ~Init_PositionOffset();

  virtual void apply(Particle *p, Emitter *e = 0);

protected:
  Vector3D _min;
  Vector3D _range;
};

#endif // INIT_POSITIONOFFSET_H
