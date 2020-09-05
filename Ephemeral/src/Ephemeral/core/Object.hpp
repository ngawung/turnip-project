#pragma once

#include <string>

namespace EE {

    enum class ObjectCategory {
        NONE = 0,
        SPRITE2D, SPRITE3D , BACKGROUND ,BMFONT
    };

    class Object {
        public:
            bool enableUpdate;

        protected:
            std::string _name;
            uint16_t _id;
            uint8_t _screen;
            ObjectCategory _type;
        
        public:
            Object(std::string name);
            virtual ~Object();

            virtual void preUpdate();

            virtual void initialize() = 0;
            virtual void update() = 0;
            
            virtual void destroy();

             // Get && Set
            std::string get_name();

            ObjectCategory get_category();

            void set_id(uint16_t id);
            uint16_t get_id();

            void set_screen(uint16_t screen);
            uint16_t get_screen();

        private:
    };

}