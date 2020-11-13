#include "epch.hpp"
#include "Ephemeral/utils/Assets.hpp"

namespace EE {
    
            // ======= ram =======
            bool Assets::loadSprite(const char* file, std::string name, uint16_t width, uint16_t height) {
                // check if name already exist
                for (uint16_t i=0; i<sprite.size(); i++) {
                    if (sprite[i]->name == name) {
                        #ifdef DEBUG
                            std::cout << "sprite (" << name << ") already exist" << std::endl; 
                        #endif
                        return false;
                    }
                }

                RamSlot* ramslot = new RamSlot(name);
                #ifdef DEBUG 
                    std::cout << "" << std::endl; 
                #endif
            }
            bool Assets::loadPallete(const char* file, std::string name) {}

            bool Assets::unloadSprite(std::string name) {}
            bool Assets::unloadPallete(std::string name) {}

            // ======= vram2D =======
            bool Assets::loadSprite2D(std::string name, bool keepframes) {}
            bool Assets::loadPallete2D(std::string name) {}

            bool Assets::freeSprite2D(std::string name) {}
            bool Assets::freePallete2D(std::string name) {}

            // ======= vram3D =======
            bool Assets::loadSprite3D(std::string name, bool keepframes) {}
            bool Assets::loadPallete3D(std::string name) {}

            bool Assets::freeSprite3D(std::string name) {}
            bool Assets::freePallete3D(std::string name) {}

            // ======= Background =======
            bool Assets::loadBg(std::string name) {}
            bool Assets::unloadBg(std::string name) {}
            
            // ======= Sound =======
            bool Assets::loadSound(std::string name) {}
            bool Assets::unloadSound(std::string name) {}

}