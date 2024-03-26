// C++ code
//
int LED[6] = {13,12,11,10,9,8};
int button = A0;
int ranNumber = 0;
int first = 1;
void setup()
{
  pinMode(button, INPUT_PULLUP);
  for(int i = 0; i < 6; i++) {
    pinMode(LED[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop()
{
  int buttonStatus = digitalRead(button);
  if (buttonStatus == LOW) {
    for(int i = 0; i < 6; i++) {
        digitalWrite(LED[i], HIGH);
        delay(200);
        digitalWrite(LED[i], LOW);
    	}
    for(int i = 0; i < 5; i++) {
        digitalWrite(LED[4 - i], HIGH);
        delay(200);
        digitalWrite(LED[4 - i], LOW);
    	}
    delay(500);
    ranNumber = random(1, 7);
    ControlLed(ranNumber, 1, 0);
    delay(1000);
    for(int i = 0; i < 6; i++) {
      ControlLed(ranNumber, 1, 0);
      delay(150);
      ControlLed(ranNumber, 0, 0);
      delay(150);
    }
  }
}
void ControlLed(int num, int state, int de) {
  for(int i = 0; i < num; i++) {
    digitalWrite(LED[i], state);
    delay(de);
  }
}