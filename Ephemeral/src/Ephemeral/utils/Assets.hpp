#pragma once

#include <string>
#include <vector>

namespace EE {
    
    enum class RamType { NONE, VRAM2D, VRAM3D };

    struct RamSlot {
        std::string name;
        RamSlot(std::string _name) : name(_name) {}
    };

    class Assets {
        public:
        private:
            // ram
            static inline RamSlot* sprite[256];
            static inline RamSlot* pallete[64];

            // vram 2d
            static inline RamSlot* sprite2D[128];
            static inline RamSlot* pallete2D[16];

            // vram 3d
            static inline RamSlot* sprite3D[256];
            static inline RamSlot* pallete3D[32];

            // ==================

            // ram
            static inline uint16_t maxSprite = 256;
            static inline uint16_t maxPallete = 64;

            // vram 2d
            static inline uint16_t maxSprite2D = 128;
            static inline uint16_t maxPallete2D = 16;
            
            // vram 3d
            static inline uint16_t maxSprite3D = 256;
            static inline uint16_t maxPallete3D = 32;
        
        public:
            // ram
            static bool loadSprite(const char* file, std::string name, uint16_t width, uint16_t height);
            static bool loadPallete(const char* file, std::string name);

            static bool unloadSprite(std::string name);
            static bool unloadPallete(std::string name);

            // vram2D
            // static bool loadSprite2D(std::string name, bool keepframes);
            // static bool loadPallete2D(std::string name);

            // static bool freeSprite2D(std::string name);
            // static bool freePallete2D(std::string name);

            // vram3D
            static bool loadSprite3D(std::string name, bool keepframes);
            static bool loadPallete3D(std::string name);

            static bool freeSprite3D(std::string name);
            static bool freePallete3D(std::string name);

            // Background
            static bool loadBg(std::string name);
            static bool unloadBg(std::string name);
            
            // Sound
            static bool loadSound(std::string name);
            static bool unloadSound(std::string name);

            // ================ Get && Set ==================

            // // vram2d
            // static uint16_t get_sprite2D(std::string name);
            // static uint16_t get_pallete2D(std::string name);
            
            // vram3d
            static uint16_t get_sprite3D(std::string name);
            static uint16_t get_pallete3D(std::string name);

            // not implemented yet.... to lazy
            static uint16_t getSprite(std::string name);
            static uint16_t getPallete(std::string name);

            // background

            // sound


            // // ram vram 256
            // static void load3dSprite(const char* file, std::string name, uint16_t ramslot, uint16_t width, uint16_t height, bool keepframe);

            // // ram 64, vram 32
            // static void load3dPallete(const char* file, std::string name, uint16_t ramslot);

            // static void unload3dSprite(std::string name);
            // static void unload3dPallete(std::string name);
            // static void unload3dSpriteAll();
            // static void unload3dPalleteAll();

        private:
    };
    
}
