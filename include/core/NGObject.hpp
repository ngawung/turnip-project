#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>

#include <nds.h>
#include <nf_lib.h>

#include "simplenfl.hpp"
#include "STween.hpp"
#include "Random.hpp"
#include "Assets.hpp"
#include "TransformObject.hpp"
#include "SaveGame.hpp"


typedef struct ObjectBound {
	uint16_t x;
	uint16_t y;
	uint16_t width;
	uint16_t height;

	ObjectBound(uint16_t _x, uint16_t _y, uint16_t _width, uint16_t _height)
		: x(_x), y(_y), width(_width), height(_height)
	{

	}

	void set(uint16_t x, uint16_t y, uint16_t width, uint16_t height) {
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
	}
} ObjectBound;

class NGObject {
    public:
        int x;
		int y;
		int rotation;
		int scaleX;
		int scaleY;
		int layer;
		int frame;
		int delay;
		ObjectBound bound;

		bool enableUpdate;
		bool enableAnimation;

		static int objectNum;
    private:
        int _x;
		int _y;
		int _rotation;
		int _scaleX;
		int _scaleY;
		int _layer;
		int _frame;

		std::map<std::string, std::vector<int>> _animationData;
		std::string _currentPlay;
		int _currentFrame;
		int _currentDelay;

		std::string _name;
		uint16_t _sprite;
		uint16_t _pallete;
		uint16_t _id;
    
    public:
        NGObject(std::string name, uint16_t sprite, uint16_t pallete);
        
        void draw(uint16_t id);
        void update();
        void destroy();

        // Animation stuff
        void addAnimation(std::string name, std::vector<int> frames);
        void updateAnimation(std::string name, std::vector<int> frames);
        void removeAnimation(std::string name);
        void clearAnimation(std::string name);
        void quickPlay(std::vector<int> frames, int frameskip = 0);
        void play(std::string name, int frameskip = 0);
        void stop(std::string name);
        void reset();

		// Touch
		bool getTouch(KeyPhase phase);

        // Basic tool
        std::string getName();
        uint16_t getId();
    private:
};