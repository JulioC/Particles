#include "camerashader.h"

#include <math.h>

#include <qgl.h>
#include <QMatrix4x4>
#include <QGLShaderProgram>

CameraShader::CameraShader(QGLShaderProgram *shaderProgram) :
  Camera(),
  _shaderProgram(shaderProgram) {
}

CameraShader::~CameraShader() {
}

void CameraShader::apply() {
  QMatrix4x4 mv;
  mv.setToIdentity();
  // ModelView.rotate(eye, at, up);

  mv.rotate(-_pitch, 1.0, 0.0, 0.0);
  mv.rotate(  -_yaw, 0.0, 1.0, 0.0);
  mv.rotate( -_roll, 0.0, 0.0, 1.0);
  mv.translate(-_position.x, -_position.y, -_position.z);

  _shaderProgram->setUniformValue("ModelView", mv);
}