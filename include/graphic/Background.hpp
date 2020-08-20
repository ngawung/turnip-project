#include "DisplayObject.hpp"

class Background : public DisplayObject {
    public:
    private:
        int16_t _x;
        int16_t _y;
        bool _visible;
        bool _isExist;

    public:
        Background();
        void preUpdate() override;
        void destroy() override;

        void changeBg(const char* name);
        void removeBg();

        bool isExist();
    private:
};