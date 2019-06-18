#include "Timer.h"
Timer timer;

void setup() {
  DDRB = 0x3F, DDRC = 0x3F, DDRD = 0xFF;
  timer.every(1000, firstCounter);
  timer.every(2000, secondCounter);
  timer.every(3000, thirdCounter);
}

void loop() {
  timer.update();
}

void firstCounter() {
  PORTB = PORTB != 0x3F ? (PORTB << 1) | 1 : 0x1;
}

void secondCounter() {
  PORTC = PORTC != 0x3F ? (PORTC << 1) | 1 : 0x1; 
}

void thirdCounter() {
  PORTD = PORTD != 0xFF ? (PORTD << 1) | 1 : 0x1;
}
