#ifndef ZONE_SPHERE_H
#define ZONE_SPHERE_H

#include "vector3d.h"
#include "zone.h"

class Zone_Sphere : public Zone {
public:
  Zone_Sphere(const Vector3D &center, float radiusMin, float radiusMax);
  virtual ~Zone_Sphere();

  virtual bool inside(const Vector3D &point);
  virtual Vector3D point();

protected:
  Vector3D _center;

  float _radiusMin;
  float _radiusRange;

  static const float TWOPI;
};

#endif // ZONE_SPHERE_H
