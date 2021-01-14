#pragma once

#include "Ephemeral/core/Object.hpp"
#include <vector>

namespace EE {

    class BasicScene {
        public:
        private:
        std::vector<Object*> children;
            
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

    class MainScene : BasicScene {
        public:
        private:
        
        public:
        private:
    };

    class SubScene : BasicScene {
        public:
        private:
        
        public:
        private:
    };

}