// C++ code
//
int LED[12] = {A0, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
int button = 2;
int number = 0;
void setup()
{
  pinMode(button, INPUT_PULLUP);
  for(int i = 0; i < 12; i++)
    pinMode(LED[i], OUTPUT);
  for(int i = 0; i < 12; i++) {
          digitalWrite(LED[i],LOW);
      }
  Serial.begin(9600);
}
void loop()
{
  int buttonStatus = digitalRead(button);
  if (buttonStatus == LOW) {
    if(number == 12)
      number = -1;
    number++;
    
    for(int i = 0; i < 12; i++) {
      if(i < number)
          digitalWrite(LED[i],HIGH);
      else
        digitalWrite(LED[i],LOW);
    }
  }
  delay(100);
}