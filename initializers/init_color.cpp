#include "init_color.h"

#include <stdlib.h>

#include "particle.h"

Init_Color::Init_Color(ColorGenerator *generator, bool offset) :
  Initializer(),
  _generator(generator),
  _offset(offset) {
}

Init_Color::~Init_Color() {
}

void Init_Color::apply(Particle *p, Emitter *e) {
  Color res(0, 0, 0, 0);
  Color val = _generator->generate();

  if(_offset) {
    res = p->color;
    for(int i = 0; i < 4; i++) {
      res[i] += val[i];
      if(res[i] > 0xFF) {
        res[i] = 0xFF;
      }
    }
  }
  else {
    res = val;
  }

  p->color = val;
}
