#include "colorgen_range.h"

#include "random.h"

ColorGen_Range::ColorGen_Range(const Color &min, const Color &max, bool linear) :
  ColorGenerator(),
  _min(min),
  _range(),
  _linear(linear) {
  for(int i = 0; i < 4; i++) {
    _range[i] = max[i] - min[i];
  }
}

ColorGen_Range::~ColorGen_Range() {
}

Color ColorGen_Range::generate() {
  Color res;

  if(_linear) {
    float val = Random::value();
    for(int i = 0; i < 4; i++) {
      res[i] = _min[i] + _range[i] * val;
    }
  }
  else {
    for(int i = 0; i < 4; i++) {
      res[i] = _min[i] + Random::value(_range[i]);
    }
  }

  return res;
}
