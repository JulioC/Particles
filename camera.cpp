#include "camera.h"

#include <math.h>

#include <qgl.h>

Camera::Camera() :
  _position(0, 0, 0),
  _direction(0, 0, -1),
  _pitch(0),
  _yaw(0),
  _roll(0) {
}

Camera::~Camera() {
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

void Camera::rotate(float pitch, float yaw, float roll, bool offset) {
  if(offset) {
    _pitch += pitch;
    _yaw += yaw;
    _roll += roll;
  }
  else {
    _pitch = pitch;
    _yaw = yaw;
    _roll = roll;
  }

  float pitch_rad = M_PI * _pitch / 180;
  float yaw_rad = M_PI * _yaw / 180;

  //@FIXME: this calculation is wrong
  // We should do matrix multiplying to transform local direction to world coord
  _direction.x = sin(yaw_rad) * pitch_rad;
  _direction.y = sin(pitch_rad);
  _direction.z = cos(yaw_rad) * pitch_rad;
}

void Camera::pitch(float value) {
  rotate(value, _yaw, _roll, false);
}

void Camera::yaw(float value) {
  rotate(_pitch, value, _roll, false);
}

void Camera::roll(float value) {
  rotate(_pitch, _yaw, value, false);
}

void Camera::move_forwards(float distance) {
  Vector3D direction;
  direction.x = _direction.x * distance;
  direction.y = _direction.y * distance;
  direction.z = _direction.z * distance;
  _position += direction;
}

void Camera::move_right(float distance) {
  Vector3D direction;
  direction.x = - _direction.x * distance;
  direction.y = 0.0;
  direction.z = _direction.z * distance;
  _position += direction;
}
