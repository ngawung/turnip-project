#include <iostream>

#include "NGMain.h"
#include "scene1.h"
#include "scene2.h"
#include "Random.h"
#include "Assets.h"

scene2::scene2() {
    i = 0;
}

void scene2::initialize() {
    std::cout << "Scene 2 init" << std::endl;
}

void scene2::update() {
    if (KEY_LEFT & keysUp()) {
        NGMain::getInstance()->set_scene(new scene1());
    }

    if (KEY_RIGHT & keysUp()) {
        NGMain::getInstance()->get_scene()->printName();
    }

    if (KEY_DOWN & keysHeld()) {
        NGObject* obj = new NGObject(Random::string(5), Assets::getSprite("mist"), Assets::getPallete("mist"));
        obj->x = Random::range(256);
        obj->y = Random::range(192);
        NGMain::getInstance()->get_scene()->addChild(obj);

        i++;
        std::cout << i << std::endl;
    }
}