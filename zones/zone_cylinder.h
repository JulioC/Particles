#ifndef ZONE_CYLINDER_H
#define ZONE_CYLINDER_H

#include "zone.h"

class Zone_Cylinder : public Zone {
public:
  Zone_Cylinder(const Vector3D &bottom, const Vector3D &top, float radiusMin = 0, float radiusMax = 1);
  virtual ~Zone_Cylinder();

  virtual bool inside(const Vector3D &point);
  virtual Vector3D point();

protected:
  Vector3D _bottom;
  Vector3D _axis[3];

  float _radiusMin;
  float _radiusRange;

  static const float TWOPI;
};

#endif // ZONE_CYLINDER_H
