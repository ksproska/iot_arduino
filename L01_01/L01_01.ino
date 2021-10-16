// Po naciśnięciu przycisku zielonego zmień kolor świecącej diody. Przycisk czerwony włącza i wyłącza świecenie.
#define LED_RED 6
#define LED_GREEN 5
#define LED_BLUE 3

#define RED_BUTTON 2
#define GREEN_BUTTON 4

bool isOn = true;
int number_of_colors = 3;
int current = 0;
int myPins[] = {LED_RED, LED_GREEN, LED_BLUE};
int prev_button_red_level = LOW;
int prev_button_green_level = LOW;


void initRGB()
{
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);

    pinMode(LED_RED, OUTPUT);
    digitalWrite(LED_RED, LOW);

    pinMode(LED_GREEN, OUTPUT);
    digitalWrite(LED_GREEN, LOW);

    pinMode(LED_BLUE, OUTPUT);
    digitalWrite(LED_BLUE, LOW);
}

void initButtons()
{
    pinMode(RED_BUTTON, INPUT_PULLUP);
    pinMode(GREEN_BUTTON, INPUT_PULLUP);
}

void setup()
{
    initRGB();
    initButtons();
}

void loop() {
    if (digitalRead(GREEN_BUTTON) != prev_button_green_level) {
        if (digitalRead(GREEN_BUTTON) == LOW && isOn) {
            digitalWrite(myPins[current], LOW);
            current = (current + 1) % number_of_colors;
            digitalWrite(myPins[current], HIGH);
        }
        prev_button_green_level = !prev_button_green_level;
    }
    
    if (digitalRead(RED_BUTTON) != prev_button_red_level) {
        if (digitalRead(RED_BUTTON) == LOW) {
            isOn = !isOn;
            if (isOn) {
                digitalWrite(myPins[current], HIGH);
            }
            else {
                digitalWrite(myPins[current], LOW);
            }
        }
        prev_button_red_level = !prev_button_red_level;
    }
}
