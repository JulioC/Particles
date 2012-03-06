#ifndef V3DGENERATOR_H
#define V3DGENERATOR_H

#include "vector3d.h"

class V3DGenerator {
public:
  virtual ~V3DGenerator() {};
  virtual Vector3D generate() = 0;
};

#endif // V3DGENERATOR_H
