#include "epch.hpp"
#include "App.hpp"

#include <nf_lib.h>

namespace EE {

    App* App::_instance = 0;

    App::App(ScreenPosition screen3D = ScreenPosition::TOP, bool console = false) {
        App* ptr = this;
        _instance = ptr;

        _console = console;
        _screen3D = screen3D;
    }

    App::~App() {

    }

    void App::start() {
        srand(time(NULL));

        // setup main screen position
        if (_screen3D == ScreenPosition::TOP) lcdMainOnTop();
        else lcdMainOnBottom();

        // setup video mode
        videoSetMode(MODE_5_3D);
        videoSetModeSub(MODE_0_2D);

        // nitrofs
        NF_SetRootFolder("NITROFS");

        // setup GL2D
        glScreen2D();

        ////////////////////

        // // init maxmod

        // // setup background
        // NF_InitTiledBgBuffers();
        // NF_InitTiledBgSys(SCREEN_0);
        // NF_InitTiledBgSys(SCREEN_1);

        // // init bmfont
        // NF_InitTextSys(SCREEN_0);
        // NF_InitTextSys(SCREEN_1);

        // // setup sprite buffer
        // NF_InitSpriteBuffers();

        // // init 3d sprite
        // NF_Init3dSpriteSys();
        // NF_3dSpritesLayer(2);  //default 3d sprite layer 2

        // // init 2d sprite
        // NF_InitSpriteSys(SCREEN_1); // init 2d sprite on subscene

        // // setup bmfont layer

        // // preload core assets

        ////////////////////

        if (_console) enableConsole();

        // SaveGame::initialize();

        #ifdef DEBUG
            std::cout << "Ephemeral initialized" << std::endl; 
        #endif

        handleOnStart();

        while(true) {
            scanKeys();

            update();
            
            swiWaitForVBlank();
        }
    }

    void App::update() {
        // update main scene
        if (_mainScene != nullptr) {
            glBegin2D();
            _mainScene->preUpdate();
            glEnd2D();
            glFlush(0);
        }

        // update sub scene
        if (_subScene != nullptr) _subScene->preUpdate();
    }

    void App::enableConsole() {
        consoleDemoInit();
    }

    void App::trace(const char * text) {
        std::cout << "[Tr] " << text << std::endl;
    }

    // GET && SET

}