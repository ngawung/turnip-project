#include <algorithm>
#include "Image.hpp"

Image::Image(std::string name, std::string sprite, std::string pallete)
    : DisplayObject(name), _sprite(sprite), _pallete(pallete), _x(x), _y(y), _rotation(rotation), _scaleX(scaleX), _scaleY(scaleY), _layer(layer)
{

}

void Image::preUpdate() {
    if (_x != x || _y != y) {
        NF_Move3dSprite(_id, x, y);
        _x = x;
        _y = y;
    }

    if (_rotation != rotation) {
        NF_Rotate3dSprite(_id, 0, 0, TransformObject::rotate(rotation));
        _rotation = rotation;
    }

    if (_scaleX != scaleX || _scaleY != scaleY) {
        NF_Scale3dSprite(_id, TransformObject::scale(scaleX), TransformObject::scale(scaleY));
        _scaleX = scaleX;
        _scaleY = scaleY;
    }

    if (_layer != layer) {
        layer = std::clamp(static_cast<int>(layer), -512, 512);
        NF_3dSpriteSetDeep(_id, -layer);
        _layer = layer;
    }

    Image::DisplayObject::preUpdate();
}

void Image::initialize() {
    NF_Create3dSprite(_id, Assets::getSprite(_sprite), Assets::getSprite(_pallete), x, y);
}

void Image::destroy() {
    NF_Delete3dSprite(_id);

    Image::DisplayObject::destroy();
}