#ifndef VECTOR4D_H
#define VECTOR4D_H

// We don't need more precision than float
typedef float vec_t;

/**
 * 4D Vector
 * Implementation borrowed from Valve
 */
class Vector4D
{
public:
    // Public access to properties
    vec_t x, y, z, w;

    // Constructors
    Vector4D(void);
    Vector4D(vec_t X, vec_t Y, vec_t Z, vec_t W);
    Vector4D(const float *pFloat);
    Vector4D(const Vector4D &);

    // Assignment
    Vector4D& operator=(const Vector4D &);

    // Comparassion
    bool operator==(const Vector4D& v) const;
    bool operator!=(const Vector4D& v) const;

    // Arithmetic
    Vector4D& operator+=(const Vector4D &v);
    Vector4D& operator-=(const Vector4D &v);
    Vector4D& operator*=(const Vector4D &v);
    Vector4D& operator*=(vec_t s);
    Vector4D& operator/=(const Vector4D &v);
    Vector4D& operator/=(vec_t s);

    // Conversion
    void toArray(vec_t *dst);

private:
};

#endif // VECTOR4D_H
