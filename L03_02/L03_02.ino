// Napisz program, który będzie reagował na komendy wysyłane z narzędzia Serial Monitor do 
// zestawu Arduino. Program powinien zapalać wszystkie diody LED z zadaną każdej osobno 
// jasnością w reakcji na komendę. Postać komendy ustal samodzielnie.
#define LED_RED 6
#define LED_GREEN 5
#define LED_BLUE 3
int led[] = {LED_RED, LED_GREEN, LED_BLUE};

void initRGB() {
    pinMode(LED_RED, OUTPUT);
    digitalWrite(LED_RED, LOW);

    pinMode(LED_GREEN, OUTPUT);
    digitalWrite(LED_GREEN, LOW);

    pinMode(LED_BLUE, OUTPUT);
    digitalWrite(LED_BLUE, LOW);
}

void initSerial() {
    Serial.begin(9600);
    while (!Serial) {}
}

void setup() {
    initRGB();
    initSerial();
}


int split_length(String input, const char* spliter) {
    input = input + spliter;
    char buf[input.length()];
    input.toCharArray(buf, sizeof(buf));
    
    char *p = buf;
    char *str;
    int tab_size = 0;
    while ((str = strtok_r(p, spliter, &p)) != NULL)
      tab_size ++;
    
    return tab_size;
}

void split(String input, const char* spliter, int tab_size) {
    input = input + spliter;    
    char* tab_splited[tab_size];
    int i = 0;

    char buf[input.length()];
    input.toCharArray(buf, sizeof(buf));
    char *p = buf;
    char *str;
    while ((str = strtok_r(p, spliter, &p)) != NULL)
      Serial.println(str);
      i++;
}

boolean isValidNumber(String str){
  for(byte i=0;i<str.length();i++) {
    if(isDigit(str.charAt(i))) return true;
  }
  return false;
}


void loop()
{
  if ( Serial.available()) {
    String command = Serial.readStringUntil('\n');
    const char* spliter = " ";
    int tab_size = split_length(command, spliter);

    String input = command + spliter;    
    char* tab_splited[tab_size];
    int i = 0;

    char buf[input.length()];
    input.toCharArray(buf, sizeof(buf));
    char *p = buf;
    char *str;
    String rgb_names[] = {"r", "g", "b"};
    bool rgb[] = {false, false, false};
    
    while ((str = strtok_r(p, spliter, &p)) != NULL)
    {
      for(int i=0; i<3; i++)
      {
        if(rgb_names[i] == str)
        {
           rgb[i] = true;
        }
      }

      if(isValidNumber(str))
        {
          for(int i=0; i<3; i++)
          {
            if(rgb[i])
            {
              rgb[i] = false;
              int val = String(str).toInt();
              analogWrite(led[i], val);
            }
          }
        }
        i++;
    }
  }
}