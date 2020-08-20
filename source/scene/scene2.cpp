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

    // background.changeBg("nfl");

    font1 = new BMFont("font1", "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book.");
    addChild(font1);

    // mist = new Movieclip("mist", "cat3D", "cat3D");
    // addChild(mist);

    // mist->quickPlay(std::vector<int>{0,1}, 1);
}

void scene2::update() {
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