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

uint16_t mapIndex = 0;

std::vector<uint16_t>* mapList;

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

    name = new BMFont("name", "");
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

    // ricardo = new Image("ricardo", "ricardo", "ricardo");
    // ricardo->layer = -10;
    // ricardo->y = Stage::height - 180;
    // ricardo->flip = true;
    // addChild(ricardo);

    mapList = MSG::getMap("test");
}

void scene2::update() {
    if (waiting && SNF::getTouch(KeyPhase::release)) {
        nextAction();
    }    
}

void scene2::nextAction() {
    waiting = false;
    if (mapIndex < mapList->size()) {

        Action* result = MSG::getAction((*mapList)[mapIndex]);
        std::cout << "Running action no " << i << ":" << result->type << std::endl;

        if (result->type == ActionType::CHAT) {
            std::cout << i << std::endl;
            name->text = result->chat_name;
            text->skip = result->chat_speed;
            text->set_text(result->chat_msg);
        }

        if (result->type == ActionType::NPC_SPAWN) {
            std::string npcName = "npc_";
            npcName += std::to_string(result->npc_id);
            
            // remove npc if the id already exist
            if (getChildByName(npcName)) removeChildByName(npcName);

            Image* npc = new Image(npcName, result->npc_gfx, result->npc_pal);
            npc->x = result->npc_x;
            npc->y = result->npc_y;
            npc->flip = result->npc_flip;
            addChild(npc);
            
            waiting = true;
        }

        mapIndex++;
        if (result->skipOnLoad) nextAction();
    }
}