#pragma once

#include "Ephemeral/core/Object.hpp"
#include <vector>

namespace EE {

    enum class SceneType {
        NOT_DEFINED = 0,
        SCENE2D, SCENE3D, CONSOLE
    };

    class Scene {
        public:
        private:
            SceneType _type;
            uint16_t _numSprite2D;
            uint16_t _numSprite3D;
            uint8_t _screen;
            
            std::vector<Object*> children;

            bool _TextLayer[4] = {0, 0, 0, 0};
        public:
            Scene();
            virtual ~Scene();

            void preUpdate();

            // buat client
            virtual void initialize() = 0;
            virtual void update() = 0;
            
            virtual void destroy();
            
            // child
            Object* addChild(Object* child);
            Object* getChildByName(std::string name);
            Object* getChildbyId(unsigned int id);
            bool removeChild(Object* child);
            bool removeChildByName(std::string name);
            bool removeChildById(unsigned int id);
            bool removeChildAll();

            // textlayer
            bool textlayer_check(uint8_t layer);
            void textlayer_create(uint8_t layer, const char* fontname, uint8_t rotation);
            void textlayer_remove(uint8_t layer);
            void textlayer_reset();

            // GET && SET

            uint8_t get_screen() { return _screen; }
            void set_screen(uint8_t screen) { _screen = screen; }

        private:
    };

}