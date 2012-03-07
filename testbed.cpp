#include "testbed.h"
#include "ui_testbed.h"

TestBed::TestBed(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::TestBed),
  _qtimer(this) {
  ui->setupUi(this);
  ui->emitterspanel->setGLWidget(ui->glwidget);
  connect(&_qtimer, SIGNAL(timeout()), this, SLOT(updateStatusBar()));
  _qtimer.start(1000);
}

TestBed::~TestBed() {
  delete ui;
}

void TestBed::updateStatusBar() {
  int fps = ui->glwidget->getFPS();
  int vertexes = ui->glwidget->getVertexCount();
  ui->labelStatus->setText(QString("FPS: %1, Vertexes: %2").arg(fps).arg(vertexes));
}
