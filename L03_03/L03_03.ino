// Napisz program, który dla napięcia zadanego potencjometrem, na wyświetlaczu LCD wyświetli 
// wartość, którą odczytał ADC i rzeczywistą wartość napięcia zadanego potencjometrem.
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#define POTENTIOMETER A0

void initLCD()
{
  lcd.init();
  lcd.clear();
  lcd.backlight();
}

void setup()
{
    initLCD();
}

void displayInt(int int_val) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(int_val);
}

int value = -1;
void loop()
{
    int value_new = analogRead(POTENTIOMETER);
    if(value != value_new) {
      value = value_new;
      displayInt(value);
    }
}