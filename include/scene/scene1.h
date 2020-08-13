#pragma once

#include "NGScene.h"

class scene1 : public NGScene {
    public:
        int i;
    private:
    
    public:
        scene1();
        void initialize() override;
        void update() override;
    private:
};