#pragma once

#include "DisplayObject.hpp"

class Image : public DisplayObject {
    public:
    protected:
        std::string _sprite;
	    std::string _pallete;
        
        int16_t _x;
        int16_t _y;
        int16_t _rotation;
        int16_t _scaleX;
        int16_t _scaleY;
        int16_t _layer;
        int16_t _visible;
    
    public:
        Image(std::string name, std::string sprite, std::string pallete);

        void preUpdate() override;
        void initialize() override;
        void destroy() override;

    private:
};