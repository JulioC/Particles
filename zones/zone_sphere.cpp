#include "zone_sphere.h"

#include <math.h>

#include "random.h"

const float Zone_Sphere::TWOPI = M_PI * 2;

Zone_Sphere::Zone_Sphere(const Vector3D &center, float radiusMin, float radiusMax) :
  Zone(),
  _center(center),
  _radiusMin(radiusMin),
  _radiusRange(radiusMax - radiusMin) {
}

Zone_Sphere::~Zone_Sphere() {
}

bool Zone_Sphere::inside(const Vector3D &point) {
  Vector3D dist = point - _center;
  float len = dist.length();

  if(len - _radiusMin > _radiusRange) {
    return false;
  }

  return true;
}

Vector3D Zone_Sphere::point() {
  float theta = TWOPI * Random::value();
  float omega = TWOPI * Random::value();

  float sin_omega = sin(omega);

  float x, y, z;
  x = cos(omega);
  y = cos(theta) * sin_omega;
  z = sin(theta) * sin_omega;

  Vector3D res(x, y, z);

  res *= Random::ranged(_radiusMin, _radiusRange);

  return res;
}
