#ifndef LEDCUBEGLWIDGET_H
#define LEDCUBEGLWIDGET_H

#include <QGLWidget>

#include <types/ledcubestate.h>

namespace ledcubesimulator {
namespace gl {

class LEDCubeGLWidget : public QGLWidget
{
    Q_OBJECT

public:
    explicit LEDCubeGLWidget(QWidget *parent = 0);

public slots:
    void showGrid(bool show);
    void showAxes(bool show);
    void showInactiveLEDs(bool inactiveLEDs);
    void setLedSize(float size);
    void setState(quint8 *data);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    static int NormalizeAngle(int a);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

protected:
    int xRot;
    int yRot;
    int zTrans;
    QPoint lastPos;
    QColor backgroundColor;
    QColor ledColor;
    float ledSize;
    bool grid;
    bool axes;
    bool inactiveLEDs;
    types::LEDCubeState state;

};

} // end of namespace gl
} // end of namespace ledcubesimulator

#endif // LEDCUBEGLWIDGET_H
