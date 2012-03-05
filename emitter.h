#ifndef EMITTER_H
#define EMITTER_H

#include "vector3d.h"

#define MAX_PARTICLES 1024 * 50
#define MAX_INITIALIZERS 32
#define MAX_OPERATORS 32

class Particle;
class Renderer;
class Operator;
class Initializer;

class Emitter {
public:
  Emitter(const Vector3D &pos, float itv = 1., int max = MAX_PARTICLES);
  virtual ~Emitter();

  // These should be called on every animation frame
  virtual void update(float elapsed);
  virtual void draw();

  // Set renderer, initializer and operator objects
  // They will be deallocated on ~Emitter
  void renderer(Renderer* rend);
  bool addInitializer(Initializer* initr);
  bool addOperator(Operator *opr);

protected:
  Vector3D _position;

  float _interval;

  int _maxParticles;

  bool createParticle();
  void removeParticle(int index);

  void applyInitializers(Particle *p);
  void applyOperators(Particle *p, float elapsed);

private:
  // Do not copy me!
  Emitter(const Emitter &);
  Emitter& operator=(const Emitter &);

  Renderer* _renderer;

  Initializer** _initializers;
  Operator** _operators;

  Particle** _particles;

  float _elapsed;
};

#endif // EMITTER_H
