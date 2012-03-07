#ifndef EMITTERSPANEL_H
#define EMITTERSPANEL_H

#include <QVector>
#include <QWidget>

class GLWidget;

class Emitter;
class EmitterController;

namespace Ui {
class EmittersPanel;
}

class EmittersPanel : public QWidget {
  Q_OBJECT

public:
  explicit EmittersPanel(QWidget *parent = 0);
  ~EmittersPanel();

  void setGLWidget(GLWidget *glwidget);

public slots:
  void createFire();
  void createSmoke();
  void createWater();
  void createController();

  void closeTab(int index);

private:
  Ui::EmittersPanel *ui;
  GLWidget *_glwidget;

  EmitterController *addController(QString title);
};

#endif // EMITTERSPANEL_H
