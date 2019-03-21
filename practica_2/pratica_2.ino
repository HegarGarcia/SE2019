void setup() {
  DDRB = B00000000, DDRD = B00000011, DDRC = B11111111;
}

void loop() {
  int result = PINB + (PIND >> 2);
  PORTC = result;
  PORTD = result >> 6;
}
