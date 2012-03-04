#include "glwidget.h"

#include <time.h>

#include <QTimer>

#include "emitter.h"

#include "renderers/dummyrenderer.h"

#include "initializers/lifetimerandom.h"
#include "initializers/speedoffsetrandom.h"
#include "initializers/positionoffsetrandom.h"

#include "operators/basicphysics.h"
#include "operators/decay.h"

GLWidget::GLWidget(QWidget *parent) :
  QGLWidget(parent),
  _timer(),
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

  _emitter = new Emitter(Vector4D(0, 0, 0), Vector4D(.2, 1, 0), 0.002);

  _emitter->renderer(new DummyRenderer());

  _emitter->addInitializer(new LifetimeRandom(3, 1.5));
  _emitter->addInitializer(new SpeedOffsetRandom(Vector4D(-.1, -.5, 0), Vector4D(.1, 0, .1)));
  _emitter->addInitializer(new PositionOffsetRandom(Vector4D(-.1, 0, -.1), Vector4D(.1, 0, .1)));

  _emitter->addOperator(new Decay());
  _emitter->addOperator(new BasicPhysics(Vector4D(0, -1., 0), 0.1));
}

void GLWidget::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  _emitter->draw();

  showFPS();
}

void GLWidget::resizeGL(int w, int h) {
  glViewport(0, 0, (GLuint) w, (GLuint) h);
}

void GLWidget::showFPS() {
  glColor3ub(222, 160, 0);
  renderText(-.9, .9, .0, QString("FPS: %1").arg(_timer.fps(), 1));
}
