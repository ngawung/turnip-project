#include "epch.hpp"
#include "App.hpp"

#include <nf_lib.h>

namespace EE {

    App::App() {

    }

    App::~App() {

    }

    void App::start() {
        NF_Set2D(0, 0);
        NF_Set2D(1, 0);

        NF_SetRootFolder("NITROFS");

        consoleDemoInit();

        std::cout << "Hello World" << std::endl;

        while(true) {
            scanKeys();
            swiWaitForVBlank();
        }
    }

}