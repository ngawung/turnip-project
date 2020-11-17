#include "epch.hpp"
#include "Ephemeral/utils/Assets.hpp"

namespace EE {
    
            // ======= ram =======
            bool Assets::loadSprite(const char* file, std::string name, uint16_t width, uint16_t height) {
                // check if name already exist
                for (uint16_t i=0; i<maxSprite; i++) {
                    if (sprite[i] == nullptr) continue;

                    if (sprite[i]->name == name) {
                        #ifdef DEBUG
                            std::cout << "sprite (" << name << ") already exist" << std::endl; 
                        #endif
                        return false;
                    }
                }
                
                // find empty slot
                for (uint16_t i=0; i<maxSprite; i++) {
                    if (sprite[i] != nullptr) continue;

                    // load ramslot
                    RamSlot* ramslot = new RamSlot(name);
                    sprite[i] = ramslot;
                    #ifdef DEBUG 
                        std::cout << "load sprite " << name << std::endl; 
                    #endif
                    NF_LoadSpriteGfx(file, i, width, height);
                    return true;
                }
  
                #ifdef DEBUG
                    std::cout << "sprite reached max capacity" << std::endl; 
                #endif
                return false;
            }

            bool Assets::loadPallete(const char* file, std::string name) {
                // check if name already exist
                for (uint16_t i=0; i<maxPallete; i++) {
                    if (pallete[i] == nullptr) continue;

                    if (pallete[i]->name == name) {
                        #ifdef DEBUG
                            std::cout << "pallete (" << name << ") already exist" << std::endl; 
                        #endif
                        return false;
                    }
                }
                
                // find empty slot
                for (uint16_t i=0; i<maxPallete; i++) {
                    if (pallete[i] != nullptr) continue;

                    // load ramslot
                    RamSlot* ramslot = new RamSlot(name);
                    pallete[i] = ramslot;
                    #ifdef DEBUG 
                        std::cout << "load pallete " << name << std::endl; 
                    #endif
                    NF_LoadSpritePal(file, i);
                    return true;
                }
  
                #ifdef DEBUG
                    std::cout << "pallete reached max capacity" << std::endl; 
                #endif
                return false;
            }

            bool Assets::unloadSprite(std::string name) {
                for (uint16_t i=0; i<maxSprite; i++) {
                    if (sprite[i]->name == name) {
                        delete sprite[i];
                        sprite[i] = nullptr;
                        #ifdef DEBUG
                            std::cout << "unload sprite " << name << std::endl; 
                        #endif
                        NF_UnloadSpriteGfx(i);
                        return true;
                    }
                }

                #ifdef DEBUG
                    std::cout << "failed to unload sprite " << name << std::endl; 
                #endif
                return false;
            }

            bool Assets::unloadPallete(std::string name) {
                for (uint16_t i=0; i<maxPallete; i++) {
                    if (pallete[i]->name == name) {
                        delete pallete[i];
                        pallete[i] = nullptr;
                        #ifdef DEBUG
                            std::cout << "unload pallete " << name << std::endl; 
                        #endif
                        NF_UnloadSpritePal(i);
                    }
                }

                #ifdef DEBUG
                    std::cout << "failed to unload pallete " << name << std::endl; 
                #endif
                return false;
            }

            // ======= vram2D =======
            // bool Assets::loadSprite2D(std::string name, bool keepframes) {}
            // bool Assets::loadPallete2D(std::string name) {}

            // bool Assets::freeSprite2D(std::string name) {}
            // bool Assets::freePallete2D(std::string name) {}

            // ======= vram3D =======
            bool Assets::loadSprite3D(std::string name, bool keepframes) {
                // find in ram
                int16_t ramIndex = -1;
                for (uint16_t i=0; i<maxSprite; i++) {
                    if (sprite[i] == nullptr) continue;

                    if (sprite[i]->name == name) {
                        ramIndex = i;
                        break;
                    }
                }

                if (ramIndex == -1) {
                    #ifdef DEBUG
                        std::cout << "cant find sprite " << name << " in ram" << std::endl; 
                    #endif
                    return false;
                }

                // find empty slot
                for (uint16_t i=0; i<maxSprite3D; i++) {
                    if (sprite3D[i] != nullptr) continue;

                    // load ramslot
                    RamSlot* ramslot = new RamSlot(name);
                    sprite3D[i] = ramslot;
                    #ifdef DEBUG 
                        std::cout << "load sprite3D " << name << std::endl; 
                    #endif
                    NF_Vram3dSpriteGfx(ramIndex, i, keepframes);
                    return true;
                }
  
                #ifdef DEBUG
                    std::cout << "sprite3D reached max capacity" << std::endl; 
                #endif
                return false;
            }

            bool Assets::loadPallete3D(std::string name) {
                // find in ram
                int16_t ramIndex = -1;
                for (uint16_t i=0; i<maxPallete; i++) {
                    if (pallete[i] == nullptr) continue;

                    if (pallete[i]->name == name) {
                        ramIndex = i;
                        break;
                    }
                }

                if (ramIndex == -1) {
                    #ifdef DEBUG
                        std::cout << "cant find pallete " << name << " in ram" << std::endl; 
                    #endif
                    return false;
                }

                // find empty slot
                for (uint16_t i=0; i<maxPallete2D; i++) {
                    if (pallete3D[i] != nullptr) continue;

                    // load ramslot
                    RamSlot* ramslot = new RamSlot(name);
                    pallete3D[i] = ramslot;
                    #ifdef DEBUG 
                        std::cout << "load pallete3D " << name << std::endl; 
                    #endif
                    NF_Vram3dSpritePal(ramIndex, i);
                    return true;
                }
  
                #ifdef DEBUG
                    std::cout << "pallete3D reached max capacity" << std::endl; 
                #endif
                return false;
            }

            bool Assets::freeSprite3D(std::string name) {}
            bool Assets::freePallete3D(std::string name) {}

            // ======= Background =======
            bool Assets::loadBg(std::string name) {}
            bool Assets::unloadBg(std::string name) {}
            
            // ======= Sound =======
            bool Assets::loadSound(std::string name) {}
            bool Assets::unloadSound(std::string name) {}

}