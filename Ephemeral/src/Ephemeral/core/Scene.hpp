#pragma once

#include "Ephemeral/core/Object.hpp"
#include <vector>

namespace EE {

    enum class SceneType {
        BASIC, MAIN, SUB
    };

    class BasicScene {
        public:
        protected:
        std::vector<Object*> children;
        SceneType sceneType;
            
        public:
            BasicScene();
            virtual ~BasicScene();

            virtual void preUpdate();

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

            // GET && SET

        private:
    };

    class MainScene : public BasicScene {
        public:
            MainScene();
            virtual ~MainScene();
        private:
        
        public:
            void preUpdate() override;
        private:
    };

    class SubScene : public BasicScene {
        public:
            SubScene();
            virtual ~SubScene();
        private:
        
        public:
            void preUpdate() override;
        private:
    };

}