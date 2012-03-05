#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>

#include "camera.h"
#include "timer.h"
#include "vector3d.h"

class Emitter;

class QTimer;

class QGLShader;
class QGLShader;
class QGLShaderProgram;

class GLWidget : public QGLWidget {
  Q_OBJECT

public:
  explicit GLWidget(QWidget *parent = 0);
  virtual ~GLWidget();

  QSize minimumSizeHint() const;
  QSize sizeHint() const;

  float getFPS() { return _timer.fps(); }

public slots:
  virtual void animate();

protected:
  Timer _timer;

  QGLShader *_vertShader;
  QGLShader *_fragShader;
  QGLShaderProgram *_shaderProgram;

  void initializeGL();
  void paintGL();
  void resizeGL(int width, int height);

  void initShaders();

  void showFPS();

  void perspective(double fovY, double aspect, double zNear, double zFar);

private:
  QTimer *_qtimer;

  Emitter* _emitter;
};

#endif // GLWIDGET_H
