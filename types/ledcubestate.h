#ifndef LEDCUBESTATE_H
#define LEDCUBESTATE_H

#include <QtGlobal>

namespace ledcubesimulator {
namespace types {

class LEDCubeState {

public:
    LEDCubeState();
    ~LEDCubeState();
    bool led(int x, int y, int z);
    bool bit(int b);
    void setLed(int x, int y, int z, bool state);
    void setBit(int b, bool state);
    void shiftLeft(bool rotate);
    void setData(quint8 *data);

public:
    quint8 *data;

};

} // end of namespace types
} // end of namespace ledcubesimulator

#endif // LEDCUBESTATE_H
