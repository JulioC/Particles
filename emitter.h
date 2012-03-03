#ifndef EMITTER_H
#define EMITTER_H

#include "vector4d.h"

#define MAX_PARTICLES 32

class Particle;
class Renderer;

class Emitter {
public:
  Emitter(const Vector4D &pos, const Vector4D &vel, int itv = 1000, int dur = -1, int max = MAX_PARTICLES);
  ~Emitter();

  void update(int elapsed);
  void draw();

  void renderer(Renderer* rend);

  //@TODO: add Renderer, Intializers, Operators

private:
  // Do not copy me!
  Emitter(const Emitter &);
  Emitter& operator=(const Emitter &);

  Vector4D _position;
  Vector4D _velocity; //@NOTE: We shouldn't call this velocity
  int _interval;
  int _duration;

  int _maxParticles;

  Renderer* _renderer;
  Particle** _particles;

  int _elapsed;

  bool createParticle();
  void removeParticle(int index);
};

#endif // EMITTER_H
