#include "ledcubeglwidget.h"

#include <QtOpenGL>

#include <gl/shapes.h>

using namespace ledcubesimulator::gl;

LEDCubeGLWidget::LEDCubeGLWidget(QWidget *parent) :
    QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    xRot = 0;
    yRot = 0;
    zTrans = -12*16;
    backgroundColor.setRgb(0, 0, 0);
    ledColor.setRgb(255, 0, 0);
    showAxes(true);
    showGrid(true);
    showInactiveLEDs(true);
    setLedSize(0.15);
}

void LEDCubeGLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    /**
     * rotation & translation
     */
    glTranslatef(0.0, 0.0, zTrans/16.0);
    glRotatef(xRot/16.0, 1.0, 0.0, 0.0);
    glRotatef(yRot/16.0, 0.0, 1.0, 0.0);
    glTranslatef(-2.0, -2.0, -2.0);

    /**
     * grid
     */
    if(grid){
        glColor3f(0.3, 0.3, 0.3);
        glBegin(GL_LINES);
        for(float i = 0.0; i < 5.0; i += 1.0) {
            for(float j = 0.0; j < 5.0; j += 1.0) {
                glVertex3f(0.0, i, j);
                glVertex3f(4.0, i, j);
                glVertex3f(i, -1.0, j);
                glVertex3f(i,  4.0, j);
                if(!((int)i%4)){
                    glVertex3f(i, j, 0.0);
                    glVertex3f(i, j, 4.0);
                }
            }
        }
        glEnd();
    }

    /**
     * leds
     */
    for(int x = 0; x < 5; x++) {
        for(int y = 0; y < 5; y++) {
            for(int z = 0; z < 5; z++) {
                if(state.led(x, z, y))
                    glColor3f(1.0, 0.0, 0.0);
                else {
                    if(!inactiveLEDs)
                        continue;
                    glColor3f(0.25, 0.1, 0.1);
                }
                Shapes::DrawCubeF(x - ledSize, y - ledSize, z - ledSize, x + ledSize, y + ledSize, z + ledSize);
            }
        }
    }

    /**
     * axes
     */
    if(axes) {
        glBegin(GL_LINES);
            // x
            glColor3f(1.0, 0.0, 0.0);
            glVertex3f(-1.0, -1.0, -1.0);
            glVertex3f( 3.0, -1.0, -1.0);
            // y ^= z
            glColor3f(0.0, 0.0, 1.0);
            glVertex3f(-1.0, -1.0, -1.0);
            glVertex3f(-1.0,  3.0, -1.0);
            // z ^= y
            glColor3f(0.0, 1.0, 0.0);
            glVertex3f(-1.0, -1.0, -1.0);
            glVertex3f(-1.0, -1.0,  3.0);
        glEnd();
    }
}

void LEDCubeGLWidget::initializeGL() {
    qglClearColor(backgroundColor);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_MULTISAMPLE);
}

void LEDCubeGLWidget::resizeGL(int width, int height) {
    float frac = ((float) height) / ((float) width);
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // TODO: make both values depend on display
    glFrustum(-0.5, +0.5, -0.5*frac, +0.5*frac, 1.0, 500.0);
    glMatrixMode(GL_MODELVIEW);
}

int LEDCubeGLWidget::NormalizeAngle(int a) {
    return a%(360*16);
}

void LEDCubeGLWidget::setState(quint8 *data) {
    state.setData(data);
    updateGL();
}

void LEDCubeGLWidget::mousePressEvent(QMouseEvent *event) {
    lastPos = event->pos();
}

void LEDCubeGLWidget::mouseMoveEvent(QMouseEvent *event) {
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();
    xRot = NormalizeAngle(xRot + (dy << 3));
    yRot = NormalizeAngle(yRot + (dx << 3));
    lastPos = event->pos();
    updateGL();
}

void LEDCubeGLWidget::wheelEvent(QWheelEvent *event) {
    zTrans += event->delta() >> 2;
    updateGL();
}

void LEDCubeGLWidget::showGrid(bool show) {
    grid = show;
    updateGL();
}

void LEDCubeGLWidget::showAxes(bool show) {
    axes = show;
    updateGL();
}

void LEDCubeGLWidget::showInactiveLEDs(bool inactiveLEDs) {
    this->inactiveLEDs = inactiveLEDs;
    updateGL();
}

void LEDCubeGLWidget::setLedSize(float size) {
    ledSize=size/2.0;
    updateGL();
}
