#include "scene3.hpp"

scene3::scene3() {

}

void scene3::initialize() {
    // videoSetMode(MODE_0_2D);
	// consoleInit(NULL, consoleGetDefault()->bgLayer, BgType_Text4bpp, BgSize_T_256x256, consoleGetDefault()->mapBase, consoleGetDefault()->gfxBase, true, true);

    std::cout << "scene 3 initialized" << std::endl;

    Assets::loadSprite("number", "cat", 32, 32);
    Assets::loadPallete("number", "cat");

    Assets::loadSprite2D("cat", true);
    Assets::loadPallete2D("cat");

    // NF_CreateTiledBg(get_screen(), 3, "nfl");

    font1 = new BMFont("font1", "Screen 1");
    addChild(font1);

    // mist = new Movieclip2D("mist", "cat", "cat");
    // addChild(mist);

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