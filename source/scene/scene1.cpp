#include "scene1.h"
#include "scene2.h"

#include <fat.h>

NGObject* mist;
STween::STween<int> tween;

scene1::scene1() {
    i = 0;
}

void done(int val) {
    mist->x = val;
    // std::cout << val << std::endl;
}

FILE* savefile;

struct VariablesToSave {
    std::string var3;
} SaveData;

void scene1::initialize() {
    std::cout << "Scene initialize" << std::endl;

    std::cout << "Tekan UP buat save" << std::endl;
    std::cout << "Tekan DOWN buat load" << std::endl;

    // mist = new NGObject(Random::string(5), Assets::getSprite("mist"), Assets::getPallete("mist"));
    // mist->bound.set(0, 0, 64, 128);
    // NGMain::getInstance()->get_scene()->addChild(mist);

    

    // tween.From(i).To(256 - 64).Time(10.0).OnStep(done).Easing(STween::EasingFunction::CubicInOut);

    fatInitDefault();
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

        std::string random = Random::string(5);
        SaveData.var3 = random;

        std::cout << "Generate Random string: (" << random << ")" << std::endl;


        std::cout << "Save file" << std::endl;

        savefile = fopen("fat:/savefile.sav","wb");
        fwrite(&SaveData,1,sizeof(SaveData),savefile);
        fclose(savefile);
    }

    if (SNF::getKeys(Key::DOWN, KeyPhase::release)) {
        std::cout << "Load file" << std::endl;

        savefile = fopen("fat:/savefile.sav","rb");
        fread(&SaveData,1,sizeof(SaveData),savefile);
        fclose(savefile);

         std::cout << "Hasil load = " << SaveData.var3 << std::endl;

        // NGObject* obj = new NGObject(Random::string(5), Assets::getSprite("mist"), Assets::getPallete("mist"));
        // obj->x = Random::range(256);
        // obj->y = Random::range(192);
        // NGMain::getInstance()->get_scene()->addChild(obj);

        // i++;
        // std::cout << i << std::endl;
    }
}

