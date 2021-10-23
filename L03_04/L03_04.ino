// Napisz program, który odczytuje wartość z przetwornika analogowo-cyfrowego, 
// a następnie wysyła przez łącze szeregowe do komputera. Zobacz wynik jego działania 
// przy pomocy narzędzi Serial Monitor i Serial Plotter z Arduino IDE.

#define POTENTIOMETER A0

void initSerial() {
    Serial.begin(9600);
    while (!Serial) {}
}

void setup() {
    initSerial();
}


void loop()
{
    int value = analogRead(POTENTIOMETER);
    String str = String(value);
    Serial.println(str);
}