#pragma once

namespace EE {

    enum class SceneType {
        NOT_DEFINED = 0,
        SCENE2D, SCENE3D, CONSOLE
    };

    class Scene {
        public:
        private:
            SceneType _type;
            uint8_t _screen;
            
            // std::vector<DisplayObject*> children;

        public:
            Scene();
            virtual ~Scene();

            void preUpdate();

            // buat client
            virtual void initialize() = 0;
            virtual void update() = 0;
            
            virtual void destroy();
            virtual std::string toString();

            // DisplayObject* addChild(DisplayObject* child);
            
            // DisplayObject* getChildByName(std::string name);
            // DisplayObject* getChildbyId(unsigned int id);
            
            // bool removeChild(DisplayObject* child);
            // bool removeChildByName(std::string name);
            // bool removeChildById(unsigned int id);
            // bool removeChildAll();

            // GET && SET

            uint8_t get_screen();
            void set_screen(uint8_t screen);

        private:
    };

}