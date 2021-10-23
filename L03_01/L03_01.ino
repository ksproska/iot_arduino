// Napisz program, który będzie wysyłał informację o stanie przycisków czerwonego i 
// zielonego przez łącze szeregowe do komputera PC. Sprawdź jaką maksymalną szybkość 
// transmisji danych możesz skonﬁgurować. Spróbuj zwizualizować stany
// przycisków na wykresie w Serial Plotter

#define RED_BUTTON 2
#define GREEN_BUTTON 4

void initButtons()
{
    pinMode(RED_BUTTON, INPUT_PULLUP);
    pinMode(GREEN_BUTTON, INPUT_PULLUP);
}

void setup() {
    initButtons();
    Serial.begin(9600);
    while (!Serial) {}
}


void loop()
{
    double r = digitalRead(RED_BUTTON);
    double g = digitalRead(GREEN_BUTTON);
    String str = String(r) + " " + String(g);
    Serial.println(str);
}