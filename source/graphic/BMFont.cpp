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
    if (visible) NF_WriteText(0, 1, x / 8, y / 8, text.c_str());

    BMFont::DisplayObject::preUpdate();
}

void BMFont::destroy() {

}

// static

void BMFont::defineRGB(uint16_t id, RGB rgb) {
    // convert rgb
    rgb.convert(ColorMode::NFLib);

    // for now screen 0 and layer 1 only
    NF_DefineTextColor(0, 1, id, rgb.r, rgb.g, rgb.b);
}

void BMFont::defineHex(uint16_t id, uint16_t hex) {
    // get rgb from hex
    RGB rgb;
    rgb.setFromHex(hex);

    // convert rgb
    rgb.convert(ColorMode::NFLib);

    // for now screen 0 and layer 1 only
    NF_DefineTextColor(0, 1, id, rgb.r, rgb.g, rgb.b);
}