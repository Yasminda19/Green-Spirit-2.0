#include <DynamixelSerial.h>

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  Dynamixel.begin(1000000, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
//Dynamixel.setID (1,23);
Dynamixel.moveSpeed (23, 547, 300);
delay(1000);
Dynamixel.moveSpeed (23, 472, 300);
delay(1000);
}
