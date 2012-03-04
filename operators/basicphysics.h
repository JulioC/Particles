#ifndef BASICPHYSICS_H
#define BASICPHYSICS_H

#include "vector4d.h"
#include "operator.h"

class BasicPhysics : public Operator {
public:
  BasicPhysics(const Vector4D &gravity, float drag = .0);
  virtual ~BasicPhysics();

  virtual void apply(Particle *p, float elapsed);

protected:
  float _drag;
  Vector4D _gravity;
};

#endif // BASICPHYSICS_H
