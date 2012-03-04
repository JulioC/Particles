#include "vector4d.h"

#include <math.h>

//-----------------------------------------------------------------------------
// Constructor
//-----------------------------------------------------------------------------

Vector4D::Vector4D(void) :
  x(0),
  y(0),
  z(0),
  w(0) {
  x = y = z = w = .0;
}

Vector4D::Vector4D(vec_t X, vec_t Y, vec_t Z, vec_t W) :
  x(X),
  y(Y),
  z(Z),
  w(W) {
}

Vector4D::Vector4D(const vec_t *array) :
  x(array[0]),
  y(array[1]),
  z(array[2]),
  w(array[3]) {
}

//-----------------------------------------------------------------------------
// Copy
//-----------------------------------------------------------------------------

Vector4D::Vector4D(const Vector4D &other) :
  x(other.x),
  y(other.y),
  z(other.z),
  w(other.w) {
}

Vector4D& Vector4D::operator=(const Vector4D &other) {
  x = other.x;
  y = other.y;
  z = other.z;
  w = other.w;
  return *this;
}

void Vector4D::toArray(vec_t *dst) {
  dst[0] = x;
  dst[1] = y;
  dst[2] = z;
  dst[3] = w;
}

//-----------------------------------------------------------------------------
// Access
//-----------------------------------------------------------------------------

vec_t& Vector4D::operator[](int index) {
  switch(index){
    case 0:
      return x;
    case 1:
      return y;
    case 2:
      return z;
   }

   return w;
}

//-----------------------------------------------------------------------------
// Comparassion
//-----------------------------------------------------------------------------

bool Vector4D::operator==(Vector4D const &other) const {
  return (other.x == x) && (other.y == y) && (other.z == z) && (other.w == w);
}

bool Vector4D::operator!=(Vector4D const &other) const {
  return (other.x != x) || (other.y != y) || (other.z != z) || (other.w != w);
}

//-----------------------------------------------------------------------------
// Arithmetic assignment
//-----------------------------------------------------------------------------

Vector4D& Vector4D::operator+=(const Vector4D &v) {
  x += v.x;
  y += v.y;
  z += v.z;
  w += v.w;
  return *this;
}

Vector4D& Vector4D::operator-=(const Vector4D &v) {
  x -=v.x;
  y -=v.y;
  z -= v.z;
  w -= v.w;
  return *this;
}

Vector4D& Vector4D::operator*=(vec_t val) {
  x *= val;
  y *= val;
  z *= val;
  w *= val;
  return *this;
}

Vector4D& Vector4D::operator*=(const Vector4D &v) {
  x *= v.x;
  y *= v.y;
  z *= v.z;
  w *= v.w;
  return *this;
}

Vector4D& Vector4D::operator/=(vec_t val) {
  //@NOTE: We shall do some checking for 0 here!
  vec_t div = 1.0f / val;
  x *= div;
  y *= div;
  z *= div;
  w *= div;
  return *this;
}

Vector4D& Vector4D::operator/=(const Vector4D &v) {
  x /= v.x;
  y /= v.y;
  z /= v.z;
  w /= v.w;
  return *this;
}

//-----------------------------------------------------------------------------
// Arithmetic
//-----------------------------------------------------------------------------

Vector4D Vector4D::operator+(const Vector4D &v) const {
  return Vector4D(x + v.x, y + v.y, z + v.z, w + v.w);
}

Vector4D Vector4D::operator-(const Vector4D &v) const {
  return Vector4D(x - v.x, y - v.y, z - v.z, w - v.w);
}

Vector4D Vector4D::operator*(vec_t val) const {
  return Vector4D(x * val, y * val, z * val, w * val);
}

Vector4D Vector4D::operator*(const Vector4D &v) const {
  return Vector4D(x * v.x, y * v.y, z * v.z, w * v.w);
}

Vector4D Vector4D::operator/(vec_t val) const {
  //@NOTE: We shall do some checking for 0 here!
  vec_t div = 1.0 / val;
  return Vector4D(x * div, y * div, z * div, w * div);
}

Vector4D Vector4D::operator/(const Vector4D &v) const {
  return Vector4D(x / v.x, y / v.y, z / v.z, w / v.w);
}

//-----------------------------------------------------------------------------
// Geometric
//-----------------------------------------------------------------------------

vec_t Vector4D::length() const {
  return sqrt(x*x + y*y + z*z + w*w);
}

void Vector4D::normalize() {
  vec_t len = length();
  if(len != 0.0) {
    x = x / len;
    y = y / len;
    z = z / len;
    w = w / len;
  }
}

Vector4D Vector4D::normalized() const {
  Vector4D copy = *this;
  copy.normalize();
  return copy;
}

vec_t Vector4D::dot(const Vector4D &v) const {
  return (x*v.x + y*v.y + z*v.z + w*v.w);
}

//@NOTE: threats the vectors as Vector3D
Vector4D Vector4D::cross(const Vector4D &v) const {
  vec_t X = y * v.z - z * v.y ;
  vec_t Y = z * v.x - x * v.z ;
  vec_t Z = x * v.y - y * v.x ;
  vec_t W = w * v.w;

  return Vector4D(X, Y, Z, W);
}