#include "epch.hpp"
#include "Scene.hpp"

EE::Scene::Scene()
    : _type(SceneType::NOT_DEFINED)
{

}

EE::Scene::~Scene() {

}

void EE::Scene::preUpdate() {
    // for (uint i=0; i<children.size(); i++) {
	// 	children[i]->preUpdate();
	// }

	update();
}

void EE::Scene::destroy() {
    // std::cout << "destroy" << std::endl;
	// removeChildAll();
}

// GET && SET

uint8_t EE::Scene::get_screen() {
    return _screen;
}

void EE::Scene::set_screen(uint8_t screen) {
    _screen = screen;
}