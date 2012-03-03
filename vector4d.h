#ifndef VECTOR4D_H
#define VECTOR4D_H

// We don't need more precision than float
typedef float vec_t;

/**
 * 4D Vector
 * Implementation based on Valve's
 */
class Vector4D {
public:
  // Public access to properties
  vec_t x, y, z, w;

  // Constructors
  Vector4D(void);
  Vector4D(vec_t X, vec_t Y, vec_t Z, vec_t W);
  Vector4D(const vec_t *array);

  // Copy
  Vector4D(const Vector4D &other);
  Vector4D& operator=(const Vector4D &other);
  void toArray(vec_t *dst);

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
  Vector4D operator+(const Vector4D &v);
  Vector4D operator-(const Vector4D &v);
  Vector4D operator*(const Vector4D &v);
  Vector4D operator*(vec_t val);
  Vector4D operator/(const Vector4D &v);
  Vector4D operator/(vec_t val);

  //@TODO: Implement other Vector methods (length, normalize, etc)
};

#endif // VECTOR4D_H
