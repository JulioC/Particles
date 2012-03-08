#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>

#include "timer.h"
#include "vector3d.h"

#define MAX_EMITTERS 16
#define MAX_VERTEXES 20000
class QTimer;

class QGLBuffer;
class QGLShader;
class QGLShader;
class QGLShaderProgram;

class Camera;
class Emitter;
class Rend_VBO;

class GLWidget : public QGLWidget {
  Q_OBJECT

public:
  explicit GLWidget(QWidget *parent = 0);
  virtual ~GLWidget();

  QSize minimumSizeHint() const;
  QSize sizeHint() const;

  float getFPS() { return _timer.fps(); }
  int getVertexCount() const;

  int addEmitter(Emitter *emitter);
  void removeEmitter(int index);

public slots:
  virtual void animate();
  void setPitch(int val);
  void setYaw(int val);
  void setRoll(int val);

protected:
  Camera *_camera;

  Timer _timer;
  QTimer *_qtimer;

  QGLShader *_vertShader;
  QGLShader *_fragShader;
  QGLShaderProgram *_shaderProgram;

  Rend_VBO *_renderer;

  int _emitterCount;
  Emitter* _emitters[MAX_EMITTERS];

  void initializeGL();
  void paintGL();
  void resizeGL(int width, int height);

  void initShaders();
  void createAxis();

  void drawAxis(float len = 1.0);

  void projection(int width, int height, float size = 1.2);

  QGLBuffer *_axisVertexes;
  QGLBuffer *_axisColors;


};

#endif // GLWIDGET_H
