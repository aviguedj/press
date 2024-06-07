#define NUMBER_OF_LEDS 2

#define BTN_pin 6
#define blueLed 12
#define redLed 2

int ledsPin[NUMBER_OF_LEDS] = { redLed, blueLed };
bool LedIsOn[NUMBER_OF_LEDS];

void ToggleLed(int chnl) {
  if (LedIsOn[chnl]) {
    TurnLedOff(chnl);
  } else {
    TurnLedOn(chnl);
  }
}


void TurnLedOn(int chnl) {
  LedIsOn[chnl] = true;
  digitalWrite(ledsPin[chnl], HIGH);
}

void TurnLedOff(int chnl) {
  LedIsOn[chnl] = false;
  digitalWrite(ledsPin[chnl], LOW);
}


void setup() {
  Serial.begin(9600);
  pinMode(blueLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(BTN_pin, INPUT_PULLUP);
  for (int k = 0; k < NUMBER_OF_LEDS; k++) {
    pinMode(ledsPin[k], OUTPUT);
    TurnLedOff(k);
  }
  unsigned long current_time;
  current_time = millis();
}

int CurrBtn;
int LastBtn;

void loop() {
  CurrBtn = digitalRead(BTN_pin);
  if ((CurrBtn == LOW) && (LastBtn == HIGH)) {
    ToggleLed(0);
  }
  LastBtn = CurrBtn;
}
