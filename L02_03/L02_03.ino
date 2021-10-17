// Napisz program, który będzie działał jako stoper elektroniczny, 
// podając czas na wyświetlaczu LCD. Klawisz zielony uruchamia
// i zatrzymuje stoper. Klawisz czerwony zatrzymuje stoper jeśli działał, 
// i resetuje wartość czasu do wartości 0. Precyzja pomiaru
// to 1 sekunda.

// na rzecz symulatora:
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define RED_BUTTON A0
#define GREEN_BUTTON A1
#define DEBOUNCE_PERIOD 1000UL

unsigned long last_time_break = 0UL;
unsigned long previous_time_sum = 0UL;
bool isTimerRunning = false;

void initButtons()
{
    pinMode(RED_BUTTON, INPUT_PULLUP);
    pinMode(GREEN_BUTTON, INPUT_PULLUP);
}

// void initLCD()
// {
//   lcd.init();
//   lcd.clear();
//   lcd.backlight();
// }

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


void setup() {
    initButtons();
    // initLCD();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Ready");
}

void displayString(String str_val) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(str_val);
}

void displayValue(unsigned long current_time) {
  static unsigned long last_displayed = 0UL;
  if (last_displayed != current_time) {
    lcd.clear();
    lcd.setCursor(0,0);
    int secs = current_time/1000;
    int mins = secs/60;
    secs = secs - 60*mins;
    lcd.print(mins);
    lcd.print(":");
    if (secs < 10) {
      lcd.print(0);
    }
    lcd.print(secs);
    last_displayed = current_time;
  }
  
}

void displayUpdatedTime() {
  static unsigned long temp_measurement = 0UL;
  if (millis() - temp_measurement > DEBOUNCE_PERIOD) {
    temp_measurement = millis();
    if (isTimerRunning) {
      displayValue(millis() - last_time_break + previous_time_sum);
    }
    else {
      displayValue(previous_time_sum);
    }
  }
}

void startTimer() {
  last_time_break = millis();
  isTimerRunning = true;
}
 
void stopTimer() {
  unsigned long last_measurement = millis() - last_time_break;
  previous_time_sum += last_measurement;
  isTimerRunning = false;
}

void resetTimer() {
  isTimerRunning = false;
  previous_time_sum = 0UL;
}

void loop() {
  static bool wasGreenReliesed = true;
  static bool wasRedReliesed = true;

  if (isGreenButtonPressed() && wasGreenReliesed) {
    isTimerRunning = !isTimerRunning;
    wasGreenReliesed = false;
    if(isTimerRunning) {
      startTimer();
      displayString("start");
    }
    else {
      stopTimer();
      displayString("stop");
    }
  }
  if (isGreenButtonReliesed()){
    wasGreenReliesed = true;
  }
  

  if (isRedButtonPressed() && wasRedReliesed) {
    wasRedReliesed = false;
    resetTimer();
    displayString("reset");
  }
  if (isRedButtonReliesed()) {
    wasRedReliesed = true;
  }
  
  displayUpdatedTime();
}
