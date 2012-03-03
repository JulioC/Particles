#include "emitter.h"

#include <stddef.h>

#include "particle.h"
#include "renderer.h"

Emitter::Emitter(const Vector4D &pos, const Vector4D &vel, int itv, int max) :
  _position(pos),
  _velocity(vel),
  _interval(itv),
  _maxParticles(max),
  _renderer(NULL),
  _initializers(NULL),
  _operators(NULL),
  _particles(NULL),
  _elapsed(itv) {
  _particles = new Particle*[_maxParticles];
  for(int i = 0; i < _maxParticles; i++) {
    _particles[i] = NULL;
  }

  _initializers = new Initializer*[MAX_INITIALIZERS];
  for(int i = 0; i < MAX_INITIALIZERS; i++) {
    _initializers[i] = NULL;
  }

  _operators = new Operator*[MAX_OPERATORS];
  for(int i = 0; i < MAX_OPERATORS; i++) {
    _operators[i] = NULL;
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

  for(int i = 0; i < MAX_INITIALIZERS; i++) {
    if(_initializers[i]) {
      //delete _initializers[i];
      _initializers[i] = NULL;
    }
  }
  delete[] _initializers;

  for(int i = 0; i < MAX_OPERATORS; i++) {
    if(_operators[i]) {
      //delete _operators[i];
      _operators[i] = NULL;
    }
  }
  delete[] _operators;
}

void Emitter::update(int elapsed) {
  float elapsedf = (float)elapsed/1000;
  for(int i = 0; i < _maxParticles; i++) {
    if(_particles[i]) {
      Particle* p = _particles[i];

      // Update particle state (do it with operators?)
      p->position += p->velocity * elapsedf;
      p->lifetime -= elapsed;

      applyOperators(p);

      if(p->dead) {
        removeParticle(i);
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

bool Emitter::addInitializer(Initializer *initr) {
  int index;

  // We should store the top of the array
  for(index = 0; index < MAX_INITIALIZERS; index++) {
    if(!_initializers[index]) break;
  }

  if(index >= MAX_INITIALIZERS) return false;

  _initializers[index] = initr;

  return true;
}

bool Emitter::addOperator(Operator *opr) {
  int index;

  // We should store the top of the array
  for(index = 0; index < MAX_OPERATORS; index++) {
    if(!_operators[index]) break;
  }

  if(index >= MAX_OPERATORS) return false;

  _operators[index] = opr;

  return true;
}

bool Emitter::createParticle() {
  int index;
  for(index = 0; index < _maxParticles; index++) {
    if(!_particles[index]) break;
  }

  if(index >= _maxParticles) return false;

  Particle* particle = new Particle(_position, _velocity);
  applyInitializers(particle);

  _particles[index] = particle;

  return true;
}

void Emitter::removeParticle(int index) {
  delete _particles[index];
  _particles[index] = NULL;

  //@TODO: Keep track of free indexes (?)
}

void Emitter::applyInitializers(Particle *p) {
  int index;
  for(index = 0; index < MAX_INITIALIZERS; index++) {
    if(_initializers[index]) {
      //_initializers[index]->apply(p);
    }
  }
}

void Emitter::applyOperators(Particle *p) {
  int index;
  for(index = 0; index < MAX_OPERATORS; index++) {
    if(_operators[index]) {
      //_operators[index]->apply(p);
    }
  }
}