#include "colorgen_constant.h"

ColorGen_Constant::ColorGen_Constant(const Color &color) :
  ColorGenerator(),
  _color(color) {
}

ColorGen_Constant::~ColorGen_Constant() {
}

Color ColorGen_Constant::generate() {
  return _color;
}
