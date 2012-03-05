#include "vector3d.h"

#include <math.h>

Vector3D::Vector3D(void) :
  x(0),
  y(0),
  z(0) {
  x = y = z = .0;
}

Vector3D::Vector3D(vec_t X, vec_t Y, vec_t Z) :
  x(X),
  y(Y),
  z(Z) {
}

Vector3D::Vector3D(const vec_t *array) :
  x(array[0]),
  y(array[1]),
  z(array[2]) {
}

Vector3D::Vector3D(const Vector3D &other) :
  x(other.x),
  y(other.y),
  z(other.z) {
}

Vector3D& Vector3D::operator=(const Vector3D &other) {
  x = other.x;
  y = other.y;
  z = other.z;
  return *this;
}

void Vector3D::toArray(vec_t *dst) {
  dst[0] = x;
  dst[1] = y;
  dst[2] = z;
}

vec_t& Vector3D::operator[](int index) {
  switch(index){
    case 0:
      return x;
    case 1:
      return y;
   }

   return z;
}

bool Vector3D::operator==(Vector3D const &other) const {
  return (other.x == x) && (other.y == y) && (other.z == z);
}

bool Vector3D::operator!=(Vector3D const &other) const {
  return (other.x != x) || (other.y != y) || (other.z != z);
}

Vector3D& Vector3D::operator+=(const Vector3D &v) {
  x += v.x;
  y += v.y;
  z += v.z;
  return *this;
}

Vector3D& Vector3D::operator-=(const Vector3D &v) {
  x -=v.x;
  y -=v.y;
  z -= v.z;
  return *this;
}

Vector3D& Vector3D::operator*=(vec_t val) {
  x *= val;
  y *= val;
  z *= val;
  return *this;
}

Vector3D& Vector3D::operator*=(const Vector3D &v) {
  x *= v.x;
  y *= v.y;
  z *= v.z;
  return *this;
}

Vector3D& Vector3D::operator/=(vec_t val) {
  //@NOTE: We shall do some checking for 0 here!
  vec_t div = 1.0f / val;
  x *= div;
  y *= div;
  z *= div;
  return *this;
}

Vector3D& Vector3D::operator/=(const Vector3D &v) {
  x /= v.x;
  y /= v.y;
  z /= v.z;
  return *this;
}

Vector3D Vector3D::operator+(const Vector3D &v) const {
  return Vector3D(x + v.x, y + v.y, z + v.z);
}

Vector3D Vector3D::operator-(const Vector3D &v) const {
  return Vector3D(x - v.x, y - v.y, z - v.z);
}

Vector3D Vector3D::operator*(vec_t val) const {
  return Vector3D(x * val, y * val, z * val);
}

Vector3D Vector3D::operator*(const Vector3D &v) const {
  return Vector3D(x * v.x, y * v.y, z * v.z);
}

Vector3D Vector3D::operator/(vec_t val) const {
  //@NOTE: We shall do some checking for 0 here!
  vec_t div = 1.0 / val;
  return Vector3D(x * div, y * div, z * div);
}

Vector3D Vector3D::operator/(const Vector3D &v) const {
  return Vector3D(x / v.x, y / v.y, z / v.z);
}

vec_t Vector3D::length() const {
  return sqrt(x*x + y*y + z*z);
}

void Vector3D::normalize() {
  vec_t len = length();
  if(len != 0.0) {
    x = x / len;
    y = y / len;
    z = z / len;
  }
}

Vector3D Vector3D::normalized() const {
  Vector3D copy = *this;
  copy.normalize();
  return copy;
}

vec_t Vector3D::dot(const Vector3D &v) const {
  return (x*v.x + y*v.y + z*v.z);
}

Vector3D Vector3D::cross(const Vector3D &v) const {
  vec_t X = y * v.z - z * v.y;
  vec_t Y = z * v.x - x * v.z;
  vec_t Z = x * v.y - y * v.x;

  return Vector3D(X, Y, Z);
}