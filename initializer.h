#ifndef INITIALIZER_H
#define INITIALIZER_H

class Particle;
class Emitter;

class Initializer {
public:
  virtual ~Initializer() {};
  virtual void apply(Particle *p, Emitter *e=0) = 0;
};

#endif // INITIALIZER_H
