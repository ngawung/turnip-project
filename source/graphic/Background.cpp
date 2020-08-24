#include "Background.hpp"

Background::Background() 
    : DisplayObject("background"), _x(x), _y(x), _visible(visible), _isExist(false)
{

}

void Background::preUpdate() {
    if (_visible != visible && _isExist) {
        if (visible) NF_ShowBg(screen, 3);
        else NF_HideBg(screen, 3);
    }

    if (_x != x && _y != y && _isExist) {
        NF_ScrollBg(screen, 3, x, y);
        _x = x;
        _y = y;
    }

    Background::DisplayObject::preUpdate();
}


void Background::changeBg(const char* name) {
    if (_isExist) {
        NF_DeleteTiledBg(screen, 3);
        NF_CreateTiledBg(screen, 3, name);
    } else {
        NF_CreateTiledBg(screen, 3, name);
    }

    _isExist = true;
}

void Background::removeBg() {
    NF_DeleteTiledBg(screen, 3);
    _isExist = false;
}

void Background::destroy() {
    NF_DeleteTiledBg(screen, 3);

    Background::DisplayObject::destroy();
}

bool Background::isExist() {
    return _isExist;
}