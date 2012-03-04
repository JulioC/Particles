#ifndef OPER_FADE_H
#define OPER_FADE_H

#include "operator.h"

class Oper_Fade : public Operator {
public:
  Oper_Fade(float start);
  virtual ~Oper_Fade();

  virtual void apply(Particle *p, float elapsed);

protected:
  float _start;
};

#endif // OPER_FADE_H
