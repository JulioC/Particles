#include "window.h"

#include <QtGui>

Window::Window() {
  glWidget = new GLWidget(this);

  QHBoxLayout *mainLayout = new QHBoxLayout(this);
  mainLayout->addWidget(glWidget);
  setLayout(mainLayout);

  setWindowTitle(tr("Particles"));
}
