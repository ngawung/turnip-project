#pragma once

#include "DisplayObject.hpp"
#include "Color.hpp"

class BMFont : public DisplayObject {
    public:
        std::string text;
        // uint16_t colorId;

    private:
        uint16_t _colorId;
    
    public:
        BMFont(std::string _name, std::string _text);
        void preUpdate() override;
        void destroy() override;

        // static

        void defineRGB(uint8_t _screen, uint16_t id, RGB rgb);
        void defineHex(uint8_t _screen, uint16_t id, uint16_t hex);
    private:
};