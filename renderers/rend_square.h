#ifndef REND_SQUARE_H
#define REND_SQUARE_H

#include "renderer.h"

class Rend_Square : public Renderer {
public:
  Rend_Square();
  virtual ~Rend_Square();

  virtual void render(Particle *p);
};

#endif // REND_SQUARE_H
