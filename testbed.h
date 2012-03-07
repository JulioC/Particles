#ifndef TESTBED_H
#define TESTBED_H

#include <QMainWindow>

namespace Ui {
class TestBed;
}

class TestBed : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit TestBed(QWidget *parent = 0);
    ~TestBed();
    
private:
    Ui::TestBed *ui;
};

#endif // TESTBED_H
