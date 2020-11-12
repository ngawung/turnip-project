#pragma once

#include <Ephemeral/core/App.hpp>
#include <Ephemeral/core/Scene.hpp>

namespace EE {

    class Scene1 : public Scene {
        public:
        private:
        
        public:
            Scene1();

            void initialize() override {
                App::get_instance()->trace("initialize scene 1");
            }

            void update() override;
            
        private:
    };

    class Scene2 : public Scene {
        public:
        private:
        
        public:
            Scene2();

            void initialize() override {
                App::get_instance()->trace("initialize scene 2");
            }

            void update() override;
            
        private:
    };
    
}
