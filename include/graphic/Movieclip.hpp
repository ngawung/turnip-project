#pragma once

#include "Image.hpp"

class Movieclip : public Image {
    public:
        int16_t frame;
		int16_t delay;

        bool enableAnimation;
    private:
        std::map<std::string, std::vector<int>> _animationData;
		std::string _currentPlay;
        int16_t _frame;
		int16_t _currentFrame;
		int16_t _currentDelay;

    public:
        Movieclip(std::string name, std::string sprite, std::string pallete);

        void preUpdate() override;

        // Animation stuff
        void addAnimation(std::string name, std::vector<int> frames);
        void updateAnimation(std::string name, std::vector<int> frames);
        void removeAnimation(std::string name);
        void clearAnimation(std::string name);
        void quickPlay(std::vector<int> frames, int frameskip);
        void play(std::string name, int frameskip);
        void stop(std::string name);
        void reset();

    private:
};