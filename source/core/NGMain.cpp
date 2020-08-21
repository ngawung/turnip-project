#include "NGMain.hpp"

NGMain* NGMain::_instance = 0;

NGMain* NGMain::getInstance() {
    return _instance;
}

NGMain::NGMain(uint8_t screen3D = 1, bool console = false) {
    NGMain* ptr = this;
    _instance = ptr;
    _console = console;

    _screen3D = screen3D;
    // if (_screen3D == 0) _screen2D = 1;
    // else if (_screen3D == 1) _screen2D = 0;

    initialize();
}

void NGMain::initialize() {
    srand(time(NULL));

    // setup screen
    NF_Set3D(_screen3D, 0);
    NF_Set2D(SCREEN_1, 0);

    NF_SetRootFolder("NITROFS");

    // soundEnable();
    // NF_InitRawSoundBuffers();

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
    NF_InitSpriteSys(SCREEN_1);

    // setup bmfont layer
    NF_LoadTextFont("core/font/default", "font", 256, 256, 0);
    NF_CreateTextLayer(SCREEN_0, LAYER_1, 0, "font");
    NF_CreateTextLayer(SCREEN_1, LAYER_2, 0, "font");

    // preload core assets

    if (_console) enableConsole();
    std::cout << "Game Initialize" << std::endl;

    // SaveGame::initialize();
}

void NGMain::update() {
    // update input
    scanKeys();

    // clear bmfont before scene update
    NF_ClearTextLayer(0, 1);

    // update main scene
    if (_mainScene != nullptr) {
        _mainScene->preUpdate();
    }

    // update bmfont on main scene
    NF_UpdateTextLayers();
    NF_ClearTextLayer(1, 2);

    // update sub scene
    if (_subScene != nullptr) {
        _subScene->preUpdate();
    }

    // update bmfont on sub scene
    NF_UpdateTextLayers();

    // draw 3d sprite
    NF_Draw3dSprites();
    glFlush(0);

    // draw 2d sprite
    NF_SpriteOamSet(SCREEN_1);

    // ==============//
    swiWaitForVBlank();
    // ==============//

    // update animation
    NF_Update3dSpritesGfx();

    // update oam
    oamUpdate(&oamSub);
}

void NGMain::destroy() {
    if (_mainScene != nullptr) {
        _mainScene->destroy();
        delete _mainScene;
    }

    if (_subScene != nullptr) {
        _subScene->destroy();
        delete _subScene;
    }
}

void NGMain::enableConsole() {
    consoleDemoInit();
}

// GET && SET

NGScene* NGMain::get_mainScene() {
    return _mainScene;
}

void NGMain::set_mainScene(NGScene* scene) {
    if (_mainScene != nullptr) {
        _mainScene->destroy();
        delete _mainScene;
    }

    _mainScene = scene;
    _mainScene->set_screen(0);
    _mainScene->background.screen = 0; // i should move this to NGScene.. but im lazy
    _mainScene->initialize();
}

NGScene* NGMain::get_subScene() {
    return _subScene;
}

void NGMain::set_subScene(NGScene* scene) {
    if (_subScene != nullptr) {
        _subScene->destroy();
        delete _subScene;
    }

    _subScene = scene;
    _subScene->set_screen(1);
    _subScene->background.screen = 1; // i should move this to NGScene.. but im lazy
    _subScene->initialize();
}