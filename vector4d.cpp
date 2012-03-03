#include "vector4d.h"

inline Vector4D::Vector4D(void) {
    x = y = z = w = .0;
}

inline Vector4D::Vector4D(vec_t X, vec_t Y, vec_t Z, vec_t W) {
    x = X;
    y = Y;
    z = Z;
    w = W;
}

inline Vector4D::Vector4D(const vec_t *array) {
    x = array[0];
    y = array[1];
    z = array[2];
    w = array[3];
}


