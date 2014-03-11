#include "shapes.h"

#include <QtOpenGL>

using namespace ledcubesimulator::gl;

void Shapes::DrawCubeF(float x1, float y1, float z1, float x2, float y2, float z2) {
    if(x1 > x2) swapF(&x1, &x2);
    if(y1 > y2) swapF(&y1, &y2);
    if(z1 > z2) swapF(&z1, &z2);
    glBegin(GL_QUADS);
        // q1
        glVertex3f(x1, y1, z1);
        glVertex3f(x2, y1, z1);
        glVertex3f(x2, y2, z1);
        glVertex3f(x1, y2, z1);
        // q2
        glVertex3f(x1, y1, z2);
        glVertex3f(x2, y1, z2);
        glVertex3f(x2, y2, z2);
        glVertex3f(x1, y2, z2);
        // q3
        glVertex3f(x1, y1, z1);
        glVertex3f(x1, y1, z2);
        glVertex3f(x1, y2, z2);
        glVertex3f(x1, y2, z1);
        // q4
        glVertex3f(x2, y1, z1);
        glVertex3f(x2, y1, z2);
        glVertex3f(x2, y2, z2);
        glVertex3f(x2, y2, z1);
        // q5
        glVertex3f(x1, y1, z1);
        glVertex3f(x2, y1, z1);
        glVertex3f(x2, y1, z2);
        glVertex3f(x1, y1, z2);
        // q6
        glVertex3f(x1, y2, z1);
        glVertex3f(x2, y2, z1);
        glVertex3f(x2, y2, z2);
        glVertex3f(x1, y2, z2);
    glEnd();
}

void Shapes::swapF(float *a, float *b) {
    float buffer = *a;
    *a = *b;
    *b = buffer;
}
