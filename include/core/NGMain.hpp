#pragma once

#include "NGScene.hpp"

#define SCREEN_0 0
#define SCREEN_1 1

#define LAYER_0 0
#define LAYER_1 1
#define LAYER_2 2
#define LAYER_3 3

typedef struct Stage {
    static const uint width = 256;
    static const uint height = 192;

    static const uint bmfWidth = 256 / 8;
    static const uint bmfHeight = 192 / 8;
} Stage;

class NGMain {
    public:
    private:
        static NGMain* _instance;
        
        NGScene* _mainScene;
        NGScene* _subScene;

        uint8_t _screen3D;
        uint8_t _screen2D;
        bool _console;
    
    public:
        static NGMain* getInstance();

        NGMain(uint8_t screen3D, bool console);

        void initialize();
        void update();
        void destroy();

        void enableConsole();

        // GET && SET

        NGScene* get_mainScene();
        void set_mainScene(NGScene* scene);
        
        NGScene* get_subScene();
        void set_subScene(NGScene* scene);

    private:
};