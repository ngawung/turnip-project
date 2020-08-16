#include <iostream>
#include <sstream>
#include <fat.h>
#include "SaveGame.h"

bool SaveGame::_fat = false;
void* SaveGame::_data = nullptr;

void SaveGame::initialize() {
    _fat = fatInitDefault();

    if (!_fat) std::cout << "Warning fat not supported!" << std::endl;
}

bool SaveGame::save(const void* data, std::string filename) {
    // using stringstream
    std::stringstream ss;
    ss << "fat:/" << filename << ".sav";

    // convert ss to string
    std::string str(ss.str());

    FILE* savefile = fopen(str.c_str() ,"wb");
    if (savefile) {
        fwrite(data, 1, sizeof(data), savefile);
        fclose(savefile);
        return true;
    } else {
        std::cout << "Failed to open savefile" <<std::endl;
        fclose(savefile);
        return false;
    }
}

bool SaveGame::load(void* data, std::string filename) {
    // using stringstream
    std::stringstream ss;
    ss << "fat:/" << filename << ".sav";

    // convert ss to string
    std::string str(ss.str());

    FILE* savefile = fopen(str.c_str() ,"rb");
    if (savefile) {
        fread(&data, 1, sizeof(data), savefile);
        fclose(savefile);
        return true;
    } else {
        std::cout << "Failed to open savefile" <<std::endl;
        fclose(savefile);
        return false;
    }
}

bool SaveGame::isFatSupported() {
    return _fat;
}