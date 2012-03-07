#include "glwidget.h"

#include <math.h>

#include <QKeyEvent>
#include <QTimer>
#include <QVector3D>
#include <QGLShader>
#include <QGLShaderProgram>

#include "color.h"
#include "emitter.h"

#include "camerashader.h"
#include "renderers/rend_vbo.h"

GLWidget::GLWidget(QWidget *parent) :
  QGLWidget(parent),
  _camera(NULL),
  _timer(),
  _qtimer(NULL),
  _vertShader(NULL),
  _fragShader(NULL),
  _shaderProgram(NULL),
  _renderer(NULL),
  _emitterCount(0),
  _emitters() {
  for(int i = 0; i < MAX_EMITTERS; i++) {
    _emitters[i] = NULL;
  }

  // Set the animation timer
  _qtimer = new QTimer(this);
  connect(_qtimer, SIGNAL(timeout()), this, SLOT(animate()));
  _qtimer->start();

  // Fire the internal timer
  _timer.start();
}

GLWidget::~GLWidget() {
  if(_qtimer) {
    delete _qtimer;
  }
}

QSize GLWidget::minimumSizeHint() const {
  return QSize(80, 80);
}

QSize GLWidget::sizeHint() const {
  return QSize(600, 600);
}

int GLWidget::getVertexCount() const {
  return _renderer->vertexCount();
}

int GLWidget::addEmitter(Emitter *emitter) {
  int index;
  for(index = 0; index < MAX_EMITTERS; index++) {
    if(!_emitters[index]) {
      break;
    }
  }

  if(index == MAX_EMITTERS) {
    return -1;
  }

  _emitters[index] = emitter;
  emitter->renderer(_renderer);

  return index;
}

void GLWidget::removeEmitter(int index) {
  if(_emitters[index]) {
    _emitters[index] = NULL;
  }
}

void GLWidget::animate() {
  _timer.update();

  float elapsed = _timer.elapsed();
  for(int i = 0; i < MAX_EMITTERS; i++) {
    if(_emitters[i]) {
      _emitters[i]->update(elapsed);
    }
  }

  updateGL();
}

void GLWidget::setPitch(int val) {
  _camera->pitch(val);
}

void GLWidget::setYaw(int val) {
  _camera->yaw(val);
}

void GLWidget::setRoll(int val) {
  _camera->roll(val);
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

  _camera = new CameraShader(_shaderProgram);
  _renderer = new Rend_VBO(MAX_VERTEXES, _shaderProgram);
}

void GLWidget::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  _camera->apply();

  drawAxis();

  glPointSize(4.0);

  _renderer->clear();
  for(int i = 0; i < MAX_EMITTERS; i++) {
    if(_emitters[i]) {
      _emitters[i]->draw();
    }
  }
  _renderer->draw();
}

void GLWidget::resizeGL(int w, int h) {
  projection(w, h);
  glViewport(0, 0, w, h);
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

void GLWidget::drawAxis(float len) {
  //@TODO: we should use VBO here

  glColor3f(0.4, 0.4, 0.4);

  glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(len, 0.0, 0.0);
  glEnd();

  glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, len, 0.0);
  glEnd();

  glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, len);
  glEnd();
}

void GLWidget::projection(int width, int height, float size) {
  QMatrix4x4 proj;
  proj.setToIdentity();
  proj.ortho(-size,size, -size,size, -size,size);

  _shaderProgram->setUniformValue("Projection", proj);
}
