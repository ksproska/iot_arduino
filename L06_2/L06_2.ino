// Zadanie 2: Implementacja własnej biblioteki ze sterownikiem wybranego urządzenia

// Przygotuj własną bibliotekę, która będzie służyła do sterowania diodą RGB. 
// Samodzielnie zaprojektuj interfejs programistyczny tej biblioteki, tak aby pozwalał podać, 
// do których pinów podłączona jest dioda, oraz aby pozwalał ustawiać kolory
// poprzez podanie wartości komponentów RGB oraz przez nazwy kolorów: 
// RED, GREEN, BLUE, YELLOW, CYAN, MAGENTA, BLACK, WHITE. 
// Zadbaj o kolorowanie składni w Arduino IDE.
// Jest to zadanie przykładowe. Prowadzący może zmodyﬁkować lub zmienić treść zadania.

void copyArray(int tabAim[], int tabFrom[], int len) {
    for(int i = 0; i < len; i++) {
        tabAim[i] = tabFrom[i];
    }
}

class MyColor {
    public:
        MyColor(String name) {
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
        MyColor(int r, int g, int b) {
            rgb[0] = r;
            rgb[1] = g;
            rgb[2] = b;
        };

        int red() {
            return rgb[0];
        }

        int green() {
            return rgb[1];
        }

        int blue() {
            return rgb[2];
        }
    
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
        MyDiode(int pinR, int pinG, int pinB) {
            r = pinR;
            g = pinG;
            b = pinB;
        };

        void initialize() {
            pinMode(r, OUTPUT);
            pinMode(r, OUTPUT);
            pinMode(r, OUTPUT);

            digitalWrite(r, LOW);
            digitalWrite(r, LOW);
            digitalWrite(r, LOW);
        }

        void writeRed(int val) {
            analogWrite(r, val);
        }

        void writeGreen(int val) {
            analogWrite(g, val);
        }

        void writeBlue(int val) {
            analogWrite(b, val);
        }

        void writeAll(int valR, int valG, int valB) {
            analogWrite(r, valR);
            analogWrite(g, valG);
            analogWrite(b, valB);
        }

        void writeMyColor(String color) {
            MyColor myColor(color);
            analogWrite(r, myColor.red());
            analogWrite(g, myColor.green());
            analogWrite(b, myColor.blue());
        }

    private:
        int r, g, b;
};


MyDiode myDiode(6, 5, 3);
void setup() {
    myDiode.initialize();
}

void loop() {
    myDiode.writeMyColor("red");
    delay(1000);
    myDiode.writeMyColor("green");
    delay(1000);
    myDiode.writeMyColor("blue");
    delay(1000);
    myDiode.writeMyColor("yellow");
    delay(1000);
    myDiode.writeMyColor("cyan");
    delay(1000);
    myDiode.writeMyColor("magenta");
    delay(1000);
    myDiode.writeMyColor("white");
    delay(1000);
    myDiode.writeMyColor("black");
    delay(1000);
    myDiode.writeAll(50, 34, 77);
    delay(1000);
}
