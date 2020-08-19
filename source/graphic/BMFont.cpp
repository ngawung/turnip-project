#include "BMFont.hpp"

BMFont::BMFont(std::string _name, std::string _text = "")
    : DisplayObject(_name), text(_text)
{
    _type = "BMFont";
}

void BMFont::preUpdate() {
    x = std::clamp(static_cast<int>(x), 0, 256);
    y = std::clamp(static_cast<int>(y), 0, 192);

    // for now screen 0 and layer 1 only
    if (visible) {
        if (screen == 0) NF_WriteText(screen, 1, x / 8, y / 8, text.c_str());
        else NF_WriteText(screen, 2, x / 8, y / 8, text.c_str()); // use layer 2 instead
    }

    BMFont::DisplayObject::preUpdate();
}

void BMFont::destroy() {

}

// static

void BMFont::defineRGB(uint8_t _screen, uint16_t id, RGB rgb) {
    // convert rgb
    rgb.convert(ColorMode::NFLib);

    // for now screen 0 and layer 1 only
    NF_DefineTextColor(_screen, 1, id, rgb.r, rgb.g, rgb.b);
}

void BMFont::defineHex(uint8_t _screen, uint16_t id, uint16_t hex) {
    // get rgb from hex
    RGB rgb;
    rgb.setFromHex(hex);

    // convert rgb
    rgb.convert(ColorMode::NFLib);

    // for now screen 0 and layer 1 only
    NF_DefineTextColor(_screen, 1, id, rgb.r, rgb.g, rgb.b);
}