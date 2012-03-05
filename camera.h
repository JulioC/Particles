#ifndef CAMERA_H
#define CAMERA_H

#include "vector3d.h"

class Camera {
public:
  Camera();

  void apply();

  void move(const Vector3D &direction);
  void rotate(float pitch, float yaw, float roll = 0.0);

private:
  static const float PI;

  Vector3D _position;
  Vector3D _direction;

  float _pitch;
  float _yaw;
  float _roll;
};

#endif // CAMERA_H