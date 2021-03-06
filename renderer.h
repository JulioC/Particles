#ifndef RENDERER_H
#define RENDERER_H

class Particle;

class Renderer {
public:
  virtual ~Renderer() {};
  virtual void render(Particle* p) = 0;
};

#endif // RENDERER_H
