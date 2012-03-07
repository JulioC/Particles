#ifndef CAMERA_H
#define CAMERA_H

#include "vector3d.h"

class Camera {
public:
  Camera();
  virtual ~Camera();

  virtual void apply();

  virtual void move(const Vector3D &direction);
  virtual void rotate(float pitch, float yaw, float roll = 0.0, bool offset = true);

  virtual void pitch(float value);
  virtual void yaw(float value);
  virtual void roll(float value);

  virtual void move_forwards(float distance);
  virtual void move_right(float distance);

protected:
  Vector3D _position;
  Vector3D _direction;

  float _pitch;
  float _yaw;
  float _roll;
};

#endif // CAMERA_H
