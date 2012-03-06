#ifndef V3DGEN_CONE_H
#define V3DGEN_CONE_H

#include "v3dgenerator.h"

class V3DGen_Cone : public V3DGenerator {
public:
  V3DGen_Cone(const Vector3D &center,
              const Vector3D &top,
              float angleMin = 0, float angleMax = 45,
              float radiusMin = 0, float radiusMax = 1);
  virtual ~V3DGen_Cone();

  virtual Vector3D generate();

protected:
  Vector3D _center;
  Vector3D _axis[3];

  float _angleMin;
  float _angleRange;

  float _radiusMin;
  float _radiusRange;

  static const float TWOPI;
};

#endif // V3DGEN_CONE_H
