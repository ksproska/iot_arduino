# include "DiodeHandler.h"

void copyArray(int tabAim[], int tabFrom[], int len) {
    for(int i = 0; i < len; i++) {
        tabAim[i] = tabFrom[i];
    }
}

MyColor::MyColor(String name) {
    if(name == "red") {
        copyArray(rgb, RED, rgbLen);
    }
    else if(name == "green") {
        copyArray(rgb, GREEN, rgbLen);
    }
    else if(name == "blue") {
        copyArray(rgb, BLUE, rgbLen);
    }
    else if(name == "yellow") {
        copyArray(rgb, YELLOW, rgbLen);
    }
    else if(name == "cyan") {
        copyArray(rgb, CYAN, rgbLen);
    }
    else if(name == "magenta") {
        copyArray(rgb, MAGENTA, rgbLen);
    }
    else if(name == "white") {
        copyArray(rgb, WHITE, rgbLen);
    }
    else if(name == "black") {
        copyArray(rgb, BLACK, rgbLen);
    }
};

MyColor::MyColor(int r, int g, int b) {
    rgb[0] = r;
    rgb[1] = g;
    rgb[2] = b;
};

int MyColor::red() {
    return rgb[0];
}

int MyColor::green() {
    return rgb[1];
}

int MyColor::blue() {
    return rgb[2];
}

MyDiode::MyDiode(int pinR, int pinG, int pinB) {
    r = pinR;
    g = pinG;
    b = pinB;
};

void MyDiode::initialize() {
    pinMode(r, OUTPUT);
    pinMode(r, OUTPUT);
    pinMode(r, OUTPUT);

    digitalWrite(r, LOW);
    digitalWrite(r, LOW);
    digitalWrite(r, LOW);
}

void MyDiode::writeRed(int val) {
    analogWrite(r, val);
}

void MyDiode::writeGreen(int val) {
    analogWrite(g, val);
}

void MyDiode::writeBlue(int val) {
    analogWrite(b, val);
}

void MyDiode::writeAll(int valR, int valG, int valB) {
    analogWrite(r, valR);
    analogWrite(g, valG);
    analogWrite(b, valB);
}

void MyDiode::writeMyColor(String color) {
    MyColor myColor(color);
    analogWrite(r, myColor.red());
    analogWrite(g, myColor.green());
    analogWrite(b, myColor.blue());
}
