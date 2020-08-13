#pragma once

#include <map>
#include <string>
#include <vector>

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

        // Basic tool
        std::string getName();
        uint16_t getId();
    private:
};