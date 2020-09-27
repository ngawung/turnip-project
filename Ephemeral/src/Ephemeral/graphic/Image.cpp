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
}

EE::Image::~Image() {

}

void EE::Image::preUpdate() {

}

void EE::Image::initialize() {
    if (_type == ObjectCategory::SPRITE3D) {
        // NF_Create3dSprite(_id,)
    } else {
        // NF_CreateSprite(_screen, _id, Assets::get_sprite2D(_gfx), Assets::get_pallete2D(_palette), _x, _y);
    }

    validate();
}

void EE::Image::validate() {
    if (_type == ObjectCategory::SPRITE3D) {
        // visibility update
        if (_visible != visible) {
            NF_Show3dSprite(_id, visible);
            _visible = visible;
            if (!_visible) return;
        }

        // // update alpha
        // if (_alpha != alpha) {
        //     if (polygonId == 0 && alpha != 100) {
        //         std::cout << "Change polygonId to use alpha" << std::endl;
        //     } else {
        //         std::cout << TransformObject::alpha(alpha) << std::endl;
        //         NF_Blend3dSprite(_id, polygonId, TransformObject::alpha(alpha));
        //         _alpha = alpha;
        //     }
        // }

        // position update
        if (_x != x || _y != y) {
            NF_Move3dSprite(_id, x, y);
            _x = x;
            _y = y;
        }

        // // rotation update
        // if (_rotation != rotation || _flip != flip) {
        //     if (flip) NF_Rotate3dSprite(_id, 0, TransformObject::rotate(180), TransformObject::rotate(rotation));
        //     else NF_Rotate3dSprite(_id, 0, 0, TransformObject::rotate(rotation));
        //     _rotation = rotation;
        //     _flip = flip;
        // }

        // // scaling update
        // if (_scaleX != scaleX || _scaleY != scaleY) {
        //     scaleX = std::clamp(static_cast<int>(scaleX), 0, 800);
        //     scaleY = std::clamp(static_cast<int>(scaleY), 0, 800);
        //     NF_Scale3dSprite(_id, TransformObject::scale(scaleX), TransformObject::scale(scaleY));
        //     _scaleX = scaleX;
        //     _scaleY = scaleY;
        // }

        // // depth update
        // if (_layer != layer) {
        //     layer = std::clamp(static_cast<int>(layer), -512, 512);
        //     NF_3dSpriteSetDeep(_id, -layer);
        //     _layer = layer;
        // }
    } else {
        // NF_CreateSprite(_screen, _id, Assets::get_sprite2D(_gfx), Assets::get_pallete2D(_palette), _x, _y);
    }
}

void EE::Image::destroy() {
    if (_type == ObjectCategory::SPRITE3D) {

    } else {
        
    }
}

