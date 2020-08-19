#include "Image2D.hpp"

Image2D::Image2D(std::string name, std::string sprite, std::string pallete)
    : Image(name, sprite, pallete)
{
    _type = "Sprite2D";
}

void Image2D::initialize() {
    NF_CreateSprite(screen, _id, Assets::get_sprite2D(_sprite), Assets::get_pallete2D(_pallete), _x, _y);
}

void Image2D::preUpdate() {
    // visibility update
    if (_visible != visible) {
        NF_ShowSprite(screen, _id, visible);
        _visible = visible;
        if (!_visible) return;
    }

    // position update
    if (_x != x || _y != y) {
        NF_MoveSprite(screen, _id, x, y);
        _x = x;
        _y = y;
    }

    // rotation update
    // males...

    // scaling update
    // males...

    // depth update
    // will be tricky

    Image2D::DisplayObject::update();
}

void Image2D::destroy() {
    NF_DeleteSprite(screen, _id);

    Image2D::DisplayObject::destroy();
}