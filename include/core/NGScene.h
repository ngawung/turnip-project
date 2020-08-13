#pragma once

#include <vector>

#include <nds.h>
#include <nf_lib.h>

#include "NGObject.h"

class NGScene {
    public:
    private:
        std::vector<NGObject*> children;
    
    public:
        NGScene();
        virtual ~NGScene();

        void preUpdate();

        virtual void initialize() = 0;
        virtual void update() = 0;
        
        void destroy();

        NGObject* addChild(NGObject* child);
        
        NGObject* getChildByName(std::string name);
        NGObject* getChildbyId(unsigned int id);
        
        bool removeChild(NGObject* child);
        bool removeChildByName(std::string name);
        bool removeChildById(unsigned int id);
        bool removeChildAll();
        
        unsigned int numChildren();
        void printName();

    private:
};