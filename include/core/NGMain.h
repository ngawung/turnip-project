#pragma once

#include "NGScene.h"

#define SCREEN_0 0
#define SCREEN_1 1

#define LAYER_0 0
#define LAYER_1 1
#define LAYER_2 2
#define LAYER_3 3

typedef struct Stage {
    const uint width = 256;
    const uint height = 192;
} Stage;

class NGMain {
    public:
    private:
        static NGMain* _instance;
        NGScene* _currentScene;

        bool _console;
    
    public:
        static NGMain* getInstance();

        NGMain(bool console = false);

        void initialize();
        void update();
        void destroy();

        void enableConsole();

        // GET && SET

        NGScene* get_scene();
        void set_scene(NGScene* scene);

    private:
};