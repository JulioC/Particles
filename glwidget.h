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

class Rend_VBO;

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
  Camera *_camera;

  Timer _timer;
  QTimer *_qtimer;

  QGLShader *_vertShader;
  QGLShader *_fragShader;
  QGLShaderProgram *_shaderProgram;

  Rend_VBO *_VBO;

  int _emitterCount;
  Emitter* _emitters[10];

  void initializeGL();
  void paintGL();
  void resizeGL(int width, int height);

  void keyPressEvent(QKeyEvent *event);

  void initShaders();

  void showFPS();
  void drawAxis(float len = 1.0);

  void perspective(double fovY, double aspect, double zNear, double zFar);

};

#endif // GLWIDGET_H
