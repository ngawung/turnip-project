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

class SNF {
    public:
    
        enum KeyPhase { release, press, held };

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

        // check rectangle overlap
        static bool overlap(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
};

    
// ====================================//
// this function broken on my env...
// too lazy to fix
// ====================================//

// u16 Pressed;
// u16 Held;
// u16 Released;

// const char *A = "A";
// const char *B = "B";
// const char *X = "X";
// const char *Y = "Y";
// const char *UP = "UP";
// const char *DOWN = "DOWN";
// const char *LEFT = "LEFT";
// const char *RIGHT = "RIGHT";
// const char *R = "R";
// const char *L = "L";
// const char *SELECT = "SELECT";
// const char *START = "START";
// const char *PRESS = "press";
// const char *HELD = "held";
// const char *RELEASE = "release";

// const char* keyup = "keyup";
// const char* keydown = "keydown";
// const char* keyheld = "keyheld";

// bool ispressed(const char *button, const char *type);

// bool ispressed(const char *button, const char *type) {
//     scanKeys();
//     Pressed = keysDown();
//     Held = keysHeld();
//     Released = keysUp();
//     switch(button){
//         case A:
//         switch(type){
//             case PRESS:
//             if (KEY_A & Pressed) {
//                 return true;
//             } else {
//                 return false;
//             }
//             break;
//             case HELD:
//             if (KEY_A & Held) {
//                 return true;
//             } else {
//                 return false;
//             }
//             break;
//             case RELEASE:
//             if (KEY_A & Released) {
//                 return true;
//             } else {
//                 return false;
//             }
//             break;

//         }
//         break;

//         case B:
//         switch(type){
//             case PRESS:
//             if (KEY_B & Pressed) {
//                 return true;
//             } else {
//                 return false;
//             }
//             break;
//             case HELD:
//             if (KEY_B & Held) {
//                 return true;
//             } else {
//                 return false;
//             }
//             break;
//             case RELEASE:
//             if (KEY_B & Released) {
//                 return true;
//             } else {
//                 return false;
//             }
//             break;

//         }
//         break;

//         case X:
//         switch(type){
//             case PRESS:
//             if (KEY_X & Pressed) {
//                 return true;
//             } else {
//                 return false;
//             }
//             break;
//             case HELD:
//             if (KEY_X & Held) {
//                 return true;
//             } else {
//                 return false;
//             }
//             break;
//             case RELEASE:
//             if (KEY_X & Released) {
//                 return true;
//             } else {
//                 return false;
//             }
//             break;

//         }
//         break;

//         case Y:
//         switch(type){
//             case PRESS:
//             if (KEY_Y & Pressed) {
//                 return true;
//             } else {
//                 return false;
//             }
//             break;
//             case HELD:
//             if (KEY_Y & Held) {
//                 return true;
//             } else {
//                 return false;
//             }
//             break;
//             case RELEASE:
//             if (KEY_Y & Released) {
//                 return true;
//             } else {
//                 return false;
//             }
//             break;

//         }
//         break;


//         case L:
//         switch(type){
//             case PRESS:
//             if (KEY_L & Pressed) {
//                 return true;
//             } else {
//                 return false;
//             }
//             break;
//             case HELD:
//             if (KEY_L & Held) {
//                 return true;
//             } else {
//                 return false;
//             }
//             break;
//             case RELEASE:
//             if (KEY_L & Released) {
//                 return true;
//             } else {
//                 return false;
//             }
//             break;

//         }
//         break;
         
//         case R:
//         switch(type){
//             case PRESS:
//             if (KEY_R & Pressed) {
//                 return true;
//             } else {
//                 return false;
//             }
//             break;
//             case HELD:
//             if (KEY_R & Held) {
//                 return true;
//             } else {
//                 return false;
//             }
//             break;
//             case RELEASE:
//             if (KEY_R & Released) {
//                 return true;
//             } else {
//                 return false;
//             }
//             break;

//         }
//         break;
        

//         case UP:
//         switch(type){
//             case PRESS:
//             if (KEY_UP & Pressed) {
//                 return true;
//             } else {
//                 return false;
//             }
//             break;
//             case HELD:
//             if (KEY_UP & Held) {
//                 return true;
//             } else {
//                 return false;
//             }
//             break;
//             case RELEASE:
//             if (KEY_UP & Released) {
//                 return true;
//             } else {
//                 return false;
//             }
//             break;

//         }
//         break;

//         case DOWN:
//         switch(type){
//             case PRESS:
//             if (KEY_DOWN & Pressed) {
//                 return true;
//             } else {
//                 return false;
//             }
//             break;
//             case HELD:
//             if (KEY_DOWN & Held) {
//                 return true;
//             } else {
//                 return false;
//             }
//             break;
//             case RELEASE:
//             if (KEY_DOWN & Released) {
//                 return true;
//             } else {
//                 return false;
//             }
//             break;

//         }
//         break;

//         case LEFT:
//         switch(type){
//             case PRESS:
//             if (KEY_LEFT & Pressed) {
//                 return true;
//             } else {
//                 return false;
//             }
//             break;
//             case HELD:
//             if (KEY_LEFT & Held) {
//                 return true;
//             } else {
//                 return false;
//             }
//             break;
//             case RELEASE:
//             if (KEY_LEFT & Released) {
//                 return true;
//             } else {
//                 return false;
//             }
//             break;

//         }
//         break;

//         case RIGHT:
//         switch(type){
//             case PRESS:
//             if (KEY_RIGHT & Pressed) {
//                 return true;
//             } else {
//                 return false;
//             }
//             break;
//             case HELD:
//             if (KEY_RIGHT & Held) {
//                 return true;
//             } else {
//                 return false;
//             }
//             break;
//             case RELEASE:
//             if (KEY_RIGHT & Released) {
//                 return true;
//             } else {
//                 return false;
//             }
//             break;

//         }
//         break;

//         case SELECT:
//         switch(type){
//             case PRESS:
//             if (KEY_SELECT & Pressed) {
//                 return true;
//             } else {
//                 return false;
//             }
//             break;
//             case HELD:
//             if (KEY_SELECT & Held) {
//                 return true;
//             } else {
//                 return false;
//             }
//             break;
//             case RELEASE:
//             if (KEY_SELECT & Released) {
//                 return true;
//             } else {
//                 return false;
//             }
//             break;

//         }
//         break;

//         case START:
//         switch(type){
//             case PRESS:
//             if (KEY_START & Pressed) {
//                 return true;
//             } else {
//                 return false;
//             }
//             break;
//             case HELD:
//             if (KEY_START & Held) {
//                 return true;
//             } else {
//                 return false;
//             }
//             break;
//             case RELEASE:
//             if (KEY_START & Released) {
//                 return true;
//             } else {
//                 return false;
//             }
//             break;

//         }
//         break;

//     }
    
// }