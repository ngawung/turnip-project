#include <iostream>
#include <fstream>

#include "scene2.hpp"
#include "Message.hpp"

scene2::scene2() {
    i = 0;
}

Image* textbox;
Image* namebox;
Image* ricardo;
BMFont* name;
TextBox* text;

bool waiting = true;

void scene2::initialize() {
    std::cout << "Scene 2 init" << std::endl;

    Assets::loadSprite("demo/hud/namebox", "namebox", 128, 16);
    Assets::loadSprite("demo/hud/textbox", "textbox", 256, 64);
    Assets::loadPallete("demo/hud/hud", "hud");

    Assets::loadSprite3D("namebox", false);
    Assets::loadSprite3D("textbox", false);
    Assets::loadPallete3D("hud");
    
    Assets::loadSprite("demo/character/ricardo", "ricardo", 128, 256);
    Assets::loadPallete("demo/character/ricardo", "ricardo");
    
    Assets::loadSprite3D("ricardo", false);
    Assets::loadPallete3D("ricardo");

    MSG::initialize();

    background.changeBg("nfl2");

    textbox = new Image("textbox", "textbox", "hud");
    textbox->y = 191 - 56;
    addChild(textbox);


    namebox = new Image("namebox", "namebox", "hud");
    namebox->y = textbox->y - 16 -4;
    addChild(namebox);

    name = new BMFont("name", "Ganteng");
    name->y = namebox->y + 4 + 1;
    name->x = 0;
    addChild(name);

    BMFont::defineHex(get_screen(), 1, 0x000000);
    BMFont::defineRGB(get_screen(), 2, 50, 168, 82);
    BMFont::setColor(get_screen(), 1);

    text = new TextBox("textbox", "", 256 - 16, 0);
    text->y = textbox->y + 8 + 1;
    text->x = 8;
    text->skip = 3;
    text->enableRunningText = true;
    text->callbackRunningText = [&]() { 
        waiting = true;
        std::cout << "waiting..." << std::endl;
    };
    addChild(text);

    ricardo = new Image("ricardo", "ricardo", "ricardo");
    ricardo->layer = -10;
    ricardo->y = Stage::height - 180;
    addChild(ricardo);

}

void scene2::update() {
    if (waiting && SNF::getTouch(KeyPhase::release)) {
        waiting = false;
        if (i < 3) {
            std::cout << i << std::endl;
            text->set_text(MSG::getAction(i)->chat);
            i++;
        }
    }
    
}