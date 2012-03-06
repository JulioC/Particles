#ifndef V3DGENERATOR_H
#define V3DGENERATOR_H

#include "vector3d.h"

class V3DGenerator {
public:
  virtual ~V3DGenerator() {};
  virtual bool inside(const Vector3D &point) = 0;
  virtual Vector3D point() = 0;
};

#endif // V3DGENERATOR_H
