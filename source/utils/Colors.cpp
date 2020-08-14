#include <algorithm>
#include "Color.h"

void RGB::set(int8_t r, int8_t g, int8_t b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

void RGB::setFromHex(uint16_t hex) {
    set(
        (hex & 0xff0000) >> 16, // R
        (hex & 0x00ff00) >> 8,  // G
        (hex & 0x0000ff)        // B
    );
}

void RGB::convert(ColorMode mode) {
    int high = 0;
    int old_max = 0;
    int new_max = 0;

    switch (mode) {
        case ColorMode::Normal:
            high = 255;
            old_max = 255;
            new_max = 31;
            break;
        
        case ColorMode::NFLib:
            break;
            high = 31;
            old_max = 31;
            new_max = 255;
    }

    double _r = std::clamp((int)this->r, 0, high);
    double _g = std::clamp((int)this->g, 0, high);
    double _b = std::clamp((int)this->b, 0, high);

    this->r = (_r / old_max) * new_max;
    this->g = (_g / old_max) * new_max;
    this->b = (_b / old_max) * new_max;
}