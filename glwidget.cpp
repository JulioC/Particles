#include "glwidget.h"

#include <QTimer>

#include "emitter.h"
#include "dummyrenderer.h"

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent),
    _timer(NULL),
    _elapsedTimer(NULL),
    _lastFrameTime(0),
    _emitter(NULL) {
}

GLWidget::~GLWidget() {
    if(_timer) delete _timer;
    if(_elapsedTimer) delete _elapsedTimer;
    if(_emitter) delete _emitter;
}

QSize GLWidget::minimumSizeHint() const {
    return QSize(80, 60);
}

QSize GLWidget::sizeHint() const {
    return QSize(800, 600);
}

void GLWidget::animate()
{
    int current = _elapsedTimer->elapsed();
    int elapsed = (float)(current - _lastFrameTime);
    _lastFrameTime = current;

    _emitter->update(elapsed);

    updateGL();
}

void GLWidget::initializeGL() {
    glClearColor(.0, .0, .0, 1.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    // Create the elapsed timer
    _elapsedTimer = new QElapsedTimer();
    _elapsedTimer->start();

    // Fire the animation timer
    if(_timer != NULL) delete _timer;
    _timer = new QTimer(this);
    connect(_timer, SIGNAL(timeout()), this, SLOT(animate()));
    _timer->start(0);

    //@TODO: do time management in a better way

    _emitter = new Emitter(Vector4D(), Vector4D(1, 1, 1, 1));
    _emitter->renderer(new DummyRenderer());
}

void GLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    _emitter->draw();
}

void GLWidget::resizeGL(int w, int h) {
    glViewport(0, 0, (GLuint) w, (GLuint) h);
}
