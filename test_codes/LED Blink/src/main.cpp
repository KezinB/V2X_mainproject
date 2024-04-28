#include <Arduino.h>
#define LED_1 2
#define LED_2 4
#define LED_3 5

void setup() {
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);

}

void loop() {
  digitalWrite(LED_1, HIGH);
  delay(1000);
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, HIGH);
  delay(2000);
  digitalWrite(LED_3, HIGH);
}


