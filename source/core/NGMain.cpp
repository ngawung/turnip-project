#include "NGMain.h"

NGMain* NGMain::_instance = 0;

NGMain* NGMain::getInstance() {
    return _instance;
}

NGMain::NGMain(bool console) {
    NGMain* ptr = this;
    _instance = ptr;
    _console = console;

    initialize();
}

void NGMain::initialize() {
    srand(time(NULL));

    // setup screen
    NF_Set3D(SCREEN_0, 0);
    NF_Set2D(SCREEN_1, 0);

    NF_SetRootFolder("NITROFS");

    // setup background
    NF_InitTiledBgBuffers();
    NF_InitTiledBgSys(SCREEN_0);
    NF_InitTiledBgSys(SCREEN_1);

    // update 3d sprite
    NF_InitSpriteBuffers();
    NF_Init3dSpriteSys();
    NF_3dSpritesLayer(2);  //default 3d sprite layer 2

    // setup bmfont
    NF_InitTextSys(SCREEN_0);
    NF_LoadTextFont("core/font/default", "font", 256, 256, 0);
    NF_CreateTextLayer(SCREEN_0, LAYER_1, 0, "font");
    NF_CreateTextLayer(SCREEN_0, LAYER_2, 0, "font");

    // preload core assets

    if (_console) enableConsole();
    std::cout << "Game Initialize" << std::endl;

    SaveGame::initialize();
}

void NGMain::update() {
    // update input
    scanKeys();

    //update scene
    if (_currentScene != nullptr) {
        _currentScene->preUpdate();
    }

    // draw 3d sprite
    NF_Draw3dSprites();
    glFlush(0);

    swiWaitForVBlank();

    // update animation
    NF_Update3dSpritesGfx();

    // update bmfont
    NF_UpdateTextLayers();
}

void NGMain::destroy() {
    if (_currentScene != nullptr) {
        _currentScene->destroy();
        delete _currentScene;
    }
}

void NGMain::enableConsole() {
    consoleDemoInit();
}

// GET && SET

NGScene* NGMain::get_scene() {
    return _currentScene;
}

void NGMain::set_scene(NGScene* scene) {
    if (_currentScene != nullptr) {
        std::cout << "Call destroy" << std::endl;
        _currentScene->destroy();
        delete _currentScene;
    }

    _currentScene = scene;
    _currentScene->initialize();
}