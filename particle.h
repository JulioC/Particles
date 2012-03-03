#ifndef PARTICLE_H
#define PARTICLE_H

#include "vector4d.h"

class Particle
{
public:
    // Exposed properties for ease of access
    int lifetime;
    Vector4D position;
    Vector4D velocity;
    //@TODO: Add color

    Particle(int l, const Vector4D &p, const Vector4D &v);

private:
    // Do not copy me!
    Particle(const Particle &);
    Particle& operator=(const Particle &);
};

#endif // PARTICLE_H
