#include <Arduino.h>
#include <SoftwareSerial.h>

const int LED = 13;
const int BT_TX = 3;
const int BT_RX = 2;
unsigned char data = 0;

SoftwareSerial btSerial(BT_RX, BT_TX);

void setup() {
  btSerial.begin(9600);
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
}

void loop() {
  if(btSerial.available() > 0) {
    data = btSerial.read();
    Serial.println(data);
  }
  if(data%2 == 0) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}