#ifndef INIT_RADIUS_H
#define INIT_RADIUS_H

#include "initializer.h"

class Init_Radius : public Initializer {
public:
  Init_Radius(float max, float min = .0);
  virtual ~Init_Radius();

  virtual void apply(Particle *p, Emitter *e = 0);

protected:
  float _min;
  float _range;
};

#endif // INIT_RADIUS_H
