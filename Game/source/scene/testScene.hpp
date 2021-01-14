#pragma once

#include <Ephemeral/core/App.hpp>
#include <Ephemeral/core/Scene.hpp>

namespace EE {

    class Scene1 : public MainScene {
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
    
}
