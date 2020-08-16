#include "scene1.h"
#include "scene2.h"

NGObject* mist;
STween::STween<int> tween;

scene1::scene1() {
    i = 0;
}

void done(int val) {
    mist->x = val;
    // std::cout << val << std::endl;
}

struct test {
    char str[10];
};

void scene1::initialize() {

    std::cout << std::endl << "Tekan UP buat save" << std::endl;
    std::cout << std::endl << "Tekan DOWN buat load" << std::endl;

    // mist = new NGObject(Random::string(5), Assets::getSprite("mist"), Assets::getPallete("mist"));
    // mist->bound.set(0, 0, 64, 128);
    // NGMain::getInstance()->get_scene()->addChild(mist);

    // tween.From(i).To(256 - 64).Time(10.0).OnStep(done).Easing(STween::EasingFunction::CubicInOut);

    // init fat
    SaveGame::initialize();
}

void scene1::update() {
    // tween.Update(0.02); // fixed dt, time doesnt work on desmume

    // if (SNF::getTouch(KeyPhase::release)) {
    //     std::cout << SNF::Stylus.px << ":" << SNF::Stylus.py << std::endl;
    // }

    // if (mist->getTouch(KeyPhase::release)) {
    //     std::cout << "Touch" << std::endl;
    // }

    // if (SNF::getKeys(Key::LEFT, KeyPhase::release)) {
    //     NGMain::getInstance()->set_scene(new scene2());
    // }

    // if (SNF::getKeys(Key::RIGHT, KeyPhase::release)) {
    //     NGMain::getInstance()->get_scene()->printName();
    // }
    
    // if (SNF::getKeys(Key::A, KeyPhase::release)) {
    //     std::cout << "open" << std::endl;
    // }

    if (SNF::getKeys(Key::UP, KeyPhase::release)) {
        if (SaveGame::isFatSupported()) {
            test testsave;
            // Random::string(10).copy(testsave.str, 10);
            strcpy(testsave.str, Random::string(10).c_str());
            std::cout << "Saving Random number: (" << testsave.str << ")" << std::endl;

            // SaveGame::save(&var3, "save_slot1");

            FILE* savefile = fopen("fat:/savefile.sav" ,"wb");
            fwrite(&testsave, 1, sizeof(&testsave), savefile);
            fclose(savefile);
        } else {
            std::cout << "Save failed! fat not supported" << std::endl;
        }
    }

    if (SNF::getKeys(Key::DOWN, KeyPhase::release)) {
        if (SaveGame::isFatSupported()) {
            //int NewSaveData;
            // SaveGame::load(&NewSaveData,"save_slot1");

            test loadsave;

            FILE* savefile = fopen("fat:/savefile.sav" ,"rb");
            fread(&loadsave, 1, sizeof(&loadsave), savefile);
            fclose(savefile);

            std::cout << "Hasil load = " << loadsave.str << std::endl;
        } else {
            std::cout << "Load failed! fat not supported" << std::endl;
        }

        // NGObject* obj = new NGObject(Random::string(5), Assets::getSprite("mist"), Assets::getPallete("mist"));
        // obj->x = Random::range(256);
        // obj->y = Random::range(192);
        // NGMain::getInstance()->get_scene()->addChild(obj);

        // i++;
        // std::cout << i << std::endl;
    }
}

