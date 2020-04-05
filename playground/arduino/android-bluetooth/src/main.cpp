#include <Arduino.h>
#include <SoftwareSerial.h>
#include <Servo.h>

const int LED = 13;
const int BT_TX = 3;
const int BT_RX = 2;
const int AZIMUTH_SIGNAL = 9;
const int ELEVATION_SIGNAL = 8;

const int AZIMUTH_UPPER_LIMIT = 175;
const int AZIMUTH_LOWER_LIMIT = 5;
const int ELEVATION_UPPER_LIMIT = 95;
const int ELEVATION_LOWER_LIMIT = 5;

signed char pitch_value = 0;
signed char roll_value = 0;
unsigned char az_angle = 90;
unsigned char el_angle = 90;

unsigned char new_az_angle = 0;
unsigned char new_el_angle = 0;

Servo azimuth;
Servo elevation;
SoftwareSerial btSerial(BT_RX, BT_TX);

void setup() {
  azimuth.attach(AZIMUTH_SIGNAL);
  elevation.attach(ELEVATION_SIGNAL);
  btSerial.begin(9600);
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  azimuth.write(az_angle);
  elevation.write(el_angle);
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
  if((az_angle+pitch_value) > ELEVATION_LOWER_LIMIT && (az_angle+pitch_value) < ELEVATION_UPPER_LIMIT) {
    azimuth.write((az_angle+pitch_value));
  } 
  if((el_angle+roll_value) > AZIMUTH_LOWER_LIMIT && (el_angle+roll_value) < AZIMUTH_UPPER_LIMIT) {
    azimuth.write((el_angle+roll_value));
  }
  delay(100);
}