#include "particle.h"

Particle::Particle(const Vector4D &p, const Vector4D &v) :
    position(p),
    velocity(v),
    lifetime(-1),
    dead(false) {
}
