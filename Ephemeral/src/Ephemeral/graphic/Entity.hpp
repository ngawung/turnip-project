#pragma once

#include "Ephemeral/core/Object.hpp"

namespace EE {

    class Entity : public Object {
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

        public:
            Entity();
            virtual ~Entity();

        private:
    };

}