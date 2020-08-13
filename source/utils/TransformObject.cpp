#include <algorithm>
#include "TransformObject.h"

// convert 0-360 to 0-512
int TransformObject::rotate(int angle) {
    // reduce the angle
    angle = angle % 360;
    // force it to be the positive remainder, so that 0 <= angle < 360
    double _angle = angle;

    int old_max = 360;
    int new_max = 512;

    return (_angle / old_max) * new_max;
}

// convert 0-800% to 0-64-512 (64 = 100%)
int TransformObject::scale(int value) {
    double _value = std::clamp(value, 0, 800);

    int old_max = 800;
    int new_max = 512;

    return (_value / old_max) * new_max;
}