#ifndef V3DGEN_CYLINDER_H
#define V3DGEN_CYLINDER_H

#include "v3dgenerator.h"

class V3DGen_Cylinder : public V3DGenerator {
public:
  V3DGen_Cylinder(const Vector3D &bottom, const Vector3D &top,
                  float lengthMin = 0, float lengthMax = 1,
                  float radiusMin = 0, float radiusMax = 1);
  virtual ~V3DGen_Cylinder();

  virtual Vector3D generate();

protected:
  Vector3D _bottom;
  Vector3D _axis[3];

  float _lengthMin;
  float _lengthRange;

  float _radiusMin;
  float _radiusRange;

  static const float TWOPI;
};

#endif // V3DGEN_CYLINDER_H
