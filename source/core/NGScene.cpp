#include "NGScene.hpp"

NGScene::NGScene() {

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
	if (child->isSprite() && DisplayObject::get_numSprite() >= 254) { // 254 instead of 255, sometime it crash when there is 255 sprite in screen
		std::cout << "Max sprite limit reached";
		return nullptr;
	}

	// push child
	children.push_back(child);

	// get the last index
	uint index = children.size() - 1;

	// set child id to last index
	child->set_id(index);

	// initialize child (render)
	child->initialize();

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
	}

	children.clear();
	return true;
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