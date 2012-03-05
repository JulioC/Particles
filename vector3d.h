#ifndef VECTOR3D_H
#define VECTOR3D_H

// We don't need more precision than float
typedef float vec_t;

/**
 * Vector implementation based on Valve's
 * (I know, don't reinvent the well, we have QVector*D...)
 */
class Vector3D {
public:
  // Public access to properties
  vec_t x, y, z;

  // Constructors
  Vector3D(void);
  Vector3D(vec_t X, vec_t Y, vec_t Z);
  Vector3D(const vec_t *array);

  // Copy
  Vector3D(const Vector3D &other);
  Vector3D& operator=(const Vector3D &other);
  void toArray(vec_t *dst);

  // Access
  vec_t& operator[](int index);

  // Comparassion
  bool operator==(const Vector3D &other) const;
  bool operator!=(const Vector3D &other) const;

  // Arithmetic assignment
  Vector3D& operator+=(const Vector3D &v);
  Vector3D& operator-=(const Vector3D &v);
  Vector3D& operator*=(const Vector3D &v);
  Vector3D& operator*=(vec_t val);
  Vector3D& operator/=(const Vector3D &v);
  Vector3D& operator/=(vec_t val);

  // Arithmetic
  Vector3D operator+(const Vector3D &v) const;
  Vector3D operator-(const Vector3D &v) const;
  Vector3D operator*(const Vector3D &v) const;
  Vector3D operator*(vec_t val) const;
  Vector3D operator/(const Vector3D &v) const;
  Vector3D operator/(vec_t val) const;

  // Geometric methods
  vec_t length() const;

  void normalize();
  Vector3D normalized() const;

  vec_t dot(const Vector3D &v) const;
  Vector3D cross(const Vector3D &v) const;

};

#endif // VECTOR3D_H
