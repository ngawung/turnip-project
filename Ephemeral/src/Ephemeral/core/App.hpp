#pragma once

#include "Ephemeral/core/Scene.hpp"

namespace EE {

    #define SCREEN_0 0
    #define SCREEN_1 1

    #define LAYER_0 0
    #define LAYER_1 1
    #define LAYER_2 2
    #define LAYER_3 3

    enum class ScreenPosition {
        TOP, BOTTOM
    };

    struct Stage {
        const int witdh = 256;
        const int height = 192;
    };

    class App {
        public:

        private:
            static App* _instance;
            bool _console;

            MainScene* _mainScene;
            SubScene* _subScene;

            ScreenPosition _screen3D;

        public:
            App(ScreenPosition screen3D, bool console);
            virtual ~App();

            void start();

            void update();
            void destroy();

            virtual void handleOnStart() = 0;

            void enableConsole();

            // simple trace
            void trace(const char * text);

            // GET && SET
            static App* get_instance() { return _instance; }
            
            MainScene* get_mainScene() { return _mainScene; }
            SubScene* get_subScene() { return _subScene; }

            void set_mainScene(MainScene* scene) {
                if (_mainScene != nullptr) {
                    _mainScene->destroy();
                    delete _mainScene;
                }

                _mainScene = scene;
                _mainScene->initialize();
            }

            void set_subScene(SubScene* scene) {
                if (_subScene != nullptr) {
                    _subScene->destroy();
                    delete _subScene;
                }

                _subScene = scene;
                _subScene->initialize();
            }

        private:

    };

    App* CreateApp();

}