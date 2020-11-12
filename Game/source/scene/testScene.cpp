#include <epch.hpp>
#include <simplenfl.h>

#include "testScene.hpp"

EE::Scene1::Scene1() : Scene() {

}

void EE::Scene1::update() {
    if (SNF::getKeys(SNF::Key::L, SNF::KeyPhase::release)) {
        App::get_instance()->set_mainScene(new Scene2);
    }
}

// ===============

EE::Scene2::Scene2() : Scene() {

}

void EE::Scene2::update() {
    if (SNF::getKeys(SNF::Key::L, SNF::KeyPhase::release)) {
        App::get_instance()->set_mainScene(new Scene1);
    }
}
