#ifndef ZONE_H
#define ZONE_H

#include "vector3d.h"

class Zone {
public:
  virtual ~Zone() {};
  virtual bool inside(const Vector3D &point) = 0;
  virtual Vector3D point() = 0;
};

#endif // ZONE_H
