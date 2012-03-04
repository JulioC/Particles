#ifndef VECTOR4D_H
#define VECTOR4D_H

//@TODO: change Vector4D for Vector3D

// We don't need more precision than float
typedef float vec_t;

/**
 * 4D Vector implementation based on Valve's
 * (I know, don't reinvent the well, we have QVector*D...)
 */
class Vector4D {
public:
  // Public access to properties
  vec_t x, y, z, w;

  // Constructors
  Vector4D(void);
  Vector4D(vec_t X, vec_t Y, vec_t Z, vec_t W = 0);
  Vector4D(const vec_t *array);

  // Copy
  Vector4D(const Vector4D &other);
  Vector4D& operator=(const Vector4D &other);
  void toArray(vec_t *dst);

  // Access
  vec_t& operator[](int index);

  // Comparassion
  bool operator==(const Vector4D &other) const;
  bool operator!=(const Vector4D &other) const;

  // Arithmetic assignment
  Vector4D& operator+=(const Vector4D &v);
  Vector4D& operator-=(const Vector4D &v);
  Vector4D& operator*=(const Vector4D &v);
  Vector4D& operator*=(vec_t val);
  Vector4D& operator/=(const Vector4D &v);
  Vector4D& operator/=(vec_t val);

  // Arithmetic
  Vector4D operator+(const Vector4D &v) const;
  Vector4D operator-(const Vector4D &v) const;
  Vector4D operator*(const Vector4D &v) const;
  Vector4D operator*(vec_t val) const;
  Vector4D operator/(const Vector4D &v) const;
  Vector4D operator/(vec_t val) const;

  // Geometric methods
  vec_t length() const;

  void normalize();
  Vector4D normalized() const;

  vec_t dot(const Vector4D &v) const;
  Vector4D cross(const Vector4D &v) const;

};

#endif // VECTOR4D_H
