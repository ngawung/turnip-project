#pragma once

#include "Image.hpp"

class Movieclip : public Image {
    public:
        int16_t frame;
		int16_t delay;

        bool enableUpdate;
        bool enableAnimation;
    private:
        std::map<std::string, std::vector<uint16_t>> _animationData;
		std::string _currentPlay;
		int16_t _currentFrame;
		int16_t _currentDelay;

    public:
        Movieclip(std::string name, std::string sprite, std::string pallete);

        void preUpdate() override;

    private:
};