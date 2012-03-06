#include "v3dgen_box.h"

#include "random.h"

V3DGen_Box::V3DGen_Box(const Vector3D &min, const Vector3D &max) :
  V3DGenerator(),
  _min(min),
  _range(max - min) {
}

V3DGen_Box::~V3DGen_Box() {
}

Vector3D V3DGen_Box::generate() {
  float x, y, z;
  x = Random::ranged(_min.x, _range.x);
  y = Random::ranged(_min.y, _range.y);
  z = Random::ranged(_min.z, _range.z);

  return Vector3D(x, y, z);
}
