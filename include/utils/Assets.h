#pragma once

#include <map>
#include <string>

class Assets {
    public:
        inline static std::map<std::string, uint16_t> sprite;
		inline static std::map<std::string, uint16_t> pallete;
		inline static std::string test;
    private:
    
    public:
        // ram vram 256
		static void load3dSprite(const char* file, std::string name, uint16_t ramslot, uint16_t width, uint16_t height, bool keepframe);

        // ram 64, vram 32
		static void load3dPallete(const char* file, std::string name, uint16_t ramslot);

        static void unload3dSprite(std::string name);
        static void unload3dPallete(std::string name);
        static void unload3dSpriteAll();
        static void unload3dPalleteAll();

        static uint16_t getSprite(std::string name);
        static uint16_t getPallete(std::string name);

    private:
};