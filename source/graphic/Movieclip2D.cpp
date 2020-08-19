#include "Movieclip2D.hpp"

Movieclip2D::Movieclip2D(std::string name, std::string sprite, std::string pallete) 
    : Image2D(name, sprite, pallete), frame(0), delay(0), enableAnimation(true), _frame(frame), _currentFrame(frame), _currentDelay(delay)
{

}

void Movieclip2D::preUpdate() {
    if (delay < 0) delay = 0;
	
    if (_frame != frame) {
        if (frame < 0) frame = 0;
        NF_SpriteFrame(1, _id, frame);
        _frame = frame;
    }

    if (enableAnimation) {
        frame = _animationData.find(_currentPlay)->second[_currentFrame];
        _currentDelay++;
        if (_currentDelay > delay) {
            _currentDelay = 0;
            _currentFrame++;
            if (_currentFrame > ((int)_animationData.find(_currentPlay)->second.size() - 1)) {
                _currentFrame = 0;
            }
        }
    }

    Movieclip2D::Image2D::preUpdate();
}

// Animation stuff
void Movieclip2D::addAnimation(std::string name, std::vector<int> frames) {
    _animationData.insert({name, frames});
}

void Movieclip2D::updateAnimation(std::string name, std::vector<int> frames) {
    auto it = _animationData.find(name);
	if (it != _animationData.end()) {
		it->second = frames;
	} else {
		std::cout << "Cannot find " << name << " animation" << std::endl;
	}
}

void Movieclip2D::removeAnimation(std::string name) {
    _animationData.erase(name);
}

void Movieclip2D::clearAnimation(std::string name) {
    _animationData.clear();
}

void Movieclip2D::quickPlay(std::vector<int> frames, int frameskip) {
    auto it = _animationData.find("_quick");
	if (it != _animationData.end()) {
		it->second = frames;
	} else {
		addAnimation("_quick", frames);
	}

	play("_quick", frameskip);
}

void Movieclip2D::play(std::string name, int frameskip) {
    auto it = _animationData.find(name);
	if (it != _animationData.end()) {
		_currentPlay = it->first;
		_currentFrame = 0;
		frame = it->second[0];
		delay = frameskip;
		enableAnimation = true;
	} else {
		std::cout << "Cannot find " << name << " animation" << std::endl;
	}
}

void Movieclip2D::stop(std::string name) {
    auto it = _animationData.find(name);
	if (it != _animationData.end()) {
		_currentPlay = it->first;
		frame = it->second[0];
		enableAnimation = false;
	} else {
		std::cout << "Cannot find " << name << " animation" << std::endl;
	}
}

void Movieclip2D::reset() {
    frame = 0;
	enableAnimation = false;
}