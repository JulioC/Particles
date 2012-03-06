#ifndef V3DGEN_BOX_H
#define V3DGEN_BOX_H

#include "v3dgenerator.h"

class V3DGen_Box : public V3DGenerator {
public:
  V3DGen_Box(const Vector3D &min, const Vector3D &max);
  virtual ~V3DGen_Box();

  virtual bool inside(const Vector3D &point);
  virtual Vector3D point();

protected:
  Vector3D _min;
  Vector3D _range;
};

#endif // V3DGEN_BOX_H
