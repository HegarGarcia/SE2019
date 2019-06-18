#include "Timer.h"

const byte digit_pattern[10] =
{
  B00111111,
  B00000110,
  B01011011,
  B01001111,
  B01100110,
  B01101101,
  B01111101,
  B00000111,
  B01111111,
  B01101111
};


Timer timer;
float temp = 0;
int refreshTime = 0;

void setup() {
  DDRB = 0xFF, DDRC = 0x0, DDRD = DDRD | 0xE0;
  Serial.begin(9600);
  timer.every(30, showTemp);
  Serial.println("Ingresa el tiempo de chequeo:");
}

void loop() {
  if (refreshTime > 0) {
    timer.update();
    return;
  }

  if (temp == 0 && Serial.available() > 0) {
    refreshTime = Serial.readString().toInt() * 1000;
    Serial.println("");
    timer.every(refreshTime, readTemp);
  }
}

void showTemp() {
  PORTB = 0x38;
  shiftOut(7, 13, MSBFIRST, digit_pattern[(int)temp / 10]);
  shiftOut(6, 12, MSBFIRST, digit_pattern[(int)temp % 10]);
  shiftOut(5, 11, MSBFIRST, digit_pattern[(int)(temp * 10) % 10]);
  PORTB = 0xFF;
}

void readTemp() {
  temp = (analogRead(A0) / 1024.0) * 500 >= 100 ? 99.9 : ((analogRead(A0) / 1024.0) * 500) - 0.4;
  Serial.println(temp, DEC);
}
