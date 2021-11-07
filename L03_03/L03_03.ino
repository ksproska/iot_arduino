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

void displayAuto(String int_val, String other) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(int_val);
    lcd.setCursor(0,1);
    lcd.print(other);
}

int value = -1;
void loop()
{
    int value_new = analogRead(POTENTIOMETER);
    int other = value_new;
    value_new = map(value_new, 0, 1023, 0, 500);
    if(value != value_new) {
      value = value_new;
      double temp = value;
      temp = temp/100;
      displayAuto(String(temp), String(other));
    }
    delay(100);
}
