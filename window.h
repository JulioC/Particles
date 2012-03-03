#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

#include "glwidget.h"

class GLWidget;

class Window : public QWidget {
    Q_OBJECT

public:
    Window();

private:
    GLWidget *glWidget;
    
};

#endif // WINDOW_H
