#include "zone_point.h"

Zone_Point::Zone_Point(const Vector3D &position) :
  Zone(),
  _position(position) {
}

Zone_Point::~Zone_Point() {
}

bool Zone_Point::inside(const Vector3D &point) {
  return _position == point;
}

Vector3D Zone_Point::point() {
  return _position;
}
