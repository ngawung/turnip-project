#include <iostream>
#include <fstream>

#include "scene2.hpp"
#include "Message.hpp"

scene2::scene2() {
    i = 0;
}

Image* namebox;
Image* ricardo;
BMFont* name;
TextBox* text;

bool waiting = true;

uint16_t mapIndex = 0;
std::vector<uint16_t>* mapList;

STween::STween<int16_t> tween;

int j = 0;

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

    namebox = new Image("namebox", "namebox", "hud");
    namebox->y = 191 - 56 - 16 -4;
    addChild(namebox);

    name = new BMFont("name", "");
    name->y = namebox->y + 4 + 1;
    name->x = 0;
    addChild(name);

    BMFont::defineHex(get_screen(), 1, 0x000000);
    BMFont::defineRGB(get_screen(), 2, 50, 168, 82);
    BMFont::setColor(get_screen(), 1);

    text = new TextBox("text", "", 256 - 16, 0);
    text->y = 191 - 56 + 8 + 1;
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
    tween.Update(0.02); // fixed dt, time doesnt work on desmume

    if (waiting && SNF::getTouch(KeyPhase::release)) {
        nextAction();
    }    
}

void scene2::nextAction() {
    waiting = false;
    if (mapIndex < mapList->size()) {

        Action* result = MSG::getAction((*mapList)[mapIndex]);
        std::cout << "Running action no " << mapIndex << ":" << result->type << std::endl;


        // switch (result->type) {
        //     case ActionType::CHAT_OPEN:
        //         break;

        //     case ActionType::CHAT_UPDATE:
        //         break;

        //     case ActionType::CHAT_CLOSE:
        //         break;

        //     case ActionType::NPC_SPAWN:
        //         break;

        //     case ActionType::NPC_UPDATE:
        //         break;
            
        //     case ActionType::NPC_REMOVE:
        //         break;
            
        // }

        if (result->type == ActionType::CHAT_OPEN) {
            // remove textbox if already exist
            if (getChildByName("action_textbox")) removeChildByName("action_textbox");

            Image* textbox = new Image("action_textbox", "textbox", "hud");
            textbox->y = 191;
            textbox->layer = 10;
            addChild(textbox);

            tween.From(&textbox->y).To(191 - 56).Time(1.0).Easing(STween::EasingFunction::CubicInOut).OnFinish([&]() {
                // mapIndex++;
                nextAction();
            });
        }

        if (result->type == ActionType::CHAT_UPDATE) {
            std::cout << i << std::endl;
            name->text = result->chat_name;
            text->skip = result->chat_speed;
            text->set_text(result->chat_msg);
        }

        if (result->type == ActionType::CHAT_CLOSE) {
            DisplayObject* textbox = getChildByName("action_textbox");

            if (textbox) {
                tween.From(&textbox->y).To(191).Time(1.0).Easing(STween::EasingFunction::CubicInOut).OnFinish([&]() {
                    removeChildByName("action_textbox");
                    // mapIndex++;
                    nextAction();
                });
            }
        }

        if (result->type == ActionType::NPC_SPAWN) {
            std::string npcName = "action_npc_";
            npcName += std::to_string(result->npc_id);
            
            // remove npc if the id already exist
            if (getChildByName(npcName)) removeChildByName(npcName);

            Image* npc = new Image(npcName, result->npc_gfx, result->npc_pal);
            npc->x = result->npc_x;
            npc->y = result->npc_y;
            npc->flip = result->npc_flip;
            npc->layer = -10;
            addChild(npc);
            waiting = true;
        }

        if (result->type == ActionType::NPC_UPDATE) {
            std::string npcName = "action_npc_";
            npcName += std::to_string(result->npc_id);

            DisplayObject* npc = getChildByName(npcName);
            if (npc) {
                tween.From(&npc->x).To(result->npc_x).Time(1.0).Easing(STween::EasingFunction::CubicInOut);
                tween.From(&npc->y).To(result->npc_y).Time(1.0).Easing(STween::EasingFunction::CubicInOut).OnFinish([&]() {
                    waiting = true;
                });
            } else {
                waiting = true;
            }
        }

        mapIndex++;
        if (result->skipOnLoad) nextAction();
    }
}