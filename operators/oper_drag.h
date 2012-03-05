#ifndef OPER_DRAG_H
#define OPER_DRAG_H

#include "vector3d.h"
#include "operator.h"

class Oper_Drag : public Operator {
public:
  Oper_Drag(float drag);
  virtual ~Oper_Drag();

  virtual void apply(Particle *p, float elapsed);

protected:
  float _drag;
};

#endif // OPER_DRAG_H
