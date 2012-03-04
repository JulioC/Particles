#ifndef OPER_BASICPHYSICS_H
#define OPER_BASICPHYSICS_H

#include "vector4d.h"
#include "operator.h"

class Oper_BasicPhysics : public Operator {
public:
  Oper_BasicPhysics(const Vector4D &gravity, float drag = .0);
  virtual ~Oper_BasicPhysics();

  virtual void apply(Particle *p, float elapsed);

protected:
  float _drag;
  Vector4D _gravity;
};

#endif // OPER_BASICPHYSICS_H
