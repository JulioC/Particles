#include "glwidget.h"

#include <math.h>

#include <QKeyEvent>
#include <QTimer>
#include <QVector3D>
#include <QGLBuffer>
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
  if(_axisVertexes) {
    _axisVertexes->destroy();
    delete _axisVertexes;
  }
  if(_axisColors) {
    _axisColors->destroy();
    delete _axisColors;
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

  createAxis();

  _camera = new CameraShader(_shaderProgram);
  _renderer = new Rend_VBO(MAX_VERTEXES, _shaderProgram);
}

void GLWidget::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  _camera->apply();

  glPointSize(4.0);

  drawAxis();
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

void GLWidget::createAxis() {
  Vector3D v[6];
  Color c[6];

  v[0] = Vector3D(0, 0, 0);
  v[1] = Vector3D(1, 0, 0);
  c[0] = c[1] = Color(255, 0, 0);

  v[2] = Vector3D(0, 0, 0);
  v[3] = Vector3D(0, 1, 0);
  c[2] = c[3] = Color(0, 255, 0);

  v[4] = Vector3D(0, 0, 0);
  v[5] = Vector3D(0, 0, 1);
  c[4] = c[5] = Color(0, 0, 255);

  _axisVertexes = new QGLBuffer(QGLBuffer::VertexBuffer);
  _axisVertexes->create();
  _axisVertexes->bind();
  _axisVertexes->setUsagePattern(QGLBuffer::DynamicDraw);
  _axisVertexes->allocate(v, 6 * sizeof(Vector3D));

  _axisColors = new QGLBuffer(QGLBuffer::VertexBuffer);
  _axisColors->create();
  _axisColors->bind();
  _axisColors->setUsagePattern(QGLBuffer::DynamicDraw);
  _axisColors->allocate(c,  6 * sizeof(Color));
}

void GLWidget::drawAxis(float len) {
  _axisVertexes->bind();
  _shaderProgram->enableAttributeArray("vPosition");
  _shaderProgram->setAttributeBuffer("vPosition", GL_FLOAT, 0, 3, 0);

  _axisColors->bind();
  _shaderProgram->enableAttributeArray("vColor");
  _shaderProgram->setAttributeBuffer("vColor", GL_FLOAT, 0, 4, 0);

  glDrawArrays(GL_LINES, 0, 6);
}

void GLWidget::projection(int width, int height, float size) {
  QMatrix4x4 proj;
  proj.setToIdentity();
  proj.ortho(-size,size, -size,size, -size,size);

  _shaderProgram->setUniformValue("Projection", proj);
}
