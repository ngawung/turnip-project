#include <iostream>
#include <fstream>

#include "scene2.hpp"

scene2::scene2() {
    i = 0;
}

Image* textbox;
Image* namebox;

void scene2::initialize() {
    std::cout << "Scene 2 init" << std::endl;

    Assets::loadSprite("demo/hud/namebox", "namebox", 128, 16);
    Assets::loadSprite("demo/hud/textbox", "textbox", 256, 64);
    Assets::loadPallete("demo/hud/hud", "hud");

    Assets::loadSprite3D("namebox", false);
    Assets::loadSprite3D("textbox", false);
    Assets::loadPallete3D("hud");

    background.changeBg("nfl");

    textbox = new Image("textbox", "textbox", "hud");
    textbox->y = Stage::height - 56;
    addChild(textbox);

    namebox = new Image("namebox", "namebox", "hud");
    namebox->y = textbox->y - 16 -4;
    addChild(namebox);

}

void scene2::update() {
    
}