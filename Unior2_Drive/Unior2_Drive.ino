#include <Wire.h>

void setup() {
  Wire.begin(8);
  Wire.onReceive(receiv);
}

void loop() {
  delay(100);
}

void receiv(int sp) {
  while (Wire.available()) {
    char c = Wire.read();
    Serial.print(c);
  }
}
