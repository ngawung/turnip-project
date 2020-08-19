#include <iostream>
#include <fstream>

#include "scene2.hpp"

scene2::scene2() {
    i = 0;
}

void scene2::initialize() {
    std::cout << "Scene 2 init" << std::endl;

    Assets::loadSprite("new/anim", "cat3D", 32, 32);
    Assets::loadPallete("new/anim", "cat3D");

    Assets::loadSprite3D("cat3D", true);
    Assets::loadPallete3D("cat3D");

    NF_CreateTiledBg(get_screen(), 3, "nfl");

    // font1 = new BMFont("font1", "Test font");
    // addChild(font1);

    mist = new Movieclip("mist", "cat3D", "cat3D");
    addChild(mist);

    mist->quickPlay(std::vector<int>{0,1}, 1);
}

void scene2::update() {
    if (SNF::getKeys(Key::UP, KeyPhase::held)) mist->y -= 3;
    if (SNF::getKeys(Key::DOWN, KeyPhase::held)) mist->y += 3;
    if (SNF::getKeys(Key::LEFT, KeyPhase::held)) mist->x -= 3;
    if (SNF::getKeys(Key::RIGHT, KeyPhase::held)) mist->x += 3;

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