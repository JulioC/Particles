#include "v3dgen_point.h"

V3DGen_Point::V3DGen_Point(const Vector3D &position) :
  V3DGenerator(),
  _position(position) {
}

V3DGen_Point::~V3DGen_Point() {
}

bool V3DGen_Point::inside(const Vector3D &point) {
  return _position == point;
}

Vector3D V3DGen_Point::point() {
  return _position;
}
