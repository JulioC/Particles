#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QElapsedTimer>

class Emitter;

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
    QTimer* _timer;
    QElapsedTimer* _elapsedTimer;

    int _lastFrameTime;

    Emitter* _emitter;
};

#endif // GLWIDGET_H
