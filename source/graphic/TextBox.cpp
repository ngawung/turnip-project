#include "TextBox.hpp"

TextBox::TextBox(std::string _name, std::string _text, uint8_t _width, uint8_t _height)
    : BMFont(_name, ""), width(_width), height(_height), skip(1), _index(0), _fullText(_text), _currentText("")
{

}

void TextBox::preUpdate() {
    if (_index < _fullText.size() && _skip > skip) {
        text.push_back(_fullText.at(_index));
        _index++;
        _skip = 0;
    }

    _skip++;

    BMFont::preUpdate();
}