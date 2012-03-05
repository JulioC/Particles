#ifndef REND_SPHERE_H
#define REND_SPHERE_H

#include "renderer.h"

class Rend_Sphere : public Renderer {
public:
  Rend_Sphere(int detailLevel = 10);
  virtual ~Rend_Sphere();

  virtual void render(Particle *p);

protected:
  int _detailLevel;

  void drawSphere(float r, int lats, int longs);
};

#endif // REND_SPHERE_H
