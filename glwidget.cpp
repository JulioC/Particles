#include "glwidget.h"

#include <math.h>

#include <QKeyEvent>
#include <QTimer>
#include <QVector3D>
#include <QGLShader>
#include <QGLShaderProgram>

#include "color.h"
#include "emitter.h"

#include "renderers/rend_point.h"
#include "renderers/rend_sphere.h"
#include "renderers/rend_square.h"

#include "initializers/init_color.h"
#include "initializers/init_direction.h"
#include "initializers/init_lifetime.h"
#include "initializers/init_position.h"
#include "initializers/init_radius.h"
#include "initializers/init_speed.h"
#include "initializers/init_speedoffset.h"

#include "operators/oper_acceleration.h"
#include "operators/oper_decay.h"
#include "operators/oper_drag.h"
#include "operators/oper_fade.h"

#include "v3dgenerators/v3dgen_box.h"
#include "v3dgenerators/v3dgen_cone.h"
#include "v3dgenerators/v3dgen_cylinder.h"
#include "v3dgenerators/v3dgen_point.h"
#include "v3dgenerators/v3dgen_sphere.h"

GLWidget::GLWidget(QWidget *parent) :
  QGLWidget(parent),
  _camera(),
  _timer(),
  _qtimer(NULL),
  _vertShader(NULL),
  _fragShader(NULL),
  _shaderProgram(NULL),
  _emitterCount(0),
  _emitters() {
  // Set the animation timer
  _qtimer = new QTimer(this);
  connect(_qtimer, SIGNAL(timeout()), this, SLOT(animate()));
  _qtimer->start();

  // Fire the internal timer
  _timer.start();
}

GLWidget::~GLWidget() {
  if(_qtimer) delete _qtimer;

  if(_emitterCount > 0) {
    for(int i = 0; i < _emitterCount; i++) {
      delete _emitters[i];
    }
  }
}

QSize GLWidget::minimumSizeHint() const {
  return QSize(80, 60);
}

QSize GLWidget::sizeHint() const {
  return QSize(600, 600);
}

void GLWidget::animate() {
  _timer.update();

  float elapsed = _timer.elapsed();
  for(int i = 0; i < _emitterCount; i++) {
    _emitters[i]->update(elapsed);
  }

  _camera.rotate(0, 36 * elapsed);

  updateGL();
}

