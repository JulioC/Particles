#ifndef ZONE_CONE_H
#define ZONE_CONE_H

#include "zone.h"

class Zone_Cone : public Zone {
public:
  Zone_Cone(const Vector3D &center,
              const Vector3D &top,
              float angleMin = 0, float angleMax = 45,
              float radiusMin = 0, float radiusMax = 1);
  virtual ~Zone_Cone();

  virtual bool inside(const Vector3D &point);
  virtual Vector3D point();

protected:
  Vector3D _center;
  Vector3D _axis[3];

  float _angleMin;
  float _angleRange;

  float _radiusMin;
  float _radiusRange;

  static const float TWOPI;
};

#endif // ZONE_CONE_H
