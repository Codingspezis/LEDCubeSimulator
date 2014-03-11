#include "ledcubestate.h"

using namespace ledcubesimulator::types;

LEDCubeState::LEDCubeState() {
    data = new quint8[16];
    for(int i=0; i<16; i++)
        data[i] = 0;
}

LEDCubeState::~LEDCubeState() {
    delete data;
}

bool LEDCubeState::led(int x, int y, int z) {
    if((x >= 0 && x < 5) &&
       (y >= 0 && y < 5) &&
       (z >= 0 && z < 5)) {
        return bit(x + y*5 + z*25);
    } else return false;
}

bool LEDCubeState::bit(int b) {
    return data[b/8] & (1 << (b%8));
}

void LEDCubeState::setLed(int x, int y, int z, bool state) {
    if((x >= 0 && x < 5) &&
       (y >= 0 && y < 5) &&
       (z >= 0 && z < 5)) {
        setBit(x + y*5 + z*25, state);
    }
}

void LEDCubeState::setBit(int b, bool state) {
    if(state)
        data[b/8] |= (1 << (b%8));
    else
        data[b/8] &= ~(1 << (b%8));
}

void LEDCubeState::shiftLeft(bool rotate) {
    bool msb = data[15] & (1 << 4); // first 3 ms bits are unused
    for(int i=15; i>=0; i--) {
        data[i] <<= 1;
        if((i >= 1 && data[i-1] & (1 << 7)) ||
           (i == 0 && rotate && msb))
            data[i] |= 1;
    }
}

void LEDCubeState::setData(quint8 *data) {
    for(int i=0; i<16; i++)
        this->data[i] = data[i];
}
