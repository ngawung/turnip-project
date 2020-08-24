#pragma once

#include "BMFont.hpp"

class TextBox : public BMFont {
    public:
        uint8_t width;
        uint8_t height;
        uint8_t skip;

        bool enableRunningText;
    private:
        uint8_t _skip;
        std::string _fullText;
        
        uint16_t _index;
        
        uint8_t _realX;
        uint8_t _realY;
        uint8_t _realWidth;
        uint8_t _realHeight;
        
        uint8_t _nowX;
        uint8_t _nowY;
        
    public:
        TextBox(std::string name, std::string text, uint8_t width, uint8_t height);
        void initialize() override;
        void preUpdate() override;

        void validate();

        // get && set
        void set_text(std::string text);
        std::string get_text();

    private:
        bool next();
};