void GLWidget::initializeGL() {
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

  _camera.rotate(30, -20);

  /* water */
  _emitters[0] = new Emitter(Vector3D(0, 0, 0), 0.0001 );

  _emitters[0]->renderer(new Rend_Point());

  _emitters[0]->addInitializer(new Init_Lifetime(4, 2));
  _emitters[0]->addInitializer(new Init_Color(Color(40, 40, 100, 0.1), Color(80, 90, 120, 0.8)));
  _emitters[0]->addInitializer(new Init_Speed(0.6, 0.8));
  _emitters[0]->addInitializer(new Init_Radius(2.5, 1.5));
  _emitters[0]->addInitializer(new Init_Position(new V3DGen_Cylinder(Vector3D(0, 0, 0), Vector3D(0, 1, 0), 0, 0, 0.005, 0.01)));
  _emitters[0]->addInitializer(new Init_Direction(new V3DGen_Cone(Vector3D(0, 0, 0), Vector3D(0, 1, 0), 10, 25)));
  // _emitters[0]->addInitializer(new Init_Direction(new V3DGen_Point(Vector3D(0, 1, 0))));

  _emitters[0]->addOperator(new Oper_Decay());
  _emitters[0]->addOperator(new Oper_Acceleration(Vector3D(0, -0.4, 0)));
  _emitters[0]->addOperator(new Oper_Drag(0.1));
  _emitters[0]->addOperator(new Oper_Fade(0.5));

  _emitterCount++;
  /* /water */

  /* fire */ /*
  _emitters[0] = new Emitter(Vector3D(0, 0, 0), 0.0005 );

  _emitters[0]->renderer(new Rend_Point());

  _emitters[0]->addInitializer(new Init_Lifetime(2, 1));
  _emitters[0]->addInitializer(new Init_Color(Color(240, 10, 0), Color(140, 80, 20)));
  _emitters[0]->addInitializer(new Init_Speed(0.1, 0.4));
  _emitters[0]->addInitializer(new Init_Radius(5.0, 2.0));
  _emitters[0]->addInitializer(new Init_PositionOffset(Vector3D(-.1, 0, -.1), Vector3D(.1, 0, .1)));
  _emitters[0]->addInitializer(new Init_DirectionCone(Vector3D(0, 1, 0), 20));

  _emitters[0]->addOperator(new Oper_Decay());
  _emitters[0]->addOperator(new Oper_Acceleration(Vector3D(0, 0.1, 0)));
  _emitters[0]->addOperator(new Oper_Fade(1.0));

  _emitterCount++;

  _emitters[1] = new Emitter(Vector3D(0, 0, 0), 0.0005 );

  _emitters[1]->renderer(new Rend_Point());

  _emitters[1]->addInitializer(new Init_Lifetime(1.5, 0.5));
  _emitters[1]->addInitializer(new Init_Color(Color(180, 180, 0), Color(140, 140, 20)));
  _emitters[1]->addInitializer(new Init_Speed(0.1, 0.4));
  _emitters[1]->addInitializer(new Init_Radius(5.0, 2.0));
  _emitters[1]->addInitializer(new Init_PositionOffset(Vector3D(-.04, 0, -.04), Vector3D(.04, 0, .04)));
  _emitters[1]->addInitializer(new Init_DirectionCone(Vector3D(0, 1, 0), 20));

  _emitters[1]->addOperator(new Oper_Decay());
  _emitters[1]->addOperator(new Oper_Acceleration(Vector3D(0, 0.1, 0)));
  _emitters[1]->addOperator(new Oper_Fade(1.0));

  _emitterCount++;

  _emitters[2] = new Emitter(Vector3D(0, 0.2, 0), 0.02 );

  _emitters[2]->renderer(new Rend_Point());

  _emitters[2]->addInitializer(new Init_Lifetime(2, 1));
  _emitters[2]->addInitializer(new Init_Color(Color(40, 40, 40), Color(40, 40, 40)));
  _emitters[2]->addInitializer(new Init_Speed(0.4, 0.8));
  _emitters[2]->addInitializer(new Init_Radius(20.0, 10.0));
  _emitters[2]->addInitializer(new Init_PositionOffset(Vector3D(-.1, 0, -.1), Vector3D(.1, 0, .1)));
  _emitters[2]->addInitializer(new Init_DirectionCone(Vector3D(0, 1, 0), 35));

  _emitters[2]->addOperator(new Oper_Decay());
  _emitters[2]->addOperator(new Oper_Acceleration(Vector3D(0, 0.05, 0)));
  _emitters[2]->addOperator(new Oper_Fade(1.0));

  _emitterCount++;
  /* /fire */

  /* ? */ /*
  _emitters[0] = new Emitter(Vector3D(0, 0, 0), 0.0002 );

  _emitters[0]->renderer(new Rend_Point());

  _emitters[0]->addInitializer(new Init_Lifetime(4, 2));
  _emitters[0]->addInitializer(new Init_Color(Color(200, 10, 0), Color(140, 80, 20)));
  _emitters[0]->addInitializer(new Init_Speed(0.8, 0.8));
  _emitters[0]->addInitializer(new Init_Radius(2.0, 1.1));
  _emitters[0]->addInitializer(new Init_PositionRing(Vector3D(0, 0, 0), Vector3D(0, 0, 1), 0.2, 0));
  _emitters[0]->addInitializer(new Init_DirectionCone(Vector3D(0, -0.8, 0), 25, 10));

  _emitters[0]->addOperator(new Oper_Decay());
  _emitters[0]->addOperator(new Oper_Acceleration(Vector3D(0, -0.001, 0)));
  _emitters[0]->addOperator(new Oper_Drag(0.1));
  _emitters[0]->addOperator(new Oper_Fade(0.5));

  _emitterCount++;
  /* /? */

  /* stars */ /*
  _emitters[0] = new Emitter(Vector3D(0, 0, 0), 0.05 );

  _emitters[0]->renderer(new Rend_Square());

  _emitters[0]->addInitializer(new Init_Lifetime(2, 1));
  _emitters[0]->addInitializer(new Init_Color(Color(255, 255, 255), Color(255, 255, 255)));
  _emitters[0]->addInitializer(new Init_Speed(0.01, 0.02));
  _emitters[0]->addInitializer(new Init_Radius(0.001, 0.005));
  _emitters[0]->addInitializer(new Init_PositionOffset(Vector3D(-1, -1, -1), Vector3D(1, 1, 1)));
  _emitters[0]->addInitializer(new Init_DirectionCone(Vector3D(0, -0.8, 0), 25, 360));

  _emitters[0]->addOperator(new Oper_Decay());
  _emitters[0]->addOperator(new Oper_Fade(0.5));

  _emitterCount++;
  /* /stars */

  /* ? */ /*
  _emitters[0] = new Emitter(Vector3D(0, 0, 0), 0.01 );

  //_emitters[0]->renderer(new Rend_Point());
  _emitters[0]->renderer(new Rend_Sphere(2));
  //_emitters[0]->renderer(new Rend_Square());

  _emitters[0]->addInitializer(new Init_Lifetime(4, 3));
  _emitters[0]->addInitializer(new Init_Color(Color(200, 200, 255), Color(255, 255, 255)));
  _emitters[0]->addInitializer(new Init_Speed(0, 0));
  _emitters[0]->addInitializer(new Init_Radius(0.01, 0.001));
  _emitters[0]->addInitializer(new Init_PositionRing(Vector3D(0, 0, 0), Vector3D(0, 0, 1), 1));
  _emitters[0]->addInitializer(new Init_PositionOffset(Vector3D(0, 1, 0), Vector3D(0, 1, 0)));
  _emitters[0]->addInitializer(new Init_DirectionCone(Vector3D(0, 1, 0), 360));

  _emitters[0]->addOperator(new Oper_Decay());
  _emitters[0]->addOperator(new Oper_Acceleration(Vector3D(0, -0.2, 0)));
  _emitters[0]->addOperator(new Oper_Fade(1.0));

  _emitterCount++;
  /* /? */
}

void GLWidget::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glPushMatrix();

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  _camera.apply();

  drawAxis();

  for(int i = 0; i < _emitterCount; i++) {
    _emitters[i]->draw();
  }

  glPopMatrix();
}

void GLWidget::resizeGL(int w, int h) {
  glViewport(0, 0, w, h);

  glPushMatrix();
  glMatrixMode(GL_PROJECTION); //set the matrix to projection
  glLoadIdentity();
  perspective(75.0, (GLfloat)w / (GLfloat)h, -10.0, 200.0);
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