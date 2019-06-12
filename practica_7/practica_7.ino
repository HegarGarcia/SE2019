#include <SoftwareSerial.h>

SoftwareSerial bt(2, 3);

void setup() {
  DDRB = 0x1;
  Serial.begin(9600);
  bt.begin(9600);
}

void loop() {
  float temp = (analogRead(A0) / 1024.0) * 500 >= 100 ? 99.9 : ((analogRead(A0) / 1024.0) * 500) - 0.4;
  bt.println(temp);
  digitalWrite(8, temp > 35 ? HIGH : LOW);
  delay(1000);
}
