#include "scene3.hpp"

Movieclip2D* mist;
BMFont* font1;

scene3::scene3() {

}

void scene3::initialize() {
    videoSetMode(MODE_0_2D);
	//vramSetBankC(VRAM_C_MAIN_BG);

	consoleInit(NULL, consoleGetDefault()->bgLayer, BgType_Text4bpp, BgSize_T_256x256, consoleGetDefault()->mapBase, consoleGetDefault()->gfxBase, true, true);

    std::cout << "scene 3 initialized" << std::endl;

    Assets::loadSprite("number", "cat", 32, 32);
    Assets::loadPallete("number", "cat");

    Assets::loadSprite2D("cat", true);
    Assets::loadPallete2D("cat");

    NF_LoadTiledBg("new/bg", "nfl", 256, 256);
    NF_CreateTiledBg(1, 3, "nfl");

    // Assets::load3dSprite("cat", "anim", 0, 32, 32, false);
    // Assets::load3dPallete("cat", "anim", 0);

    // NF_WriteText(SCREEN_0, LAYER_1, 0, 1, "Test 1...2..3..!!");
    // NF_WriteText(SCREEN_0, LAYER_1, 3, 1, "Test 1...2..3..!!");

    font1 = new BMFont("font1", "Test font");
    addChild(font1);

    mist = new Movieclip2D("mist", "cat", "cat");
    addChild(mist);

    std::cout << mist->x << ":" << mist->y << std::endl;
    
    mist->quickPlay(std::vector<int>{0,1}, 1);
}

void scene3::update() {

    // if (SNF::getKeys(Key::UP, KeyPhase::held)) mist->y -= 3;
    // if (SNF::getKeys(Key::DOWN, KeyPhase::held)) mist->y += 3;
    // if (SNF::getKeys(Key::LEFT, KeyPhase::held)) mist->x -= 3;
    // if (SNF::getKeys(Key::RIGHT, KeyPhase::held)) mist->x += 3;

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
    
    // if (SNF::getKeys(Key::R, KeyPhase::held)) mist->delay += 1;
    // if (SNF::getKeys(Key::L, KeyPhase::held)) mist->delay -= 1;

}