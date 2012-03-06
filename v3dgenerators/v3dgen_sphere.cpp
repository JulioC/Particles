#include "v3dgen_sphere.h"

#include <math.h>

#include "random.h"

const float V3DGen_Sphere::TWOPI = M_PI * 2;

V3DGen_Sphere::V3DGen_Sphere(const Vector3D &center, float radiusMin, float radiusMax) :
  V3DGenerator(),
  _center(center),
  _radiusMin(radiusMin),
  _radiusRange(radiusMax - radiusMin) {
}

V3DGen_Sphere::~V3DGen_Sphere() {
}

bool V3DGen_Sphere::inside(const Vector3D &point) {
  Vector3D dist = point - _center;
  float len = dist.length();

  if(len - _radiusMin > _radiusRange) {
    return false;
  }

  return true;
}

Vector3D V3DGen_Sphere::point() {
  float theta = Random::value(TWOPI);
  float omega = Random::value(TWOPI);

  float sin_omega = sin(omega);

  float x, y, z;
  x = cos(omega);
  y = cos(theta) * sin_omega;
  z = sin(theta) * sin_omega;

  Vector3D res(x, y, z);

  res *= Random::ranged(_radiusMin, _radiusRange);

  return res;
}
