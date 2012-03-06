#ifndef INIT_COLOR_H
#define INIT_COLOR_H

#include "initializer.h"
#include "colorgenerator.h"

class Init_Color : public Initializer {
public:
  Init_Color(ColorGenerator *generator, bool offset = false);
  virtual ~Init_Color();

  virtual void apply(Particle *p, Emitter *e = 0);

protected:
  ColorGenerator *_generator;

  bool _offset;
};

#endif // INIT_COLOR_H
