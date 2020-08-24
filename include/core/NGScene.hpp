#pragma once

#include "DisplayObject.hpp"

#include "Image.hpp"
#include "Movieclip.hpp"

#include "BMFont.hpp"
#include "TextBox.hpp"
#include "Background.hpp"

#include "Image2D.hpp"
#include "Movieclip2D.hpp"

class NGScene {
    public:
        Background background;
        
    private:
        uint8_t _screen;
        uint16_t _numSprite2D;
        uint16_t _numSprite3D;
        
        std::vector<DisplayObject*> children;
    
    public:
        NGScene();
        virtual ~NGScene();

        void preUpdate();

        virtual void initialize() = 0;
        virtual void update() = 0;
        
        virtual void destroy();

        DisplayObject* addChild(DisplayObject* child);
         
        DisplayObject* getChildByName(std::string name);
        DisplayObject* getChildbyId(unsigned int id);
         
        bool removeChild(DisplayObject* child);
        bool removeChildByName(std::string name);
        bool removeChildById(unsigned int id);
        bool removeChildAll();

        // Get && Set

        uint8_t get_screen();
        void set_screen(uint8_t screen);
        
        unsigned int numChildren();
        void printName();

    private:
};