#include "particle.h"

Particle::Particle(int l, const Vector4D &p, const Vector4D &v) :
    lifetime(l),
    position(p),
    velocity(v) {
}
