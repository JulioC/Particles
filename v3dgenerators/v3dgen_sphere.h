#ifndef V3DGEN_SPHERE_H
#define V3DGEN_SPHERE_H

#include "v3dgenerator.h"

class V3DGen_Sphere : public V3DGenerator {
public:
  V3DGen_Sphere(const Vector3D &center, float radiusMin = 0, float radiusMax = 1);
  virtual ~V3DGen_Sphere();

  virtual Vector3D point();

protected:
  Vector3D _center;

  float _radiusMin;
  float _radiusRange;

  static const float TWOPI;
};

#endif // V3DGEN_SPHERE_H
