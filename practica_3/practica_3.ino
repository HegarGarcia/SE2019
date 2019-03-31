void setup() {
  DDRB = DDRC | 0X31, DDRD = DDRD | 0xF3;
  attachInterrupt(digitalPinToInterrupt(2), setGreen, RISING);
  attachInterrupt(digitalPinToInterrupt(3), setRed, RISING);
  setColor(255, 255, 0);
}

void loop() {}

void setGreen() {
  setColor(0, 255, 0);
}

void setRed() {
  setColor(255, 0, 0);
}

void setColor(int red, int green, int blue) {
  analogWrite(11, red);
  analogWrite(10, green);
  analogWrite(9, blue);
}
