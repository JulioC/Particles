#ifndef OPER_ACCELERATION_H
#define OPER_ACCELERATION_H

#include "vector4d.h"
#include "operator.h"

class Oper_Acceleration : public Operator {
public:
  Oper_Acceleration(const Vector4D &acceleration);
  virtual ~Oper_Acceleration();

  virtual void apply(Particle *p, float elapsed);

protected:
  Vector4D _acceleration;
};

#endif // OPER_ACCELERATION_H
