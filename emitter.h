#ifndef EMITTER_H
#define EMITTER_H

#include "vector4d.h"

#define MAX_PARTICLES 32

class Particle;
class Renderer;
class Operator;
class Initializer;

class Emitter {
public:
  Emitter(const Vector4D &pos, const Vector4D &vel, int itv = 1000, int dur = -1, int max = MAX_PARTICLES);
  virtual ~Emitter();

  // These should be called on every animation frame
  virtual void update(int elapsed);
  virtual void draw();

  // Set renderer, initializer and operator objects
  // They will be deallocated on ~Emitter
  void renderer(Renderer* rend);
  void addOperator(Operator *opr);
  void addInitializer(Initializer* initr);

protected:
  Vector4D _position;
  Vector4D _velocity; //@NOTE: We shouldn't call this velocity
  int _interval;
  int _duration;

  int _maxParticles;

  bool createParticle();
  void removeParticle(int index);

private:
  // Do not copy me!
  Emitter(const Emitter &);
  Emitter& operator=(const Emitter &);

  Renderer* _renderer;
  Particle** _particles;

  int _elapsed;
};

#endif // EMITTER_H
