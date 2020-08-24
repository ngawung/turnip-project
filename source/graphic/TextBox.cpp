#include "TextBox.hpp"

TextBox::TextBox(std::string _name, std::string _text, uint8_t _width = 0, uint8_t _height = 0)
    : BMFont(_name, ""), width(_width), height(_height), skip(1), enableRunningText(false), _skip(0),  _fullText(_text)
{
    
}

void TextBox::initialize() {
    // get real x/y
    _realX = x / 8;
    _realY = y / 8;

    // get real w/h
    if (width == 0) _realWidth = 32;
    else _realWidth = std::clamp(static_cast<int>((x + width) / 8), 0, 32);
    
    if (height == 0) _realHeight = 24;
    else _realHeight = std::clamp(static_cast<int>((y + height) / 8), 0, 24);

    // draw text
    validate();

    BMFont::initialize();
}

void TextBox::validate() {
    // reset text
    text = "";
    _index = 0;

    // reset current index position
    _nowX = _realX;
    _nowY = _realY;

    // return if running text enable
    if (enableRunningText) return;

    // write all text
    while(true) {
        if (!next()) break;
    }
}

void TextBox::preUpdate() {
    if (enableRunningText) {

        if (_index < _fullText.size() && _skip > skip) {
            next();
            _skip = 0;
        }

        _skip++;
    }

    BMFont::preUpdate();
}

bool TextBox::next() {
    // text completed
    if (_index > _fullText.size()) return false;

    // return if line >= height
    if (_nowY >= _realHeight) return false;

    if (_nowX < _realWidth) {
        // check for newline
        if (_fullText.at(_index) == '|') {
            uint8_t whitespace = (32 - (_realX + _nowX)) + _realX + 1;
            for (int i2=0; i2<whitespace; i2++) {
                text.push_back(' ');
            }
            _nowX = _realX;
            _nowY++;
            _index++;
            return true;
        }


        // write per char
        text.push_back(_fullText.at(_index));
        _index++;
    } else {
        // add whitespace to the next line
        uint8_t whitespace = (32 - (_realX + _nowX)) + _realX + 1;
        for (int i2=0; i2<whitespace; i2++) {
            text.push_back(' ');
        }
        _nowX = _realX;
        _nowY++;
        return true;
    }

    _nowX++;
    return true;
}

void TextBox::set_text(std::string text) {
    _fullText = text;
    validate();
}

std::string TextBox::get_text() {
    return _fullText;
}