#ifndef COLOR_H
#define COLOR_H

/**
 * 4D Vector implementation based on Valve's
 * (I know, don't reinvent the well, we have QVector*D...)
 */
class Color {
public:
  // Public access to properties
  float r, g, b, a;

  // Constructors
  Color();
  Color(int r, int g, int b, float a = 1.0);

  // Copy
  Color(const Color &other);
  Color& operator=(const Color &other);
  void toArray(float *dst);

  // Access
  float& operator[](int index);
  const float& operator[](int index) const;
};

#endif // COLOR_H
