#include <Wire.h>

int8_t m1c, m2c;
volatile int8_t m1p, m2p;
uint32_t ltime;

void setup() {
  Serial.begin(250000);
  pinMode(4, 1);
  pinMode(5, 1);
  pinMode(6, 1);
  pinMode(7, 1);
  Wire.begin(9);
  Wire.onReceive(receiv);
  move(0, 0);
}

void loop() {
  if(millis()-ltime>100)m1p=0,m2p=0;
  //Serial.println(m1p);
  m1c = constrain(m1c + (m1c < m1p ? 1 : m1c > m1p ? -1 : 0), -127, 127);
  m2c = constrain(m2c + (m2c < m2p ? 1 : m2c > m2p ? -1 : 0), -127, 127);
  if(m1c==0)delay(10);
  if(m2c==0)delay(10);
  move(m1c, m2c);
}

void receiv(int sp) {
  while (Wire.available()) {
    ltime=millis();
    m1p = Wire.read();
    m2p = Wire.read();
  }
}

void move(int8_t m1, int8_t m2) {
  if(m1<0)digitalWrite(4, 1);
  if(m1>0)digitalWrite(4, 0);
  if(m2<0)digitalWrite(7, 1);
  if(m2>0)digitalWrite(7, 0);
  analogWrite(5, abs(m1) << 1);
  analogWrite(6, abs(m2) << 1);

}

