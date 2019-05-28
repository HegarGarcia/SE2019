void setup() {
  DDRD = 0xFF, DDRB = 0xFF, DDRC = 0b11110;
}

void loop() {
  PORTD = 0xFF >> (8 - ((analogRead(A0) / 102) > 8 ? 8 : (analogRead(A0) / 102)));
  PORTB = (PORTB & 0xFC) | 0x3 >> ((analogRead(A0) / 102) < 9 ? 2 : 10 - (analogRead(A0) / 102));
  analogWrite(11, (analogRead(A0) / 102) > 3 ? 255 : 0);
  analogWrite(10, (analogRead(A0) / 102) <= 3 ? 255 : (analogRead(A0) / 102) <= 7 ? 35 : 0);
}
