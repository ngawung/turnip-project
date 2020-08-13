#include <nf_lib.h>

#include "simplenfl.h"

void SNF::loadsprite(int screen, int ramslot, int vramslot, int width, int height, const char *dir, const char *dir2, bool transflag) {
    NF_LoadSpriteGfx(dir, ramslot, width, height);
    NF_LoadSpritePal(dir2, ramslot);
    NF_VramSpriteGfx(screen, ramslot, vramslot, transflag);
    NF_VramSpritePal(screen, ramslot, vramslot);
}

void SNF::loadfont(const char *file, const char *fontname, int width, int height, int rot, int screen, int layer) {
    NF_LoadTextFont(file, fontname, width, height, rot);
    NF_CreateTextLayer(screen, layer, rot, fontname);
}

void SNF::loadbg(const char *dir, const char *name, int width, int height, int screen, int layer) {
    NF_LoadTiledBg(dir, name, width, height);
    NF_CreateTiledBg(screen, layer, name);
}

void SNF::playandloadsound(const char *file, int channel, int freq, int sampleform, int vol, int pan, bool loop, int loopstart) {
    NF_LoadRawSound(file, channel, freq, sampleform);
    NF_PlayRawSound(channel, vol, pan, loop, loopstart);
}

bool SNF::getTouch(KeyPhase phase) {
    touchRead(&Stylus);
    
    switch (phase){
        case KeyPhase::release:
            // store prev stylus because px,py return 0 when KeysUp()
            if (KEY_TOUCH & keysHeld()) PrevStylus = Stylus;

            if (KEY_TOUCH & keysUp()) {
                Stylus = PrevStylus;
                return true;
            }
            else break;
        
        case KeyPhase::press:
            if (KEY_TOUCH & keysDown()) return true;
            else break;

        case KeyPhase::held:
            if (KEY_TOUCH & keysHeld()) return true;
            else break;
    }

    return false;
}

bool SNF::getTouchRect(int x, int y, int width, int height, KeyPhase phase) {
    if (getTouch(phase)) {
        int mathx = x + width;
        int mathy = y + height;
        return Stylus.px > x && Stylus.px < mathx && Stylus.py > y && Stylus.py < mathy;
    }
    return false;
}

bool SNF::overlap(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
    if ((x3 <= x1 && x1 <= x4 && y3 <= y1 && y1 <= y4) ||
        (x3 <= x1 && x1 <= x4 && y3 <= y2 && y2 <= y4) ||
        (x3 <= x2 && x2 <= x4 && y3 <= y1 && y1 <= y4) ||
        (x3 <= x2 && x2 <= x4 && y3 <= y2 && y2 <= y4)) {
        return true;
    }
    return false;
}