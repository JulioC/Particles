#include "window.h"

#include <QtGui>

Window::Window() :
  _glWidget(this),
  _qtimer(this) {
  connect(&_qtimer, SIGNAL(timeout()), this, SLOT(updateFPS()));
  _qtimer.start(1000);

  QHBoxLayout *mainLayout = new QHBoxLayout(this);
  mainLayout->addWidget(&_glWidget);
  setLayout(mainLayout);
}

void Window::updateFPS() {
  setWindowTitle(QString("Particles (%1 FPS)").arg((int)_glWidget.getFPS()));
}
