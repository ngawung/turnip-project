#pragma once

#include "NGMain.hpp"
#include "NGScene.hpp"

class scene2 : public NGScene {
    public:
        int i;
        Movieclip* mist;
        BMFont* font1;
    private:
    
    public:
        scene2();
        void initialize() override;
        void update() override;
    private:
};