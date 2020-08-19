#pragma once

#include "Image.hpp"

class Image2D : public Image {
    public:
    private:
    
    public:
        Image2D(std::string name, std::string sprite, std::string pallete);

        void preUpdate() override;
        void initialize() override;
        void destroy() override;
        
    private:
};