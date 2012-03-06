#ifndef ZONE_POINT_H
#define ZONE_POINT_H

#include "zone.h"

class Zone_Point : public Zone {
public:
  Zone_Point(const Vector3D &position);
  virtual ~Zone_Point();

  virtual bool inside(const Vector3D &point);
  virtual Vector3D point();

protected:
  Vector3D _position;
};

#endif // ZONE_POINT_H
