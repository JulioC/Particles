#ifndef V3DGEN_generate_H
#define V3DGEN_generate_H

#include "v3dgenerator.h"

class V3DGen_generate : public V3DGenerator {
public:
  V3DGen_generate(const Vector3D &position);
  virtual ~V3DGen_generate();

  virtual Vector3D generate();

protected:
  Vector3D _position;
};

#endif // V3DGEN_generate_H
