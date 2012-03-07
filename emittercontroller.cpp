#include "emittercontroller.h"
#include "ui_emittercontroller.h"

#include "glwidget.h"

#include "color.h"
#include "emitter.h"

#include "initializers/init_color.h"
#include "initializers/init_direction.h"
#include "initializers/init_lifetime.h"
#include "initializers/init_position.h"
#include "initializers/init_radius.h"
#include "initializers/init_speed.h"
#include "initializers/init_speedoffset.h"

#include "operators/oper_acceleration.h"
#include "operators/oper_decay.h"
#include "operators/oper_drag.h"
#include "operators/oper_fade.h"

#include "v3dgenerators/v3dgen_box.h"
#include "v3dgenerators/v3dgen_cone.h"
#include "v3dgenerators/v3dgen_cylinder.h"
#include "v3dgenerators/v3dgen_point.h"
#include "v3dgenerators/v3dgen_sphere.h"

#include "colorgenerators/colorgen_constant.h"
#include "colorgenerators/colorgen_range.h"

EmitterController::EmitterController(QWidget *parent, GLWidget *glwidget) :
  QWidget(parent),
  ui(new Ui::EmitterController),
  _emitterIndex(0),
  _emitter(NULL),
  _glwidget(glwidget),
  _type(TYPE_WATER),
  _color(255, 255, 255, 1),
  _frequency(0.01),
  _position(0, 0, 0),
  _direction(0, 1, 0) {
  ui->setupUi(this);
  createEmitter();
}

EmitterController::~EmitterController() {
  if(_emitter) {
    _glwidget->removeEmitter(_emitterIndex);
    delete _emitter;
  }
  delete ui;
}

void EmitterController::setType(emitter_type type) {
  _type = type;
  if(type == TYPE_CUSTOM) {
    setEnabled(true);
  }
  else {
    setEnabled(false);
  }
  createEmitter();
}

void EmitterController::createEmitter() {
  Emitter *emitter;

  //@TODO: everything is leaking here :-(

  switch(_type) {
    case TYPE_SMOKE:
      emitter = new Emitter(Vector3D(0, 0, 0), 0.01 );

      emitter->addInitializer(new Init_Lifetime(2, 1));
      emitter->addInitializer(new Init_Color(new ColorGen_Range(Color(0, 0, 0), Color(60, 60, 60), true)));
      emitter->addInitializer(new Init_Speed(0.4, 0.8));
      emitter->addInitializer(new Init_Position(new V3DGen_Cylinder(Vector3D(0, 0, 0), Vector3D(0, 1, 0), 0, 0, 0, 0.1)));
      emitter->addInitializer(new Init_Direction(new V3DGen_Cone(Vector3D(0, 0, 0), Vector3D(0, 1, 0), 10, 25)));

      emitter->addOperator(new Oper_Decay());
      emitter->addOperator(new Oper_Acceleration(Vector3D(0, 0.05, 0)));
      emitter->addOperator(new Oper_Fade(1.0));
      break;
    case TYPE_FIRE:
      emitter = new Emitter(Vector3D(0, 0, 0), 0.001 );

      emitter->addInitializer(new Init_Lifetime(2, 1));
      emitter->addInitializer(new Init_Color(new ColorGen_Range(Color(140, 10, 0), Color(240, 80, 20))));
      emitter->addInitializer(new Init_Speed(0.0, 0.2));
      emitter->addInitializer(new Init_Direction(new V3DGen_Point(Vector3D(0, 1, 0))));
      emitter->addInitializer(new Init_Position(new V3DGen_Cylinder(Vector3D(0, 0, 0), Vector3D(0, 1, 0), 0, 0, 0, 0.1)));

      emitter->addOperator(new Oper_Decay());
      emitter->addOperator(new Oper_Acceleration(Vector3D(0, 0.1, 0)));
      break;
    case TYPE_WATER:
      emitter = new Emitter(Vector3D(0, 0, 0), 0.001 );

      emitter->addInitializer(new Init_Lifetime(4, 2));
      emitter->addInitializer(new Init_Color(new ColorGen_Range(Color(40, 40, 100), Color(80, 90, 120), true)));
      emitter->addInitializer(new Init_Speed(0.6, 0.8));
      emitter->addInitializer(new Init_Position(new V3DGen_Cylinder(Vector3D(0, 0, 0), Vector3D(0, 1, 0), 0, 0, 0.005, 0.01)));
      emitter->addInitializer(new Init_Direction(new V3DGen_Cone(Vector3D(0, 0, 0), Vector3D(0, 1, 0), 10, 25)));

      emitter->addOperator(new Oper_Decay());
      emitter->addOperator(new Oper_Acceleration(Vector3D(0, -0.4, 0)));
      emitter->addOperator(new Oper_Drag(0.1));
      emitter->addOperator(new Oper_Fade(0.5));
      break;
    default:
      emitter = new Emitter(_position, _frequency);

      emitter->addInitializer(new Init_Lifetime(4, 2));
      emitter->addInitializer(new Init_Color(new ColorGen_Constant(_color)));
      emitter->addInitializer(new Init_Speed(0.6, 0.8));
      emitter->addInitializer(new Init_Position(new V3DGen_Point(_position)));
      emitter->addInitializer(new Init_Direction(new V3DGen_Cone(Vector3D(0, 0, 0), _direction, 10, 25)));

      emitter->addOperator(new Oper_Decay());
      emitter->addOperator(new Oper_Acceleration(Vector3D(0, -0.4, 0)));
      emitter->addOperator(new Oper_Drag(0.1));
      emitter->addOperator(new Oper_Fade(0.5));
      break;
  }

  if(_emitter) {
    _glwidget->removeEmitter(_emitterIndex);
    delete _emitter;
  }

  _emitterIndex = _glwidget->addEmitter(emitter);
  _emitter = emitter;
}

void EmitterController::setFrequency(double val) {
  _frequency = val;
  setType(TYPE_CUSTOM);
}

void EmitterController::setPosX(double val) {
  _position.x = val;
  setType(TYPE_CUSTOM);
}

void EmitterController::setPosY(double val) {
  _position.y = val;
  setType(TYPE_CUSTOM);
}

void EmitterController::setPosZ(double val) {
  _position.z = val;
  setType(TYPE_CUSTOM);
}

void EmitterController::setDirX(double val) {
  _direction.x = val;
  setType(TYPE_CUSTOM);
}

void EmitterController::setDirY(double val) {
  _direction.y = val;
  setType(TYPE_CUSTOM);
}

void EmitterController::setDirZ(double val) {
  _direction.z = val;
  setType(TYPE_CUSTOM);
}

void EmitterController::setColorR(int val) {
  _color.r = (float)val/255;
  setType(TYPE_CUSTOM);
}

void EmitterController::setColorG(int val) {
  _color.g = (float)val/255;
  setType(TYPE_CUSTOM);
}

void EmitterController::setColorB(int val) {
  _color.b = (float)val/255;
  setType(TYPE_CUSTOM);
}
