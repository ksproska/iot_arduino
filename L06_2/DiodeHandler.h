#ifndef DIODEHANDLER_H_
#define DIODEHANDLER_H_

#include "Arduino.h"

class MyColor {
    public:
        MyColor(String name);
        MyColor(int r, int g, int b);

        int red();
        int green();
        int blue();
    
    private:
        int rgbLen = 3;
        int rgb[3] = {-1, -1, -1};
        int RED[3] = {255, 0, 0};
        int GREEN[3] = {0, 255, 0};
        int BLUE[3] = {0, 0, 255};
        int YELLOW[3] = {255, 255, 0};
        int CYAN[3] = {0, 255, 255};
        int MAGENTA[3] = {255, 0, 255};
        int BLACK[3] = {0, 0, 0};
        int WHITE[3] = {255, 255, 255};
};

class MyDiode {
    public:
        MyDiode(int pinR, int pinG, int pinB);

        void initialize();

        void writeRed(int val);
        void writeGreen(int val);
        void writeBlue(int val);

        void writeAll(int valR, int valG, int valB);
        void writeMyColor(String color);

    private:
        int r, g, b;
};

#endif
