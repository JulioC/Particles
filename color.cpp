#include "color.h"

#include <math.h>

Color::Color() :
  r(1.0),
  g(1.0),
  b(1.0),
  a(1.0) {
}

Color::Color(int r, int g, int b, float a) :
  r((float)r / 255.0),
  g((float)g / 255.0),
  b((float)b / 255.0),
  a(a) {
}

Color::Color(const Color &other) :
  r(other.r),
  g(other.g),
  b(other.b),
  a(other.a) {
}

Color& Color::operator=(const Color &other) {
  r = other.r;
  g = other.g;
  b = other.b;
  a = other.a;
  return *this;
}

void Color::toArray(float *dst) {
  dst[0] = r;
  dst[1] = g;
  dst[2] = b;
  dst[3] = a;
}

float& Color::operator[](int index) {
  switch(index){
    case 0:
      return r;
    case 1:
      return g;
    case 2:
      return b;
   }

   return a;
}

const float& Color::operator[](int index) const {
  switch(index){
    case 0:
      return r;
    case 1:
      return g;
    case 2:
      return b;
   }

   return a;
}