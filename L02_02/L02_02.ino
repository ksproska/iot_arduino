#define LED_RED 6
#define LED_GREEN 5
#define LED_BLUE 3

#define RED_BUTTON 2
#define GREEN_BUTTON 4

#define DEBOUNCE_RED 900UL
#define DEBOUNCE_GREEN 1000UL
#define DEBOUNCE_BLUE 1100UL

int led[] = {LED_RED, LED_GREEN, LED_BLUE};
const unsigned long debounce[] = {DEBOUNCE_RED, DEBOUNCE_GREEN, DEBOUNCE_BLUE};

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

void setup()
{
    initRGB();
    initButtons();
}

void turnOnOneAndOffOthers(int led_inx) {
  digitalWrite(led[led_inx], HIGH);
  int next = (led_inx + 1) % 3;
  digitalWrite(led[next], LOW);
  next = (next + 1) % 3;
  digitalWrite(led[next], LOW);
}

void blinkRed()
{   
    int led_inx = 0;
    const unsigned long BlinkChangePeriod = debounce[led_inx];
    static int ledState = LOW;
    static unsigned long lastBlinkChange = 0UL;

    if (millis() - lastBlinkChange >= BlinkChangePeriod)
    {
        if (ledState == HIGH)
        {
            ledState = LOW;
            digitalWrite(led[led_inx], LOW);
        }
        else
        {
            ledState = HIGH;
            turnOnOneAndOffOthers(led_inx);
        }
        lastBlinkChange += BlinkChangePeriod;
    }
}

void blinkGreen()
{   
    int led_inx = 1;
    const unsigned long BlinkChangePeriod = debounce[led_inx];
    static int ledState = LOW;
    static unsigned long lastBlinkChange = 0UL;

    if (millis() - lastBlinkChange >= BlinkChangePeriod)
    {
        if (ledState == HIGH)
        {
            ledState = LOW;
            digitalWrite(led[led_inx], LOW);
        }
        else
        {
            ledState = HIGH;
            turnOnOneAndOffOthers(led_inx);
        }
        lastBlinkChange += BlinkChangePeriod;
    }
}

void blinkBlue()
{   
    int led_inx = 2;
    const unsigned long BlinkChangePeriod = debounce[led_inx];
    static int ledState = LOW;
    static unsigned long lastBlinkChange = 0UL;

    if (millis() - lastBlinkChange >= BlinkChangePeriod)
    {
        if (ledState == HIGH)
        {
            ledState = LOW;
            digitalWrite(led[led_inx], LOW);
        }
        else
        {
            ledState = HIGH;
            turnOnOneAndOffOthers(led_inx);
        }
        lastBlinkChange += BlinkChangePeriod;
    }
}


void loop() {
  blinkRed();
  blinkGreen();
  blinkBlue();
}
