#include "epch.hpp"
#include "Image.hpp"

EE::Image::Image(std::string name, std::string gfx, std::string palette, bool isSprite3D = true)
    : Object(name)
{   
    // set type
    if (isSprite3D) _type = ObjectCategory::SPRITE3D;
    else _type = ObjectCategory::SPRITE2D;

    _gfx = gfx;
    _palette = palette;

    x = _x = 0;
    y = _y = 0;
    rotation = _rotation = 0;
    scaleX = _scaleX = 100;
    scaleY = _scaleY = 100;
    layer = _layer = 0;
    visible = _visible = true;
    flip = _flip = false;
    alpha = _alpha = 100;

    initialize();
}

EE::Image::~Image() {

}

void EE::Image::preUpdate() {

}

void EE::Image::initialize() {
    if (_type == ObjectCategory::SPRITE3D) {

    } else {
        // NF_CreateSprite(_screen, _id, Assets::get_sprite2D(_gfx), Assets::get_pallete2D(_palette), _x, _y);
    }
}

void EE::Image::destroy() {
    if (_type == ObjectCategory::SPRITE3D) {

    } else {
        
    }
}

