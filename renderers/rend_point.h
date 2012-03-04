#ifndef REND_POINT_H
#define REND_POINT_H

#include "renderer.h"

class Rend_Point : public Renderer {
public:
  Rend_Point();
  virtual ~Rend_Point();

  virtual void render(Particle *p);
};

#endif // REND_POINT_H
