#include <iostream>
#include <unistd.h>

#include <fat.h>
#include "SaveGame.h"

bool SaveGame::_fat = false;
void* SaveGame::_data = nullptr;

void SaveGame::initialize() {
    _fat = fatInitDefault();

    if (!_fat) std::cout << "Warning fat not supported!" << std::endl;

    // change default directory back to nitrofs
    chdir("nitro:/");
}

// bool SaveGame::save(const char* data, std::string filename) {
//     // using stringstream
//     std::stringstream ss;
//     ss << "fat:/" << filename << ".sav";

//     // convert ss to string
//     std::string str(ss.str());

//     std::ofstream ofs(str.c_str(), std::ios::binary);

//      std::cout << "size2: " << sizeof(data) << std::endl;
    
//     if (ofs.is_open()) {
//         ofs.write(data, sizeof(data));
//         ofs.close();
//         return true;
//     } else {
//         ofs.close();
//         return false;
//     }
// }

// bool SaveGame::load(char* data, std::string filename) {
//     // using stringstream
//     std::stringstream ss;
//     ss << "fat:/" << filename << ".sav";

//     // convert ss to string
//     std::string str(ss.str());

//     std::cout << "size3: " << sizeof(data) << std::endl;

//     std::ifstream ifs(str.c_str(), std::ios::binary);
//     if (ifs.is_open()) {
//         ifs.read(data, sizeof(data));
//         ifs.close();
//         return true;
//     } else {
//         ifs.close();
//         return false;
//     }
// }

bool SaveGame::isFatSupported() {
    return _fat;
}