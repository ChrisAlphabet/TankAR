#include <Arduino.h>
#include <SoftwareSerial.h>

const int LED = 13;
const int BT_TX = 3;
const int BT_RX = 2;
signed char pitch_value = 0;
signed char roll_value = 0;

SoftwareSerial btSerial(BT_RX, BT_TX);

void setup() {
  btSerial.begin(9600);
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
}

void loop() {
  if(btSerial.available() > 0) {
    pitch_value = btSerial.read();
    roll_value = btSerial.read();
    Serial.print("Pitch: ");
    Serial.print(pitch_value);
    Serial.print(" Roll: ");
    Serial.println(roll_value);
    Serial.println("");
  }
  delay(100);
}