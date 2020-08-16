#pragma once

#include <string>

class SaveGame {
    public:

    private:
        static bool _fat;
        static void* _data;


    public:
        static void initialize();
        
        static bool save(const void* data, std::string filename);
        static bool load(void* data, std::string filename);

        static bool isFatSupported();
    private:

};