#include "vector4d.h"

//-----------------------------------------------------------------------------
// Constructor
//-----------------------------------------------------------------------------

Vector4D::Vector4D(void) {
    x = y = z = w = .0;
}

Vector4D::Vector4D(vec_t X, vec_t Y, vec_t Z, vec_t W) {
    x = X;
    y = Y;
    z = Z;
    w = W;
}

Vector4D::Vector4D(const vec_t *array) {
    x = array[0];
    y = array[1];
    z = array[2];
    w = array[3];
}

//-----------------------------------------------------------------------------
// Copy
//-----------------------------------------------------------------------------

Vector4D::Vector4D(const Vector4D &other) {
    x = other.x;
    y = other.y;
    z = other.z;
    w = other.w;
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
// Comparassion
//-----------------------------------------------------------------------------

bool Vector4D::operator==(Vector4D const &other) const {
    return (other.x == x) && (other.y == y) && (other.z == z) && (other.w == w);
}

bool Vector4D::operator!=(Vector4D const &other) const {
    return (other.x != x) || (other.y != y) || (other.z != z) || (other.w != w);
}

//-----------------------------------------------------------------------------
// Arithmetic
//-----------------------------------------------------------------------------

Vector4D& Vector4D::operator+=(const Vector4D &other) {
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;
    return *this;
}

Vector4D& Vector4D::operator-=(const Vector4D &other) {
    x -=other.x;
    y -=other.y;
    z -= other.z;
    w -= other.w;
    return *this;
}

Vector4D& Vector4D::operator*=(vec_t val) {
    x *= val;
    y *= val;
    z *= val;
    w *= val;
    return *this;
}

Vector4D& Vector4D::operator*=(const Vector4D &other) {
    x *= other.x;
    y *= other.y;
    z *= other.z;
    w *= other.w;
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

Vector4D& Vector4D::operator/=(const Vector4D &other) {
    x /= other.x;
    y /= other.y;
    z /= other.z;
    w /= other.w;
    return *this;
}
