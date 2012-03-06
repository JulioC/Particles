#include "v3dgen_cone.h"

#include <math.h>

#include "random.h"

const float V3DGen_Cone::TWOPI = M_PI * 2;

V3DGen_Cone::V3DGen_Cone(const Vector3D &center,
              const Vector3D &top,
              float angleMin, float angleMax,
              float radiusMin, float radiusMax) :
  V3DGenerator(),
  _center(center),
  _axis(),
  _angleMin(TWOPI * angleMin / 360),
  _angleRange(TWOPI * (angleMax - angleMin) / 360),
  _radiusMin(radiusMin),
  _radiusRange(radiusMax - radiusMin) {
  // Get our coord axis
  _axis[0] = top;
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

V3DGen_Cone::~V3DGen_Cone() {
}

Vector3D V3DGen_Cone::point() {
  Vector3D res(0, 0, 0);

  float theta = Random::value(TWOPI);
  float omega = Random::ranged(_angleMin, _angleRange);
  float sin_omega = sin(omega);

  res += _axis[0] * cos(omega);
  res += _axis[1] * cos(theta) * sin_omega;
  res += _axis[2] * sin(theta) * sin_omega;

  res.normalize();

  res *= Random::ranged(_radiusMin, _radiusRange);
  res += _center;

  return res;
}
