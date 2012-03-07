/**
 * Particles system implementation using OpenGL
 */
#include <QApplication>

#include "testbed.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  TestBed window;
  window.show();
  return app.exec();
}
