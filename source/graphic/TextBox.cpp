#include "TextBox.hpp"

TextBox::TextBox(std::string _name, std::string _text, uint8_t _width, uint8_t _height)
    : BMFont(_name, ""), width(_width), height(_height), skip(1), _index(0), _fullText(_text), _currentText("")
{
    
}

void TextBox::initialize() {
    validate();

    BMFont::initialize();
}

void TextBox::validate() {
    _currentPosX = x / 8;
    _currentPosY = y / 8;
    std::string space = " ";

    uint8_t realWidth = std::clamp(static_cast<int>((x + width) / 8), 0, 32);
    uint8_t realHeight = std::clamp(static_cast<int>((y + height) / 8), 0, 24);
    uint8_t nowX = _currentPosX;
    uint8_t nowY = _currentPosY;
    int i = 0;

    while (i < _fullText.size()) {
        if (nowY >= realHeight) break;

        if (nowX < realWidth) {
            text.push_back(_fullText.at( i));
            i++;
        } else {
            uint8_t whitespace = ((256/8) - (_currentPosX + nowX)) + _currentPosX + 1;
            std::cout << (int)whitespace << ":" << (int)nowX << "\n";
            for (int i2=0; i2<whitespace; i2++) {
                text.push_back(space.at(0));
            }
            nowX = _currentPosX;
            nowY++;
            continue;
        }

        nowX++;

    }
}

void TextBox::preUpdate() {
    // if (_index < _fullText.size() && _skip > skip) {
    //     uint8_t currentPos = (x / 8) + text.length();
    //     if (currentPos > )
    //     std::cout << static_cast<int>(currentPos) << std::endl;
    //     text.push_back(_fullText.at(_index));
    //     _index++;
    //     _skip = 0;
    // }

    // _skip++;

    BMFont::preUpdate();
}