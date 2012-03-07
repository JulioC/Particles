#ifndef EMITTERCONTROLLER_H
#define EMITTERCONTROLLER_H

#include <QWidget>

#include "color.h"
#include "vector3d.h"

class Emitter;
class GLWidget;

namespace Ui {
class EmitterController;
}

class EmitterController : public QWidget {
  Q_OBJECT

public:
  enum emitter_type {
    TYPE_SMOKE,
    TYPE_FIRE,
    TYPE_WATER,
    TYPE_CUSTOM
  };

  explicit EmitterController(QWidget *parent = 0, GLWidget *glwidget = NULL);
  virtual ~EmitterController();

  void setType(emitter_type type);

public slots:
  void setFrequency(double val);
  void setPosX(double val);
  void setPosY(double val);
  void setPosZ(double val);
  void setDirX(double val);
  void setDirY(double val);
  void setDirZ(double val);
  void setColorR(int val);
  void setColorG(int val);
  void setColorB(int val);
  
private:
  Ui::EmitterController *ui;

  int _emitterIndex;
  Emitter *_emitter;
  GLWidget *_glwidget;

  emitter_type _type;

  float _frequency;
  Color _color;
  Vector3D _position;
  Vector3D _direction;

  void createEmitter();
};

#endif // EMITTERCONTROLLER_H
