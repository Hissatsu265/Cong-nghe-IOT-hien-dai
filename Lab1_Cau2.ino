// C++ code
//
int LED[3] = {4,3,2};
int t=1;
int index = 0;
void setup()
{
  pinMode(A0, INPUT);
  for(int i = 0; i < 3; i++) {
  	pinMode(LED[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop()
{
  int value = analogRead(A0);
  Serial.println(value);
  
  int voltage;
  voltage = map(value,0,1023,0,2) + 1;
  Serial.println(voltage);
  for(int i = 0; i < 3; i++) {
  	digitalWrite(LED[i], HIGH);
    delay(1500 / voltage);
  }
  for(int i = 2; i >= 0; i--) {
  	digitalWrite(LED[i], LOW);
    delay(1500 / voltage);
  }
  /*if(t >0) {
    digitalWrite(LED[index], HIGH);
    index=index+t;
    if (index>3){t=-1;}
  }
  else {
    index=index+t;
    digitalWrite(LED[index], LOW);
    
    if (index==0){t=1;}
  }*/
}