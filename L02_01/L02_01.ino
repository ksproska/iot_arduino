//Napisz program, Program, po naciśnięciu i zwolnieniu jednego z przycisków 
//(zielony i czerwony) ma zgasić zaświeconą diodę
//i zapalić kolejną dokładnie w cyklu R,G,B,R,G,...

#define LED_RED 6
#define LED_GREEN 5
#define LED_BLUE 3

#define RED_BUTTON 2
#define GREEN_BUTTON 4

int led[] = {LED_RED, LED_GREEN, LED_BLUE};

void initRGB()
{
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);

    pinMode(LED_RED, OUTPUT);
    digitalWrite(LED_RED, HIGH);

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

#define DEBOUNCE_PERIOD 10UL

bool isButtonPressedTemplate(int button, int& debounced_button_state, 
int& previous_reading, unsigned long& last_change_time)
{
    bool isPressed = false;

    int current_reading = digitalRead(button);

    if (previous_reading != current_reading)
    {
        last_change_time = millis();
    }

    if (millis() - last_change_time > DEBOUNCE_PERIOD)
    {
        if (current_reading != debounced_button_state)
        {
            if (debounced_button_state == HIGH && current_reading == LOW)
            {
                isPressed = true;
            }
            debounced_button_state = current_reading;
        }
    }

    previous_reading = current_reading;

    return isPressed;
}


bool isGreenButtonPressed() {
    static int debounced_button_state = HIGH;
    static int previous_reading = HIGH;
    static unsigned long last_change_time = 0UL;
    return isButtonPressedTemplate(GREEN_BUTTON, debounced_button_state, 
    previous_reading, last_change_time);
}

bool isRedButtonPressed() {
    static int debounced_button_state = HIGH;
    static int previous_reading = HIGH;
    static unsigned long last_change_time = 0UL;
    return isButtonPressedTemplate(RED_BUTTON, debounced_button_state, 
    previous_reading, last_change_time);
}

bool isButtonReliesedTemplate(int button, int& debounced_button_state, 
int& previous_reading, unsigned long& last_change_time)
{
    bool isReliesed = false;

    int current_reading = digitalRead(button);

    if (previous_reading != current_reading)
    {
        last_change_time = millis();
    }

    if (millis() - last_change_time > DEBOUNCE_PERIOD)
    {
        if (current_reading != debounced_button_state)
        {
            if (debounced_button_state == LOW && current_reading == HIGH)
            {
                isReliesed = true;
            }
            debounced_button_state = current_reading;
        }
    }

    previous_reading = current_reading;

    return isReliesed;
}


bool isGreenButtonReliesed() {
    static int debounced_button_state = LOW;
    static int previous_reading = LOW;
    static unsigned long last_change_time = 0UL;
    return isButtonReliesedTemplate(GREEN_BUTTON, debounced_button_state, 
    previous_reading, last_change_time);
}

bool isRedButtonReliesed() {
    static int debounced_button_state = LOW;
    static int previous_reading = LOW;
    static unsigned long last_change_time = 0UL;
    return isButtonReliesedTemplate(RED_BUTTON, debounced_button_state, 
    previous_reading, last_change_time);
}

bool wasGreenPressedAndReliesed() {
    static bool prev_green = false;
    if (isGreenButtonPressed()) {
        prev_green = true;
    }
    if (prev_green & isGreenButtonReliesed()) {
        prev_green = false;
        return true;
    }
    return false;
}

bool wasRedPressedAndReliesed() {
    static bool prev_red = false;
    if (isRedButtonPressed()) {
        prev_red = true;
    }
    if (prev_red & isRedButtonReliesed()) {
        prev_red = false;
        return true;
    }
    return false;
}

void turnOnNextColor() {
    static int led_index = 0;
    digitalWrite(led[led_index], LOW);
    led_index = ++led_index % 3;
    digitalWrite(led[led_index], HIGH);
}

void setup() {
    initRGB();
    initButtons();
    digitalWrite(led[0], HIGH);
}

void loop() {
    if (wasGreenPressedAndReliesed() || wasRedPressedAndReliesed()) {
        turnOnNextColor();
    }
}