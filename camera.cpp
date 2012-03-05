#include "camera.h"

#include <math.h>

#include <qgl.h>

const float Camera::PI = 3.1415265359;

Camera::Camera() :
  _position(0, 0, 0),
  _direction(0, 0, -1),
  _pitch(0),
  _yaw(0),
  _roll(0) {
}

void Camera::apply() {
  glRotatef(-_pitch , 1.0, 0.0, 0.0);
  glRotatef(-_yaw , 0.0, 1.0, 0.0);
  glRotatef(-_roll , 0.0, 0.0, 1.0);
  glTranslatef(-_position.x, -_position.y, -_position.z);
}

void Camera::move(const Vector3D &direction) {
  _position += direction;
}

void Camera::rotate(float pitch, float yaw, float roll) {
  _pitch += pitch;
  _yaw += yaw;
  _roll += roll;
}