#pragma once

#include "Ephemeral/core/Scene.hpp"

namespace EE {

    #define SCREEN_0 0
    #define SCREEN_1 1

    #define LAYER_0 0
    #define LAYER_1 1
    #define LAYER_2 2
    #define LAYER_3 3

    struct Stage {
        const int witdh = 256;
        const int height = 192;
    };

    class App {
        public:
        private:
            static App* _instance;
            bool _console;

            Scene* _mainScene;
            Scene* _subScene;

            uint8_t _screen3D;

        public:
            App(uint8_t screen3D, bool console);
            virtual ~App();

            void start();

            void update();
            void destroy();

            void enableConsole();

            // GET && SET

            static App* get_instance() { return _instance; }

        private:

    };

    App* CreateApp();

}