#include "glwidget.h"

#include <time.h>
#include <math.h>

#include <QTimer>
#include <QVector3D>
#include <QGLShader>
#include <QGLShaderProgram>

#include "emitter.h"

#include "renderers/rend_point.h"

#include "initializers/init_color.h"
#include "initializers/init_lifetime.h"
#include "initializers/init_speed.h"
#include "initializers/init_speedoffset.h"
#include "initializers/init_positionoffset.h"

#include "operators/oper_basicphysics.h"
#include "operators/oper_decay.h"

GLWidget::GLWidget(QWidget *parent) :
  QGLWidget(parent),
  _timer(),
  _vertShader(NULL),
  _fragShader(NULL),
  _shaderProgram(NULL),
  _qtimer(NULL),
  _emitter(NULL) {
  // Set the animation timer
  _qtimer = new QTimer(this);
  connect(_qtimer, SIGNAL(timeout()), this, SLOT(animate()));
  _qtimer->start(10);

  // Fire the internal timer
  _timer.start();
}

GLWidget::~GLWidget() {
  if(_qtimer) delete _qtimer;
  if(_emitter) delete _emitter;
}

QSize GLWidget::minimumSizeHint() const {
  return QSize(80, 60);
}

QSize GLWidget::sizeHint() const {
  return QSize(800, 600);
}

void GLWidget::animate() {
  _timer.update();

  _emitter->update(_timer.elapsed());

  updateGL();
}

void GLWidget::initializeGL() {
  srand(time(NULL));

  glClearColor(.0, .0, .0, 1.0);
  glShadeModel(GL_FLAT);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);

  glEnable( GL_BLEND );
  glBlendFunc( GL_SRC_ALPHA, GL_ONE );

  // Eye candy? :3
  glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
  glHint( GL_POINT_SMOOTH_HINT, GL_NICEST );

  initShaders();

  _emitter = new Emitter(Vector4D(0, 0, 0), Vector4D(.2, 1, 0), 0.002);

  _emitter->renderer(new Rend_Point());

  _emitter->addInitializer(new Init_Lifetime(3, 1.5));
  _emitter->addInitializer(new Init_Color(Vector4D(140, 150, 200, 255), Vector4D(160, 200, 255, 255)));
  _emitter->addInitializer(new Init_Speed(0.8, 1.4));
  _emitter->addInitializer(new Init_PositionOffset(Vector4D(-.1, 0, -.1), Vector4D(.1, 0, .1)));

  _emitter->addOperator(new Oper_Decay());
  _emitter->addOperator(new Oper_BasicPhysics(Vector4D(0, -1., 0), 0.1));
}

void GLWidget::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glPushMatrix();
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  _emitter->draw();
  glPopMatrix();
}

void GLWidget::resizeGL(int w, int h) {
  glViewport(0, 0, w, h);

  /*glPushMatrix();
  glMatrixMode(GL_PROJECTION); //set the matrix to projection
  glLoadIdentity();
  perspective(75.0, (GLfloat)w / (GLfloat)h, 0.0, 100.0);
  glPopMatrix();*/
}

void GLWidget::initShaders() {
  _vertShader = new QGLShader(QGLShader::Vertex);
  _fragShader = new QGLShader(QGLShader::Fragment);

  if(!_vertShader->compileSourceFile(":/vshader.glsl")) {
    qWarning() << _vertShader->log();
  }

  if(!_fragShader->compileSourceFile(":/fshader.glsl")) {
    qWarning() << _fragShader->log();
  }

  _shaderProgram = new QGLShaderProgram();
  _shaderProgram->addShader(_vertShader);
  _shaderProgram->addShader(_fragShader);

  if(!_shaderProgram->link()) {
    qWarning() << _shaderProgram->log();
  }
  else {
    _shaderProgram->bind();
  }
}

void GLWidget::showFPS() {
  qDebug() << "FPS: " << _timer.fps();
}

void GLWidget::perspective(double fovY, double aspect, double zNear, double zFar) {
  const double pi = 3.1415926535897932384626433832795;
  double fW, fH;
  fH = tan( fovY / 360 * pi ) * zNear;
  fW = fH * aspect;
  glFrustum( -fW, fW, -fH, fH, zNear, zFar );
}