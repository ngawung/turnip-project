#include <iostream>
#include <fstream>

#include "scene1.h"
#include "scene2.h"

class Student {
    public:
        char var[40];
};

scene2::scene2() {
    i = 0;
}

void scene2::initialize() {
    std::cout << "Scene 2 init" << std::endl;

    Assets::load3dSprite("new/mist", "mist", 0, 64, 128, false);
	Assets::load3dPallete("new/mist", "mist", 0);
}

void scene2::update() {
    if (SNF::getKeys(Key::UP, KeyPhase::release)) {
        if (SaveGame::isFatSupported()) {
            Student one;
            strcpy(one.var, Random::string(10).c_str());
            std::cout << "Saving random string: " << one.var << std::endl;

            std::cout << "size1: " << sizeof(one) << std::endl;

            SaveGame::save(&one, "slot_1");

        } else {
            std::cout << "Save failed! fat not supported" << std::endl;
        }
    }

    if (SNF::getKeys(Key::DOWN, KeyPhase::release)) {
        if (SaveGame::isFatSupported()) {
            Student two;

            SaveGame::load(&two, "slot_1");

            std::cout << "Hasil load: " << two.var << std::endl;
        } else {
            std::cout << "Load failed! fat not supported" << std::endl;
        }
    }

    if (SNF::getKeys(Key::RIGHT, KeyPhase::held)) {
        NGObject* obj = new NGObject(Random::string(5), Assets::getSprite("mist"), Assets::getPallete("mist"));
        obj->x = Random::range(256);
        obj->y = Random::range(192);
        NGMain::getInstance()->get_scene()->addChild(obj);

        i++;
    }
}