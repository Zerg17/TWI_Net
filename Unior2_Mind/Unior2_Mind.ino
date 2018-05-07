#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(250000);
}

void loop() {
  uint16_t u1 = pulseIn(A0, 1, 45000);
  uint16_t u2 = pulseIn(A1, 1, 45000);
  int8_t v1 = constrain(map(u1 < 1000 ? 1500 : u1 < 1480 ? u1 : u1 < 1520 ? 1500 : u1 < 2000 ? u1 : 1500, 1100, 1900, -127, 127), -127, 127);
  int8_t v2 = constrain(map(u2 < 1000 ? 1500 : u2 < 1480 ? u2 : u2 < 1520 ? 1500 : u2 < 2000 ? u2 : 1500, 1100, 1900, -127, 127), -127, 127);
  Wire.beginTransmission(8);
  Wire.write(constrain(v2-v1,-127,127));
  Wire.write(constrain(v2+v1,-127,127));
  Wire.endTransmission();
  Wire.beginTransmission(9);
  Wire.write(constrain(v2-v1,-127,127));
  Wire.write(constrain(v2+v1,-127,127));
  Wire.endTransmission();
}
