#ifndef INIT_COLOR_H
#define INIT_COLOR_H

#include "initializer.h"
#include "color.h"

class Init_Color : public Initializer {
public:
  Init_Color(const Color &min, const Color &max);
  virtual ~Init_Color();

  virtual void apply(Particle *p, Emitter *e = 0);

protected:
  Color _min;
  Color _range;
};

#endif // INIT_COLOR_H
