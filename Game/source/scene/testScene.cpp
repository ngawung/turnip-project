#include <epch.hpp>
#include <simplenfl.h>

#include "testScene.hpp"

EE::Scene1::Scene1() : Scene() {

}

void EE::Scene1::update() {
    if (SNF::getTouchRect(30, 30, 50, 50, SNF::KeyPhase::press)) {
        std::cout << "Touch" << std::endl;
    }
}

// ===============

EE::Scene2::Scene2() : Scene() {

}

void EE::Scene2::update() {
    
}
