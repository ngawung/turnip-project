#pragma once

#include <sstream>
#include <fstream>
#include <string>

class SaveGame {
    public:

    private:
        static bool _fat;
        static void* _data;


    public:
        static void initialize();
        
        template <typename T> static bool save(const T* data, std::string filename) {
            // using stringstream
            std::stringstream ss;
            ss << "fat:/" << filename << ".sav";

            // convert ss to string
            std::string str(ss.str());

            std::ofstream ofs(str.c_str(), std::ios::binary);
            if (ofs.is_open()) {
                ofs.write((char*)data, sizeof(T));
                ofs.close();
                return true;
            } else {
                ofs.close();
                return false;
            }
        }

        template <typename T> static bool load(T* data, std::string filename) {
            // using stringstream
            std::stringstream ss;
            ss << "fat:/" << filename << ".sav";

            // convert ss to string
            std::string str(ss.str());

            std::ifstream ifs(str.c_str(), std::ios::binary);
            if (ifs.is_open()) {
                ifs.read((char*)data, sizeof(T));
                ifs.close();
                return true;
            } else {
                ifs.close();
                return false;
            }
        }

        static bool isFatSupported();
    private:

};