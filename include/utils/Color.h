#pragma once

enum ColorMode { Normal, NFLib };

typedef struct RGB {
    int8_t r;
    int8_t g;
    int8_t b;

    void set(int8_t r, int8_t g, int8_t b);
    void setFromHex(uint16_t hex);
    void convert(ColorMode mode);
} RGB;