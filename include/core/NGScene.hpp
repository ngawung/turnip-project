#pragma once

#include "DisplayObject.hpp"

class NGScene {
    public:
    private:
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
        
        unsigned int numChildren();
        void printName();

    private:
};