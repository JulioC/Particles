#ifndef POINTRENDERER_H
#define POINTRENDERER_H

#include "renderer.h"

class PointRenderer : public Renderer {
public:
  PointRenderer();
  virtual ~PointRenderer();

  virtual void render(Particle *p);
};

#endif // POINTRENDERER_H
