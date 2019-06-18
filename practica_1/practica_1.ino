#define LED_RANGE 14

void setup() {
  for (int pin = 0; pin < LED_RANGE; pin++) {
    pinMode(pin, OUTPUT);
  }
}

void loop() {
  for (int pin = 0; pin < LED_RANGE; pin++) {
    int prevPin = pin == 0 ? LED_RANGE - 1 : pin - 1;
    
    digitalWrite(prevPin, LOW);
    digitalWrite(pin, HIGH);
    delay(1000);
  }
}
