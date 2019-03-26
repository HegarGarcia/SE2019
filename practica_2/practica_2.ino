void setup() {
  DDRB = B00000000, DDRC = B00000000, DDRD = B11111111;
}

void loop() {
  PORTD = PINB + PINC;
}
