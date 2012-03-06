#include "zone_cylinder.h"

#include <math.h>

#include "random.h"

const float Zone_Cylinder::TWOPI = M_PI * 2;

Zone_Cylinder::Zone_Cylinder(const Vector3D &bottom, const Vector3D &top, float radiusMin, float radiusMax) :
  Zone(),
  _bottom(bottom),
  _axis(),
  _radiusMin(radiusMin),
  _radiusRange(radiusMax - radiusMin) {
  // Get our coord axis
  _axis[0] = top - bottom;
  _axis[0].normalize();

  if(_axis[0].x == 0) {
    _axis[1] = Vector3D(1, 0, 0);
  }
  else {
    _axis[1] = Vector3D(_axis[0].y, -_axis[0].x, 0);
    _axis[1].normalize();
  }
  _axis[2] = _axis[0].cross(_axis[1]);
  _axis[2].normalize();
}

Zone_Cylinder::~Zone_Cylinder() {
}

bool Zone_Cylinder::inside(const Vector3D &point) {
  //@TODO: implement

  return true;
}

Vector3D Zone_Cylinder::point() {
  Vector3D res(0, 0, 0);

  float theta = Random::value(TWOPI);
  float radius = Random::ranged(_radiusMin, _radiusRange);

  res += _axis[0] * Random::value();
  res += _axis[1] * cos(theta) * radius;
  res += _axis[2] * sin(theta) * radius;

  res += _bottom;

  return res;
}
