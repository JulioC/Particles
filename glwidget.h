#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>

#include "timer.h"

class Emitter;
class QTimer;

class GLWidget : public QGLWidget {
  Q_OBJECT

public:
  explicit GLWidget(QWidget *parent = 0);
  ~GLWidget();

  QSize minimumSizeHint() const;
  QSize sizeHint() const;

public slots:
  void animate();

protected:
  void initializeGL();
  void paintGL();
  void resizeGL(int width, int height);

private:
  Timer _timer;

  QTimer *_qtimer;

  Emitter* _emitter;

  void showFPS();
};

#endif // GLWIDGET_H
