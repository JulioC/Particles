#ifndef INIT_LIFETIME_H
#define INIT_LIFETIME_H

#include "initializer.h"

class Init_Lifetime : public Initializer {
public:
  Init_Lifetime(float max, float min = .0);
  virtual ~Init_Lifetime();

  virtual void apply(Particle *p, Emitter *e = 0);

protected:
  float _min;
  float _range;
};

#endif // INIT_LIFETIME_H
