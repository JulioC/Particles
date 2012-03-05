#ifndef WINDOW_H
#define WINDOW_H

#include <QTimer>
#include <QWidget>

#include "glwidget.h"

class GLWidget;

class Window : public QWidget {
  Q_OBJECT

public:
  Window();

public slots:
  void updateFPS();

private:
  GLWidget _glWidget;
  QTimer _qtimer;

};

#endif // WINDOW_H
