#include "glwidget.h"

#include <time.h>
#include <math.h>

#include <QKeyEvent>
#include <QTimer>
#include <QVector3D>
#include <QGLShader>
#include <QGLShaderProgram>

#include "color.h"
#include "emitter.h"

#include "renderers/rend_point.h"

#include "initializers/init_color.h"
#include "initializers/init_directioncone.h"
#include "initializers/init_lifetime.h"
#include "initializers/init_radius.h"
#include "initializers/init_speed.h"
#include "initializers/init_speedoffset.h"
#include "initializers/init_positionoffset.h"
#include "initializers/init_positionring.h"

#include "operators/oper_acceleration.h"
#include "operators/oper_decay.h"
#include "operators/oper_drag.h"
#include "operators/oper_fade.h"

GLWidget::GLWidget(QWidget *parent) :
  QGLWidget(parent),
  _camera(),
  _timer(),
  _qtimer(NULL),
  _vertShader(NULL),
  _fragShader(NULL),
  _shaderProgram(NULL),
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
  return QSize(600, 600);
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

  _camera.rotate(30, 30);

  _emitter = new Emitter(Vector3D(0, 0, 0), 0.001, 1024*100 );

  _emitter->renderer(new Rend_Point());

  _emitter->addInitializer(new Init_Lifetime(4, 2));
  _emitter->addInitializer(new Init_Color(Color(200, 30, 0), Color(220, 60, 0)));
  _emitter->addInitializer(new Init_Speed(0.8, 0.8));
  _emitter->addInitializer(new Init_Radius(1.0, 10.0));
  //_emitter->addInitializer(new Init_PositionOffset(Vector3D(-.1, 0, -.1), Vector3D(.1, 0, .1)));
  //_emitter->addInitializer(new Init_PositionRing(Vector3D(0, 0, 0), Vector3D(0, 0, 1), 0.1, 0));
  _emitter->addInitializer(new Init_DirectionCone(Vector3D(0, 0.8, 0), 25, 20));

  _emitter->addOperator(new Oper_Decay());
  _emitter->addOperator(new Oper_Acceleration(Vector3D(0, -0.4, 0)));
  _emitter->addOperator(new Oper_Drag(0.1));
  _emitter->addOperator(new Oper_Fade(0.5));
}

void GLWidget::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glPushMatrix();

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  _camera.apply();

  drawAxis();

  _emitter->draw();

  glPopMatrix();
}

void GLWidget::resizeGL(int w, int h) {
  glViewport(0, 0, w, h);

  glPushMatrix();
  glMatrixMode(GL_PROJECTION); //set the matrix to projection
  glLoadIdentity();
  perspective(75.0, (GLfloat)w / (GLfloat)h, 0.0, 100.0);
  glPopMatrix();
}

void GLWidget::keyPressEvent(QKeyEvent *event) {
  switch(event->key()){
    case Qt::Key_W:
    case Qt::Key_Up:
    break;
  }
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

void GLWidget::drawAxis(float len) {
  glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(len, 0.0, 0.0);
  glEnd();

  glBegin(GL_LINES);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, len, 0.0);
  glEnd();

  glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, len);
  glEnd();
}

void GLWidget::perspective(double fovY, double aspect, double zNear, double zFar) {
  double fW, fH;
  fH = tan(M_PI * fovY / 360) * zNear;
  fW = fH * aspect;
  glFrustum( -fW, fW, -fH, fH, zNear, zFar );
}