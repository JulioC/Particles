#ifndef INIT_SPEED_H
#define INIT_SPEED_H

#include "vector4d.h"
#include "initializer.h"

class Init_Speed : public Initializer {
public:
  Init_Speed(float min, float max);
  virtual ~Init_Speed();

  virtual void apply(Particle *p, Emitter *e = 0);

protected:
  float _min;
  float _range;
};

#endif // INIT_SPEED_H
