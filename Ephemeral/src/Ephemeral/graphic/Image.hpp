#pragma once

#include "Ephemeral/core/Object.hpp"

namespace EE {

    class Image : public Object {
        public:
            int16_t x;
            int16_t y;
            int16_t rotation;
            int16_t scaleX;
            int16_t scaleY;
            int16_t layer;
            bool visible;
            bool flip;
            int16_t alpha;

        private:
            std::string _gfx;
            std::string _palette;

            int16_t _x;
            int16_t _y;
            int16_t _rotation;
            int16_t _scaleX;
            int16_t _scaleY;
            int16_t _layer;
            bool _visible;
            bool _flip;
            int16_t _alpha;

        public:
            Image(std::string name, std::string gfx, std::string palette, bool isSprite3D);
            virtual ~Image();

            void preUpdate() override;
            void initialize() override;
            void destroy() override;

            virtual void validate();

        private:
    };

}