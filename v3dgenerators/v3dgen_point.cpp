#include "v3dgen_point.h"

V3DGen_generate::V3DGen_generate(const Vector3D &position) :
  V3DGenerator(),
  _position(position) {
}

V3DGen_generate::~V3DGen_generate() {
}

Vector3D V3DGen_generate::generate() {
  return _position;
}
