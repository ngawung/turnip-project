// ===================== //
//  !!Modified version!! //
//      Version 1.0      //
// ===================== //

//SimpleNFL - Version 1.65
//By Pipewarp 
//With Help from PolyMars and SkilLP
//https://github.com/PipeWarp/SimpleNFL/
//
//Licensed under Creative Commons Attribution-NonCommercial 3.0
//Read it here: https://github.com/PipeWarp/SimpleNFL/blob/master/LICENSE
//
//The Docs/wiki is in the github repository
//Have fun!

#pragma once

enum Key {
    UP, DOWN, LEFT, RIGHT,
    START, SELECT,
    A, B, X, Y,
    R, L
};

enum KeyPhase { release, press, held };

class SNF {
    public:
        static inline touchPosition Stylus;
        static inline touchPosition PrevStylus; // previous frame stylus position

        // quick load sprite
        static void loadsprite(int screen, int ramslot, int vramslot, int width, int height, const char *dir, const char *dir2, bool transflag);
        
        // quick load bmfont
        static void loadfont(const char *file, const char *fontname, int width, int height, int rot, int screen, int layer);
        
        // quick load bg
        static void loadbg(const char *dir, const char *name, int width, int height, int screen, int layer);
        
        // quick play sound
        static void playandloadsound(const char *file, int channel, int freq, int sampleform, int vol, int pan, bool loop, int loopstart);

        // get touch by KeyPhase
        static bool getTouch(KeyPhase phase);

        // get touch by Rectangle
        static bool getTouchRect(int x, int y, int width, int height, KeyPhase phase);
        
          // get touch by Circle
        static bool getTouchCircle(int x, int y, int radius, KeyPhase phase);

        // check rectangle overlap
        static bool overlap(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);

        static bool getKeys(Key key, KeyPhase phase);
};