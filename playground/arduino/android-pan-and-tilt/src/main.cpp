#include <Arduino.h>
#include <Servo.h>

const int LED = 13;
const int AZIMUTH_SIGNAL = 9;
const int ELEVATION_SIGNAL = 8;

unsigned char data = 0;
unsigned char az_angle = 90;
unsigned char el_angle = 90;

Servo azimuth;
Servo elevation;

void setup() {
  Serial.begin(9600);
  azimuth.attach(AZIMUTH_SIGNAL);
  elevation.attach(ELEVATION_SIGNAL);
}

void loop() {
  if(Serial.available() > 0) {
    data = Serial.read();
    if(data == 'a') {
      az_angle+=10;
    } else if (data == 'd') {
      az_angle-=10;
    } else if (data == 'w') {
      el_angle+=10;
    } else if (data == 's') {
      el_angle-=10;
    }
  }
  azimuth.write(az_angle);
  elevation.write(el_angle);
  Serial.print("Az: ");
  Serial.print(az_angle);
  Serial.print(" El: ");
  Serial.println(el_angle);
  delay(500);
}