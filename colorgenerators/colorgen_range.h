#ifndef COLORGEN_RANGE_H
#define COLORGEN_RANGE_H

#include "colorgenerator.h"

class ColorGen_Range : public ColorGenerator {
public:
  ColorGen_Range(const Color &min, const Color &max, bool linear = false);
  virtual ~ColorGen_Range();

  virtual Color generate();

protected:
  Color _min;
  Color _range;

  bool _linear;
};

#endif // COLORGEN_RANGE_H
