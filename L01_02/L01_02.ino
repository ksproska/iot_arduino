// dioda zielona, po przytrzymaniu przycisku zielonego dioda będzie rozjaśniała się, a po przytrzymaniu czerwonego będzie ściemniana
#define LED_RED 6
#define LED_GREEN 5
#define LED_BLUE 3

#define RED_BUTTON 2
#define GREEN_BUTTON 4

int current_value = 0;
int value_min = 0;
int value_max = 255;
int jump_size = 5;


void initRGB()
{
    // pinMode(LED_BUILTIN, OUTPUT);
    // digitalWrite(LED_BUILTIN, LOW);

    // pinMode(LED_RED, OUTPUT);
    // digitalWrite(LED_RED, LOW);

    // pinMode(LED_GREEN, OUTPUT);
    // digitalWrite(LED_GREEN, LOW);

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

int decrease_value(int inn_current) {
    if (inn_current - jump_size >= value_min) {
            inn_current = inn_current - jump_size;
        }
        else {
            inn_current = value_min;
        }
    return inn_current;
}

int increase_value(int inn_current) {
    if (inn_current + jump_size <= value_max) {
            inn_current = inn_current + jump_size;
        }
        else {
            inn_current = value_max;
        }
    return inn_current;
}

void loop()
{
    if (digitalRead(GREEN_BUTTON) == LOW && current_value < value_max) {
        current_value = increase_value(current_value);
        analogWrite(LED_BLUE, current_value);
    }
    
    if (digitalRead(RED_BUTTON) == LOW && current_value > value_min) {
        current_value = decrease_value(current_value);
        analogWrite(LED_BLUE, current_value);
    }
    delay(50); //gotowe
}
