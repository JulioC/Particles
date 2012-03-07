#ifndef TESTBED_H
#define TESTBED_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class TestBed;
}

class TestBed : public QMainWindow
{
  Q_OBJECT

public:
  explicit TestBed(QWidget *parent = 0);
  ~TestBed();

public slots:
  void updateStatusBar();

private:
  Ui::TestBed *ui;
  QTimer _qtimer;
};

#endif // TESTBED_H
