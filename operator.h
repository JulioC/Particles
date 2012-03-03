#ifndef OPERATOR_H
#define OPERATOR_H

class Particle;
class Emitter;

class Operator {
public:
  virtual ~Operator() {};
  virtual void apply(Particle *p, Emitter *e=0) = 0;
};

#endif // OPERATOR_H
