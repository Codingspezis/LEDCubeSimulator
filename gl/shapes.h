#ifndef SHAPES_H
#define SHAPES_H

namespace ledcubesimulator {
namespace gl {

class Shapes {

public:
    static void DrawCubeF(float x1, float y1, float z1, float x2, float y2, float z2);

protected:
    static void swapF(float *a, float *b);

};

} // end of namespace gl
} // end of namespace ledcubesimulator

#endif // SHAPES_H
