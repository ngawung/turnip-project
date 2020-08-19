#include "NGScene.hpp"

NGScene::NGScene() 
	: _numSprite2D(0), _numSprite3D(0)
{

}

NGScene::~NGScene() {

}

void NGScene::preUpdate() {
	for (uint i=0; i<children.size(); i++) {
		children[i]->preUpdate();
	}

	update();
}

void NGScene::destroy() {
	std::cout << "destroy" << std::endl;
	removeChildAll();
}

DisplayObject* NGScene::addChild(DisplayObject* child) {
	// limit sprite on screen

	if (child->get_type() == "Sprite3D" && _numSprite3D >= 254) { // 254 instead of 255, sometime it crash when there is 255 sprite in screen
		std::cout << "Max Sprite3D limit reached" << std::endl;
		return nullptr;
	} else if (child->get_type() == "Sprite2D" && _numSprite3D >= 127) { // 127 instead of 128, sometime it crash when there is 128 sprite in screen
		std::cout << "Max Sprite2D limit reached" << std::endl;
		return nullptr;
	}

	// push child
	children.push_back(child);

	// get the last index
	uint index = children.size() - 1;

	// set child id to last index
	child->set_id(index);

	// set child screen
	child->screen = get_screen();

	// initialize child (render)
	child->initialize();

	// incrase num
	if (child->get_type() == "Sprite3D") _numSprite3D++;
	if (child->get_type() == "Sprite2D") _numSprite2D++;

	// return child pointer
	return child;
}
        
DisplayObject* NGScene::getChildByName(std::string name) {
	for (unsigned int i=0; i<children.size(); i++) { 
		if (children[i]->get_name() == name) {
			return children[i];
		}
	}
	
	return nullptr;
}

DisplayObject* NGScene::getChildbyId(unsigned int id) {
	if (id >= children.size()) return nullptr;
	else return children[id];
}

bool NGScene::removeChild(DisplayObject* child) {
	for (unsigned int i=0; i<children.size(); i++) {
		if (children[i] == child) {
			// decrease num
			if (child->get_type() == "Sprite3D") _numSprite3D--;
			if (child->get_type() == "Sprite2D") _numSprite2D--;
			
			child->destroy();
			children.erase(children.begin() + i);
			delete child;
			return true;
		}
	}
	std::cout << "Failed to remove child" << std::endl;
	return false;
}

bool NGScene::removeChildByName(std::string name) {
	DisplayObject* ptr = getChildByName(name);
	if (ptr != nullptr) {
		removeChild(ptr);
		return true;
	} else {
		std::cout << "Failed to remove " << name << std::endl;
		return false;
	}
}

bool NGScene::removeChildById(unsigned int id) {
	DisplayObject* ptr = getChildbyId(id);

	if (ptr != nullptr) {
		removeChild(ptr);
		return true;
	} else {
		std::cout << "Failed to remove id " << id << std::endl;
		return false;
	}
}

bool NGScene::removeChildAll() {
	for (unsigned int i=0; i<children.size(); i++) {
		children[i]->destroy();
		delete children[i];

		_numSprite3D = _numSprite2D = 0;
	}

	children.clear();
	return true;
}

// GET && SET

uint8_t NGScene::get_screen() {
	return _screen;
}

void NGScene::set_screen(uint8_t screen) {
	_screen = screen;
}

unsigned int NGScene::numChildren() {
	return children.size();
}

// Basic Tools

void NGScene::printName() {
	for (unsigned int i=0; i<children.size(); i++) { 
		std::cout << children[i]->get_id() << ":" << children[i]->get_name() << std::endl;
	}
}