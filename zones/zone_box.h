#ifndef ZONE_BOX_H
#define ZONE_BOX_H

#include "zone.h"

class Zone_Box : public Zone {
public:
  Zone_Box(const Vector3D &min, const Vector3D &max);
  virtual ~Zone_Box();

  virtual bool inside(const Vector3D &point);
  virtual Vector3D point();

protected:
  Vector3D _min;
  Vector3D _range;
};

#endif // ZONE_BOX_H
