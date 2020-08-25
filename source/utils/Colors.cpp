#include <algorithm>
#include <iostream>
#include "Color.hpp"

void RGB::set(uint8_t r, uint8_t g, uint8_t b) {
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
    int old_max = 0;
    int new_max = 0;

    switch (mode) {
        case ColorMode::NFLib:
            old_max = 255;
            new_max = 31;
            break;
        
        case ColorMode::Normal:
            break;
            old_max = 31;
            new_max = 255;
    }

    double _r = std::clamp((int)this->r, 0, old_max);
    double _g = std::clamp((int)this->g, 0, old_max);
    double _b = std::clamp((int)this->b, 0, old_max);

    this->r = (_r * new_max / old_max);
    this->g = (_g * new_max / old_max);
    this->b = (_b * new_max / old_max);
}