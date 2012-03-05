#ifndef PARTICLE_H
#define PARTICLE_H

#include "color.h"
#include "vector3d.h"

class Particle {
public:
  // Exposed properties for ease of access
  Vector3D position;
  Vector3D velocity;

  Color color;

  float radius;

  float lifetime;

  bool dead;

  Particle(const Vector3D &p);

  void update(float elapsed);

private:
  // Do not copy me!
  Particle(const Particle &);
  Particle& operator=(const Particle &);
};

#endif // PARTICLE_H
