#include <Wire.h>

void setup() {
  pinMode(4,1);
  pinMode(5,1);
  pinMode(6,1);
  pinMode(7,1);
  Wire.begin(8);
  Wire.onReceive(receiv);
  move(0,0);
}

void loop() {
  move(50,50);
  delay(100);
}

void receiv(int sp) {
  while (Wire.available()) {
    char c = Wire.read();
    Serial.print(c);
  }
}

void move(int8_t m1, int8_t m2){
  digitalWrite(4,!(m1>>7));
  analogWrite(5,m1<<1);
  analogWrite(6,m2<<1);
  digitalWrite(7,!(m2>>7));
}

