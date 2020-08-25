#pragma once

enum ColorMode { Normal, NFLib };

typedef struct RGB {
    uint8_t r;
    uint8_t g;
    uint8_t b;

    void set(uint8_t r, uint8_t g, uint8_t b);
    void setFromHex(uint16_t hex);
    void convert(ColorMode mode);
} RGB;