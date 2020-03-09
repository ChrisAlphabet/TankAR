#include <Arduino.h>

const int LED = 13;
unsigned char data = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
}

void loop() {
  if(Serial.available() > 0) {
    data = Serial.read();
  }
  if (data == 'l') {
    digitalWrite(LED, LOW);
  } else if (data == 'h') {
    digitalWrite(LED, HIGH);
  }
}