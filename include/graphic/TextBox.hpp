#pragma once

#include "BMFont.hpp"

class TextBox : public BMFont {
    public:
        uint8_t width;
        uint8_t height;
        uint8_t skip;
    private:
        uint16_t _index;
        uint8_t _skip;
        std::string _fullText;
        std::string _currentText;
    
    public:
        TextBox(std::string name, std::string text, uint8_t width, uint8_t height);
        void preUpdate() override;

    private:
};