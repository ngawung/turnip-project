#include <iostream>
#include <fstream>

#include "NGMain.h"
#include "scene1.h"
#include "scene2.h"
#include "Random.h"
#include "Assets.h"

class Student {
    public:
        char var[40];
};

scene2::scene2() {
    i = 0;
}

void scene2::initialize() {
    std::cout << "Scene 2 init" << std::endl;

    SaveGame::initialize();
}

void scene2::update() {
    if (SNF::getKeys(Key::UP, KeyPhase::release)) {
        if (SaveGame::isFatSupported()) {
            Student one;
            strcpy(one.var, Random::string(10).c_str());
            std::cout << "Saving random string: " << one.var << std::endl;

            std::ofstream ofs("fat:/savefile.sav", std::ios::binary);
            ofs.write((char*)&one, sizeof(one));

        } else {
            std::cout << "Save failed! fat not supported" << std::endl;
        }
    }

    if (SNF::getKeys(Key::DOWN, KeyPhase::release)) {
        if (SaveGame::isFatSupported()) {
            Student two;

            std::ifstream ifs("fat:/savefile.sav", std::ios::binary);
            ifs.read((char*)&two, sizeof(two));

            std::cout << "Hasil load: " << two.var << std::endl;
        } else {
            std::cout << "Load failed! fat not supported" << std::endl;
        }
    }
}