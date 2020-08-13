#include <iostream>

#include "NGScene.h"

NGScene::NGScene() {

}

NGScene::~NGScene() {

}

void NGScene::preUpdate() {
	for (uint i=0; i<children.size(); i++) {
		children[i]->update();
	}

	update();
}

void NGScene::destroy() {
	std::cout << "destroy" << std::endl;
	removeChildAll();
}

NGObject* NGScene::addChild(NGObject* child) {
	if (children.size() == 254) { // sometime it crash when there is 255 sprite in screen
		std::cout << "Max child size reached";
		return nullptr;
	}

	// push child
	children.push_back(child);

	// get the last index
	uint index = children.size() - 1;

	// render child
	child->draw(index);

	// return child pointer
	return child;
}
        
NGObject* NGScene::getChildByName(std::string name) {
	for (unsigned int i=0; i<children.size(); i++) { 
		if (children[i]->getName() == name) {
			return children[i];
		}
	}
	
	return nullptr;
}

NGObject* NGScene::getChildbyId(unsigned int id) {
	if (id >= children.size()) return nullptr;
	else return children[id];
}

bool NGScene::removeChild(NGObject* child) {
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
	NGObject* ptr = getChildByName(name);
	if (ptr != nullptr) {
		removeChild(ptr);
		return true;
	} else {
		std::cout << "Failed to remove " << name << std::endl;
		return false;
	}
}

bool NGScene::removeChildById(unsigned int id) {
	NGObject* ptr = getChildbyId(id);

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
		std::cout << children[i]->getId() << ":" << children[i]->getName() << " " << children[i]->x << ":" << children[i]->y << std::endl;
	}
}