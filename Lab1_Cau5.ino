#include <Wire.h>
#include <string.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2); //SCL A5 SDA A4
int button[3] = {A0, A1, A2};
int LED[10] = {13, 12, 11, 10, 9, 8, 7, 6, 5, 4};
int level = 1, score = 0, randNumber;
unsigned long time;
void setup()
{
  for(int i = 0; i < 3; i++)
    pinMode(button[i], INPUT_PULLUP);
  for(int i = 0; i < 10; i++)
    pinMode(LED[i], OUTPUT);
  Serial.begin(9600);
  lcd.begin(0, 0);
  lcd.init();
  lcd.backlight();
  ShowLevelAndScore();
}

void loop()
{
  int timedOut = 1;
  SelectRandomLED();
  time = millis();
  while((millis() - time) < 4000 - level * 1000) {
    if(digitalRead(button[randNumber % 3]) == LOW) {
      score++;
      level = (level == 3) ? 3 : level + 1;
      timedOut = 0;
      break;
    }
    else if(digitalRead(button[(randNumber + 1) % 3]) == LOW ||
           digitalRead(button[(randNumber + 2) % 3]) == LOW){
      PrintAt(0, 1, "Wrong!!!");
      delay(1000);
      PrintAt(0, 1, "        ");
      level = 1;
      score = 0;
      timedOut = 0;
      break;
    }
  }
  if(timedOut == 1) {
    PrintAt(0, 1, "Time's up!");
    delay(1000);
    PrintAt(0, 1, "          ");
    score = (score == 0) ? 0 : score - 1;
    level = (level == 1) ? 1 : level - 1;
  }
  ShowLevelAndScore();
}
void SelectRandomLED()
{
  int LEDOff[10] = {13, 12, 11, 10, 9, 8, 7, 6, 5, 4},
  LEDOn[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int brightIndex , restLEDOff = 10;
  randNumber = random(1, 11);
  for(int i = 0; i < randNumber; i++) {
    brightIndex = random(0, restLEDOff);
    LEDOn[i] = LEDOff[brightIndex];
    for(int j = brightIndex; j < restLEDOff; j++)
      LEDOff[j] = LEDOff[j + 1];
    restLEDOff--;
  }
  for(int i = 0; i < randNumber; i++)
    digitalWrite(LEDOn[i], HIGH);
  delay(4000 - level * 1000);
  for(int i = 0; i < randNumber; i++)
    digitalWrite(LEDOn[i], LOW);
}
void ShowLevelAndScore() {
  lcd.setCursor(0, 0);
  lcd.print("Level " + String(level));
  lcd.setCursor(7, 0);
  lcd.print(" Score:" + String(score) + " ");
}
void PrintAt(int col, int row, String message) {
  lcd.setCursor(col, row);
  lcd.print(message);
}
