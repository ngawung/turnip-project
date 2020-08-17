#include "NGObject.hpp"

NGObject::NGObject(std::string name)
	: _name(name)
{
	
}

NGObject::~NGObject() {
	
}

void NGObject::preUpdate() {
	update();
}

void NGObject::destroy() {
	
}

// GET && SET

std::string NGObject::get_name() {
	return _name;
}

void NGObject::set_id(uint16_t id) {
	_id = id;
}

uint16_t NGObject::get_id() {
	return _id;
}

// NGObject::NGObject(std::string name, uint16_t sprite, uint16_t pallete) 
// 	:bound(0, 0, 0, 0)
// {
// 	_name = name;

// 	// graphic
// 	_sprite = sprite;
// 	_pallete = pallete;

// 	// transform
// 	x = _x = 0;
// 	y = _y = 0;
// 	rotation = _rotation = 0;
// 	scaleX = _scaleX = 100;
// 	scaleY = _scaleY = 100;
// 	layer = _layer = -1;

// 	// animation
// 	frame = _frame;
// 	enableUpdate = true;
// 	enableAnimation = false;
// 	delay = _currentDelay = 0;
// }
        
// void NGObject::draw(uint16_t id) {
// 	_id = id;

// 	NF_Create3dSprite(_id, _sprite, _pallete, x, y);
// }

// void NGObject::update() {
// 	if (enableUpdate) {
// 		if (_x != x || _y != y) {
// 			NF_Move3dSprite(_id, x, y);
// 			_x = x;
// 			_y = y;
// 		}

// 		if (_rotation != rotation) {
// 			NF_Rotate3dSprite(_id, 0, 0, TransformObject::rotate(rotation));
// 			_rotation = rotation;
// 		}

// 		if (_scaleX != scaleX || _scaleY != scaleY) {
// 			NF_Scale3dSprite(_id, TransformObject::scale(scaleX), TransformObject::scale(scaleY));
// 			_scaleX = scaleX;
// 			_scaleY = scaleY;
// 		}

// 		if (_layer != layer) {
// 			layer = std::clamp(layer, -512, 512);
// 			NF_3dSpriteSetDeep(_id, -layer);
// 			_layer = layer;
// 		}

// 		if (_frame != frame) {
// 			if (frame < 0) frame = 0;
// 			NF_Set3dSpriteFrame(_id, frame);
// 		}

// 		if (enableAnimation) {
// 			frame = _animationData.find(_currentPlay)->second[_currentFrame];
// 			_currentDelay++;
// 			if (_currentDelay > delay) {
// 				_currentDelay = 0;
// 				_currentFrame++;
// 				if (_currentFrame > ((int)_animationData.find(_currentPlay)->second.size() - 1)) {
// 					_currentFrame = 0;
// 				}
// 			}
// 		}
// 	}
// }

// void NGObject::destroy() {
// 	NF_Delete3dSprite(_id);
// }

// // // Animation stuff

// void NGObject::addAnimation(std::string name, std::vector<int> frames) {
// 	_animationData.insert({name, frames});
// }

// void NGObject::updateAnimation(std::string name, std::vector<int> frames) {
// 	auto it = _animationData.find(name);
// 	if (it != _animationData.end()) {
// 		it->second = frames;
// 	} else {
// 		std::cout << "Cannot find " << name << " animation" << std::endl;
// 	}
// }

// void NGObject::removeAnimation(std::string name) {
// 	_animationData.erase(name);
// }

// void NGObject::clearAnimation(std::string name) {
// 	_animationData.clear();
// 	reset();
// }

// void NGObject::quickPlay(std::vector<int> frames, int frameskip) {
// 	auto it = _animationData.find("_quick");
// 	if (it != _animationData.end()) {
// 		it->second = frames;
// 	} else {
// 		addAnimation("_quick", frames);
// 	}

// 	play("_quick", frameskip);
// }

// void NGObject::play(std::string name, int frameskip) {
// 	auto it = _animationData.find(name);
// 	if (it != _animationData.end()) {
// 		_currentPlay = it->first;
// 		_currentFrame = 0;
// 		frame = it->second[0];
// 		delay = frameskip;
// 		enableAnimation = true;
// 	} else {
// 		std::cout << "Cannot find " << name << " animation" << std::endl;
// 	}
// }

// void NGObject::stop(std::string name) {
// 	auto it = _animationData.find(name);
// 	if (it != _animationData.end()) {
// 		_currentPlay = it->first;
// 		frame = it->second[0];
// 		enableAnimation = false;
// 	} else {
// 		std::cout << "Cannot find " << name << " animation" << std::endl;
// 	}
// }

// void NGObject::reset() {
// 	frame = 0;
// 	enableAnimation = false;
// }

// // Touch
// bool NGObject::getTouch(KeyPhase phase) {
// 	if (bound.x == 0 && bound.y == 0 && bound.width == 0 && bound.height == 0) {
// 		if (SNF::getTouch(phase))
// 			std::cout << "Please set sprite '" << getName() << "(" << getId() << ")' bound first!" << std::endl;
		
// 		return false;
// 	}

// 	return SNF::getTouchRect(
// 		x + bound.x,
// 		y + bound.y,
// 		bound.width,
// 		bound.height,
// 		phase
// 	);
// }

// // Basic tool

// std::string NGObject::getName() {
// 	return _name;
// }

// uint16_t NGObject::getId() {
// 	return _id;
// }