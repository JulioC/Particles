#ifndef COLORGEN_CONSTANT_H
#define COLORGEN_CONSTANT_H

#include "colorgenerator.h"

class ColorGen_Constant : public ColorGenerator {
public:
  ColorGen_Constant(const Color &color);
  virtual ~ColorGen_Constant();

  virtual Color generate();

protected:
  Color _color;
};

#endif // COLORGEN_CONSTANT_H
