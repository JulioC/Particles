#include "emitter.h"

#include <stddef.h>

#include "particle.h"
#include "renderer.h"

Emitter::Emitter(const Vector4D &pos, const Vector4D &vel, int itv, int dur, int max) :
    _position(pos),
    _velocity(vel),
    _interval(itv),
    _duration(dur),
    _maxParticles(max),
    _renderer(NULL),
    _particles(NULL),
    _elapsed(0) {
    _particles = new Particle*[_maxParticles];
    for(int i = 0; i < _maxParticles; i++) {
        _particles[i] = NULL;
    }
}

Emitter::~Emitter() {
    for(int i = 0; i < _maxParticles; i++) {
        if(_particles[i]) {
            delete _particles[i];
            _particles[i] = NULL;
        }
    }
    delete[] _particles;
}

void Emitter::update(int elapsed) {
    for(int i = 0; i < _maxParticles; i++) {
        if(_particles[i]) {
            Particle* p = _particles[i];

            // This should be done with an operator (?)
            p->position += p->velocity * _elapsed;

            // This should be done with an operator
            p->lifetime -= elapsed;

            //@TODO: Apply operators on p

            if(p->lifetime < 0) {
                delete p;
                _particles[i] = NULL;

            }
        }
    }

    _elapsed += elapsed;
    while(_elapsed > _interval) {
        createParticle();
        _elapsed -= _interval;
    }
}

void Emitter::draw() {
    if(_renderer) {
        for(int i = 0; i < _maxParticles; i++) {
            if(_particles[i]) {
                _renderer->render(_particles[i]);
            }
        }
    }
}

void Emitter::renderer(Renderer *rend) {
    if(_renderer) {
        delete[] _renderer;
    }

    _renderer = rend;
}

bool Emitter::createParticle() {
    int index;
    for(int index  = 0; index  < _maxParticles; index ++) {
        if(!_particles[index]) break;
    }

    if(index >= _maxParticles) return false;

    Particle* particle = new Particle(_position, _velocity);
    //@TODO: Apply Initializers here

    _particles[index] = particle;

    return true;
}

void Emitter::removeParticle(int index) {
    delete _particles[index];
    _particles[index] = NULL;

    //@TODO: Keep track of free indexes (?)
}
