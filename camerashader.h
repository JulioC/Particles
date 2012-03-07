#ifndef CAMERASHADER_H
#define CAMERASHADER_H

#include "camera.h"
#include "vector3d.h"

class QGLShaderProgram;

class CameraShader : public Camera {
public:
  CameraShader(QGLShaderProgram *shaderProgram);
  virtual ~CameraShader();

  virtual void apply();

protected:
  QGLShaderProgram *_shaderProgram;
};

#endif // CAMERASHADER_H