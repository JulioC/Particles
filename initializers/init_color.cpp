#include "init_color.h"

#include <stdlib.h>

#include "particle.h"

Init_Color::Init_Color(const Color &min, const Color &max) :
  Initializer(),
  _min(min),
  _range() {
  for(int i = 0; i < 4; i++) {
    _range[i] = max[i] - min[i];
  }
}

Init_Color::~Init_Color() {
}

void Init_Color::apply(Particle *p, Emitter *e) {
  Color res;
  for(int i = 0; i < 4; i++) {
    res[i] = _min[i] + _range[i] * (float)rand()/(float)RAND_MAX;
  }

  p->color = res;
}
