// w sposób łagodny będzie zmieniał kolory diody RGB w cyklu, na przykład, czerwony > zielony > niebieski > czerwony ..., wyświetlając kolory pośrednie
#define LED_RED 6
#define LED_GREEN 5
#define LED_BLUE 3

#define RED_BUTTON 2
#define GREEN_BUTTON 4

int value_min = 0;
int value_max = 255;
int jump_size = 5;


int color_pins[] = {LED_RED, LED_GREEN, LED_BLUE};
int color_values[] = {255, 0, 0};
int number_of_colors = 3;
int current_color = 0;
int next_color = (current_color + 1) % number_of_colors;


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


void initRGB() {
    for (int i=0; i < number_of_colors; i++) {
      pinMode(color_pins[i], OUTPUT);
      digitalWrite(color_pins[i], LOW);
    }
}

// void initButtons()
// {
//     pinMode(RED_BUTTON, INPUT_PULLUP);
//     pinMode(GREEN_BUTTON, INPUT_PULLUP);
// }

void setup()
{
    initRGB();
    // initButtons();
}

void loop()
{
  if (color_values[current_color] > 0) {
    color_values[current_color] = decrease_value(color_values[current_color]);
    color_values[next_color] = increase_value(color_values[next_color]);
    analogWrite(color_pins[current_color], color_values[current_color]);
    analogWrite(color_pins[next_color], color_values[next_color]);
  }
  else {
    current_color = next_color;
    next_color = (current_color + 1) % number_of_colors;
  }
  delay(10); //działa
}
