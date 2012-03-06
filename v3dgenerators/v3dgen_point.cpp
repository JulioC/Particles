#include "v3dgen_point.h"

V3DGen_Point::V3DGen_Point(const Vector3D &position) :
  V3DGenerator(),
  _position(position) {
}

V3DGen_Point::~V3DGen_Point() {
}

Vector3D V3DGen_Point::generate() {
  return _position;
}
