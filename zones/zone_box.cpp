#include "zone_box.h"

#include "random.h"

Zone_Box::Zone_Box(const Vector3D &min, const Vector3D &max) :
  Zone(),
  _min(min),
  _range(max - min) {
}

Zone_Box::~Zone_Box() {
}

bool Zone_Box::inside(const Vector3D &point) {
  //@TODO: implement

  return true;
}

Vector3D Zone_Box::point() {
  float x, y, z;
  x = Random::ranged(_min.x, _range.x);
  y = Random::ranged(_min.y, _range.y);
  z = Random::ranged(_min.z, _range.z);

  return Vector3D(x, y, z);
}
