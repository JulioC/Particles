#ifndef COLORGENERATOR_H
#define COLORGENERATOR_H

#include "color.h"

class ColorGenerator {
public:
  virtual ~ColorGenerator() {};
  virtual Color generate() = 0;
};

#endif // COLORGENERATOR_H
