void setup() {
  for(int pin = 2 ; pin <= 9 ; pin++){
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
  }
  for(int pin = 10 ; pin <= 13 ; pin++){
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }
  pinMode(A5, OUTPUT);
  pinMode(A4, OUTPUT);
  digitalWrite(A5, LOW);
  digitalWrite(A4, LOW);
}
void loop() {
  digitalWrite(13, LOW);//đèn đỏ B
  digitalWrite(10, HIGH);//đèn đỏ A
  digitalWrite(A4, HIGH);//đèn xanh B
  digitalWrite(11, LOW);//đèn  vàng A
  hienthiso_1();
  digitalWrite(A4, LOW);//đèn xanh B
  digitalWrite(A5, HIGH);//đèn  vàng B
  hienthiso_2();
  digitalWrite(10, LOW);//đèn đỏ A
  digitalWrite(A5, LOW);//đèn  vàng B
  digitalWrite(12, HIGH);//đèn  xanh A
  digitalWrite(13, HIGH);//đèn đỏ B
  hienthiso_1();
  digitalWrite(12, LOW);//đèn  xanh A
  digitalWrite(11, HIGH);//đèn  vàng A
  hienthiso_2();
}
void hienthiso_1(){
  
  // hiển thị số 9
  int n9[8]={0,0,0,0,1,0,0,1};
  for(int pin = 2; pin <= 9 ; pin++){
    digitalWrite(pin,n9[pin-2]);
  }
  delay(1000);
  // hiển thị số 8
  int n8[8]={0,0,0,0,0,0,0,1};
  for(int pin = 2; pin <= 9 ; pin++){
    digitalWrite(pin,n8[pin-2]);
  }
  delay(1000);
  // hiển thị số 7
  int n7[8]={0,0,1,1,1,1,0,1};
  for(int pin = 2; pin <= 9 ; pin++){
    digitalWrite(pin,n7[pin-2]);
  }
  delay(1000);  
   // hiển thị số 6
  int n6[8]={1,0,0,0,0,0,0,1};
  for(int pin = 2; pin <= 9 ; pin++){
    digitalWrite(pin,n6[pin-2]);
  }
  delay(1000);
  // hiển thị số 5
  int n5[8]={1,0,0,0,1,0,0,1};
  for(int pin = 2; pin <= 9 ; pin++){
    digitalWrite(pin,n5[pin-2]);
  }
  delay(1000);
  // hiển thị số 4
  int n4[8]={0,1,0,0,1,1,0,1};
  for(int pin = 2; pin <= 9 ; pin++){
    digitalWrite(pin,n4[pin-2]);
  }
  delay(1000);
}
void hienthiso_2(){
   // hiển thị số 3
  int n3[8]={0,0,1,0,1,0,0,1};
  for(int pin = 2; pin <= 9 ; pin++){
    digitalWrite(pin,n3[pin-2]);
  }
  delay(1000);
    // hiển thị số 2
  int n2[8]={0,0,1,0,0,0,1,1};
  for(int pin = 2; pin <= 9 ; pin++){
    digitalWrite(pin,n2[pin-2]);
  }
  delay(1000);
   // hiển thị số 1
  int n1[8]={0,1,1,1,1,1,0,1};
  for(int pin = 2; pin <= 9 ; pin++){
    digitalWrite(pin,n1[pin-2]);
  }
  delay(1000);
}