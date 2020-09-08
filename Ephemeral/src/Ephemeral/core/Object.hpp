#pragma once

#include <string>

namespace EE {

    enum class ObjectCategory {
        NONE = 0,
        SPRITE2D, SPRITE3D , TILEDBG ,BMFONT
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
            std::string get_name() { return _name; }

            ObjectCategory get_type() { return _type; }

            void set_id(uint16_t id) { _id = id; }
            uint16_t get_id() { return _id; }

            void set_screen(uint16_t screen) { _screen = screen; }
            uint16_t get_screen() { return _screen; }

        private:
    };

}