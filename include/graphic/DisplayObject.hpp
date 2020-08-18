#pragma once

#include "NGObject.hpp"

class ObjectBound {
	public:
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
};

class DisplayObject : public NGObject {
    public:
        int16_t x;
        int16_t y;
        int16_t rotation;
        int16_t scaleX;
        int16_t scaleY;
        int16_t layer;
        ObjectBound bound;
		bool visible;

    protected:
		std::string _type;
		static inline uint16_t _numSprite = 0;
    
    public:

        DisplayObject(std::string name);

        bool getTouch(KeyPhase phase);

		// Get && Set

		std::string get_type();

		// static

		static uint16_t get_numSprite();

    private:
};