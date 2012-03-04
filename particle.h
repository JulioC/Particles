#ifndef PARTICLE_H
#define PARTICLE_H

#include "vector4d.h"

class Particle {
public:
  // Exposed properties for ease of access
  Vector4D position;
  Vector4D velocity;

  Vector4D color;

  float radius;

  float lifetime;

  bool dead;

  Particle(const Vector4D &p, const Vector4D &v);

  void update(float elapsed);

private:
  // Do not copy me!
  Particle(const Particle &);
  Particle& operator=(const Particle &);
};

#endif // PARTICLE_H
