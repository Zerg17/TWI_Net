#include <Wire.h>

void setup() {
  Wire.begin();
}

void loop() {
  Wire.beginTransmission(8);
  Wire.write("x");
  Wire.endTransmission(); 
  delay(500);
}
