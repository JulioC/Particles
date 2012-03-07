#include "testbed.h"
#include "ui_testbed.h"

TestBed::TestBed(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::TestBed) {
  ui->setupUi(this);
  ui->emitterspanel->setGLWidget(ui->glwidget);
}

TestBed::~TestBed() {
  delete ui;
}
