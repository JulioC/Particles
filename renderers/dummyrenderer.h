#ifndef DUMMYRENDERER_H
#define DUMMYRENDERER_H

#include "renderer.h"

class DummyRenderer : public Renderer {
public:
  DummyRenderer();

  void render(Particle *p);
};

#endif // DUMMYRENDERER_H
