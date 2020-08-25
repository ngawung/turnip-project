#include <iostream>
#include <fstream>

#include "scene2.hpp"

scene2::scene2() {
    i = 0;
}

Image* textbox;
Image* namebox;
BMFont* name;
TextBox* text;

void scene2::initialize() {
    std::cout << "Scene 2 init" << std::endl;

    Assets::loadSprite("demo/hud/namebox", "namebox", 128, 16);
    Assets::loadSprite("demo/hud/textbox", "textbox", 256, 64);
    Assets::loadPallete("demo/hud/hud", "hud");

    Assets::loadSprite3D("namebox", false);
    Assets::loadSprite3D("textbox", false);
    Assets::loadPallete3D("hud");

    background.changeBg("nfl2");

    textbox = new Image("textbox", "textbox", "hud");
    textbox->y = 191 - 56;
    addChild(textbox);


    namebox = new Image("namebox", "namebox", "hud");
    namebox->y = textbox->y - 16 -4;
    addChild(namebox);

    name = new BMFont("name", "Your name");
    name->y = namebox->y + 4 + 1;
    name->x = 0;
    addChild(name);

    BMFont::defineHex(0, 1, 0x000000);
    // NF_DefineTextColor(0, 1, 1, 0, 0, 0);
    NF_SetTextColor(0, 1, 1);
    

    text = new TextBox("text", "Testing running text|New line here|More random text over here to|Hellloooooooo.....|Testting...", 256 - 16, 0);
    text->y = textbox->y + 8 + 1;
    text->x = 8;
    text->skip = 3;
    text->enableRunningText = true;
    text->callbackRunningText = []() { std::cout << "running text done" << std::endl; };
    addChild(text);

}

void scene2::update() {
    
}