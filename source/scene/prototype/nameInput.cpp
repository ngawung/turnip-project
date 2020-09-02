#include "prototype/nameInput.hpp"

namespace nameInputVar {
    STween::STween<int16_t> tween;

    Image* key_corner1;
    Image* key_corner2;
    Image* key_corner3;
    Image* key_corner4;
    Image* key_box;

    Image* name_corner1;
    Image* name_corner2;
    Image* name_box;
}

nameInput::nameInput() {

}

void nameInput::initialize() {
    using namespace nameInputVar;

    // preload assets
    Assets::loadSprite("demo/hud/ui/corner1", "corner1", 16, 16);
    Assets::loadSprite("demo/hud/ui/box1", "box1", 16, 16);
    Assets::loadSprite("demo/hud/ui/corner2", "corner2", 16, 32);
    Assets::loadSprite("demo/hud/ui/box2", "box2", 16, 16);
    Assets::loadPallete("demo/hud/ui/ui", "ui");

    Assets::loadSprite3D("corner1", false);
    Assets::loadSprite3D("box1", false);
    Assets::loadSprite3D("corner2", false);
    Assets::loadSprite3D("box2", false);
    Assets::loadPallete3D("ui");

    Assets::loadSprite("new/mist", "mist", 64, 128);
    Assets::loadPallete("new/mist", "mist");

    Assets::loadSprite3D("mist", false);
    Assets::loadPallete3D("mist");

    background.changeBg("nfl2");

    Image* mist = new Image("mist", "mist", "mist");
    mist->polygonId = 62;
    mist->alpha = 80;
    addChild(mist);

    Image* mist2 = new Image("mist", "mist", "mist");
    mist2->x = mist2->y = 30;
    addChild(mist2);
}

void nameInput::update() {
    using namespace nameInputVar;

    if (SNF::getKeys(Key::A, KeyPhase::held)) getChildByName("mist")->alpha += 1;
    if (SNF::getKeys(Key::B, KeyPhase::held)) getChildByName("mist")->alpha -= 1;
}