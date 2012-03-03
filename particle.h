#ifndef PARTICLE_H
#define PARTICLE_H

#include "vector4d.h"

class Particle {
public:
  // Exposed properties for ease of access
  Vector4D position;
  Vector4D velocity;

  float lifetime;
  //@TODO: Add color

  bool dead;

  Particle(const Vector4D &p, const Vector4D &v);

  void update(float elapsed);

private:
  // Do not copy me!
  Particle(const Particle &);
  Particle& operator=(const Particle &);
};

#endif // PARTICLE_H
