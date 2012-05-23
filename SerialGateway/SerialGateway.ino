/* 
	Serial Gateway Sketch
	for Arduino Megas

	Author: Simon Waldherr
	License: MIT
*/

#include <Wire.h>

const int sspeed = 115200;
const int i2cdevice = 44;

void setup() 
  {
    // initialize all serial ports:
    Serial.begin(sspeed);
    Serial1.begin(sspeed);
    Serial2.begin(sspeed);
    Serial3.begin(sspeed);
    Wire.begin();
  }

void loop()
  {
    if (Serial.available())
      {
        int inByte = Serial.read();
        Serial1.print(inByte, BYTE); 
        Serial2.print(inByte, BYTE); 
        Serial3.print(inByte, BYTE); 
        Wire.beginTransmission(i2cdevice);
        Wire.write(inByte);
        Wire.endTransmission();
      }
    if (Serial1.available())
      {
        int inByte = Serial.read();
        Serial.print(inByte, BYTE); 
        Serial2.print(inByte, BYTE); 
        Serial3.print(inByte, BYTE); 
      }
    if (Serial2.available())
      {
        int inByte = Serial1.read();
        Serial1.print(inByte, BYTE); 
        Serial.print(inByte, BYTE); 
        Serial3.print(inByte, BYTE); 
      }
    if (Serial3.available())
      {
        int inByte = Serial.read();
        Serial1.print(inByte, BYTE); 
        Serial2.print(inByte, BYTE); 
        Serial.print(inByte, BYTE); 
      }
    while(Wire.available())
      {
        char c = Wire.read();
        Serial.print(c);
      }
  }
