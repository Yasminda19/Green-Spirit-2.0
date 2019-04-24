#include <DynamixelSerial.h>

int velocity = 100; //kecepatan servo
int sudut1 = 300;  //sudut ambil benih
int sudut2 = 700;  //sudut jatuh benih
int ID = 62;  //ID servo

void setup() {

Serial.begin(1000000);
// set dynamixel
Dynamixel.begin(1000000, 2);
}
 
void loop() {
  
Dynamixel.moveSpeed (ID, sudut1, velocity);
Serial.println ("jalan1");
delay (1000);
Dynamixel.moveSpeed (ID, sudut2, velocity);
Serial.println ("jalan2");
delay (1000);
}
