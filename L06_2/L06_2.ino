// Zadanie 2: Implementacja własnej biblioteki ze sterownikiem wybranego urządzenia

// Przygotuj własną bibliotekę, która będzie służyła do sterowania diodą RGB. 
// Samodzielnie zaprojektuj interfejs programistyczny tej biblioteki, tak aby pozwalał podać, 
// do których pinów podłączona jest dioda, oraz aby pozwalał ustawiać kolory
// poprzez podanie wartości komponentów RGB oraz przez nazwy kolorów: 
// RED, GREEN, BLUE, YELLOW, CYAN, MAGENTA, BLACK, WHITE. 
// Zadbaj o kolorowanie składni w Arduino IDE.
// Jest to zadanie przykładowe. Prowadzący może zmodyﬁkować lub zmienić treść zadania.

#include "DiodeHandler.h"

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
