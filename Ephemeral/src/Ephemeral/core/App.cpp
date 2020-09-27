#include "epch.hpp"
#include "App.hpp"

#include <nf_lib.h>

namespace EE {

    App* App::_instance = 0;

    App::App(uint8_t screen3D = 1, bool console = false) {
        App* ptr = this;
        _instance = ptr;

        _console = console;
        _screen3D = screen3D;
    }

    App::~App() {

    }

    void App::start() {
        srand(time(NULL));

        // setup screen
        NF_Set3D(_screen3D, 0);
        NF_Set2D(SCREEN_1, 0);

        NF_SetRootFolder("NITROFS");

        // init maxmod

        // setup background
        NF_InitTiledBgBuffers();
        NF_InitTiledBgSys(SCREEN_0);
        NF_InitTiledBgSys(SCREEN_1);

        // init bmfont
        NF_InitTextSys(SCREEN_0);
        NF_InitTextSys(SCREEN_1);

        // setup sprite buffer
        NF_InitSpriteBuffers();

        // init 3d sprite
        NF_Init3dSpriteSys();
        NF_3dSpritesLayer(2);  //default 3d sprite layer 2

        // init 2d sprite
        NF_InitSpriteSys(SCREEN_1); // init 2d sprite on subscene

        // setup bmfont layer

        // preload core assets

        if (_console) enableConsole();

        // SaveGame::initialize();

        dbg("Ephemeral initialized");

        while(true) {
            scanKeys();
            swiWaitForVBlank();
        }
    }

    void App::enableConsole() {
        consoleDemoInit();
    }

}