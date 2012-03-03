#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent) {
}

GLWidget::~GLWidget() {
}

QSize GLWidget::minimumSizeHint() const {
    return QSize(80, 60);
}

QSize GLWidget::sizeHint() const {
    return QSize(800, 600);
}

void GLWidget::initializeGL() {
    glClearColor(.0, .0, .0, 1.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
}

void GLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GLWidget::resizeGL(int w, int h) {
    glViewport(0, 0, (GLuint) w, (GLuint) h);
}
