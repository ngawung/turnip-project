#include "scene3.hpp"

Movieclip* mist;
BMFont* font1;

scene3::scene3() {

}

void scene3::initialize() {
    std::cout << "scene 3 initialized" << std::endl;

    Assets::load3dSprite("new/anim", "anim", 0, 32, 32, false);
    Assets::load3dPallete("new/anim", "anim", 0);

    // NF_WriteText(SCREEN_0, LAYER_1, 0, 1, "Test 1...2..3..!!");
    // NF_WriteText(SCREEN_0, LAYER_1, 3, 1, "Test 1...2..3..!!");

    font1 = new BMFont("font1", "Test font");
    addChild(font1);

    mist = new Movieclip("mist", "anim", "anim");
    addChild(mist);
    
    mist->quickPlay(std::vector<int>{0,1}, 1);
}

void scene3::update() {

    if (SNF::getKeys(Key::UP, KeyPhase::held)) font1->y -= 3;
    if (SNF::getKeys(Key::DOWN, KeyPhase::held)) font1->y += 3;
    if (SNF::getKeys(Key::LEFT, KeyPhase::held)) font1->x -= 3;
    if (SNF::getKeys(Key::RIGHT, KeyPhase::held)) font1->x += 3;

    if (SNF::getKeys(Key::A, KeyPhase::held)) {
        mist->scaleX += 5;
        mist->scaleY += 5;
    }
    
    if (SNF::getKeys(Key::B, KeyPhase::held)) {
        mist->scaleX -= 5;
        mist->scaleY -= 5;
    }

    if (SNF::getKeys(Key::X, KeyPhase::held)) mist->rotation += 5;
    if (SNF::getKeys(Key::Y, KeyPhase::held)) mist->rotation -= 5;
    
    if (SNF::getKeys(Key::R, KeyPhase::held)) mist->delay += 1;
    if (SNF::getKeys(Key::L, KeyPhase::held)) mist->delay -= 1;

}