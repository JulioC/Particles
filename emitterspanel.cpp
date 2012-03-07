#include "emitterspanel.h"
#include "emittercontroller.h"
#include "ui_emitterspanel.h"

#include "glwidget.h"

EmittersPanel::EmittersPanel(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::EmittersPanel) {
  ui->setupUi(this);
}

EmittersPanel::~EmittersPanel() {
  delete ui;
}

void EmittersPanel::setGLWidget(GLWidget *glwidget) {
  _glwidget = glwidget;
}

void EmittersPanel::createFire() {
  EmitterController *controller = addController("Fire");
  controller->setType(EmitterController::TYPE_FIRE);
}

void EmittersPanel::createSmoke() {
  EmitterController *controller = addController("Smoke");
  controller->setType(EmitterController::TYPE_SMOKE);
}

void EmittersPanel::createWater() {
  EmitterController *controller = addController("Water");
  controller->setType(EmitterController::TYPE_WATER);
}

void EmittersPanel::createController() {
  EmitterController *controller = addController("Custom");
  controller->setType(EmitterController::TYPE_CUSTOM);
}

void EmittersPanel::closeTab(int index) {
  delete ui->tabs->widget(index);
}

EmitterController* EmittersPanel::addController(QString title) {
  EmitterController *controller = new EmitterController(ui->tabs, _glwidget);
  int i = ui->tabs->addTab(controller, title);
  ui->tabs->setCurrentIndex(i);
  return controller;
}

