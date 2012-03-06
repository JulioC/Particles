#ifndef V3DGEN_POINT_H
#define V3DGEN_POINT_H

#include "v3dgenerator.h"

class V3DGen_Point : public V3DGenerator {
public:
  V3DGen_Point(const Vector3D &position);
  virtual ~V3DGen_Point();

  virtual Vector3D point();

protected:
  Vector3D _position;
};

#endif // V3DGEN_POINT_H
