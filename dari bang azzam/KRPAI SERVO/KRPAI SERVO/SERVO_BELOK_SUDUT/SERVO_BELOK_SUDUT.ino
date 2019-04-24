#include <DynamixelSerial.h>

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Dynamixel.begin(1000000,2);
}

void loop() {
  // put your main code here, to run repeatedly:
///*goyang kanan
Dynamixel.moveSpeed(11, 479,40);
Dynamixel.moveSpeed(12, 549,6);
Dynamixel.moveSpeed(13, 501,52);

Dynamixel.moveSpeed(21, 428,20);
Dynamixel.moveSpeed(22, 468,3);
Dynamixel.moveSpeed(23, 302,61);

//Dynamixel.moveSpeed(31, 563,8);
//Dynamixel.moveSpeed(32, 561,1);
//Dynamixel.moveSpeed(33, 460,27);

//Dynamixel.moveSpeed(41, 461,8);
//Dynamixel.moveSpeed(42, 463,1);
//Dynamixel.moveSpeed(43, 460,27);

Dynamixel.moveSpeed(51, 424,22);
Dynamixel.moveSpeed(52, 461,1);
Dynamixel.moveSpeed(53, 243,91);

Dynamixel.moveSpeed(61, 460,49);
Dynamixel.moveSpeed(62, 548,7);
Dynamixel.moveSpeed(63, 513,46);
delay(5000);
//*/
Dynamixel.moveSpeed(11, 557,56);
Dynamixel.moveSpeed(12, 561,14);
Dynamixel.moveSpeed(13, 603,17);

Dynamixel.moveSpeed(21, 467,18);
Dynamixel.moveSpeed(22, 463,3);
Dynamixel.moveSpeed(23, 421,43);

///Dynamixel.moveSpeed(31, 579,8);
//Dynamixel.moveSpeed(32, 560,1);
//Dynamixel.moveSpeed(33, 512,27);

//Dynamixel.moveSpeed(41, 445,8);
//Dynamixel.moveSpeed(42, 464,1);
//Dynamixel.moveSpeed(43, 512,27);

Dynamixel.moveSpeed(51, 467,18);
Dynamixel.moveSpeed(52, 463,3);
Dynamixel.moveSpeed(53, 421,43);

Dynamixel.moveSpeed(61, 557,56);
Dynamixel.moveSpeed(62, 561,14);
Dynamixel.moveSpeed(63, 603,17);
delay(5000);
/*
/////////////////////////////////////////////////////////
//goyang kiri
Dynamixel.moveSpeed(11, 600,50);
Dynamixel.moveSpeed(12, 586,50);
Dynamixel.moveSpeed(13, 664,50);

Dynamixel.moveSpeed(21, 495,50);
Dynamixel.moveSpeed(22, 451,50);
Dynamixel.moveSpeed(23, 476,50);

Dynamixel.moveSpeed(31, 573,50);
Dynamixel.moveSpeed(32, 596,50);
Dynamixel.moveSpeed(33, 569,50);

Dynamixel.moveSpeed(41, 420,50);
Dynamixel.moveSpeed(42, 454,50);
Dynamixel.moveSpeed(43, 567,50);

Dynamixel.moveSpeed(51, 496,50);
Dynamixel.moveSpeed(52, 432,50);
Dynamixel.moveSpeed(53, 486,50);

Dynamixel.moveSpeed(61, 603,50);
Dynamixel.moveSpeed(62, 582,50);
Dynamixel.moveSpeed(63, 680,50);
delay(10000);
/////////////////////////////////////
Dynamixel.moveSpeed(11, 557,50);
Dynamixel.moveSpeed(12, 561,50);
Dynamixel.moveSpeed(13, 603,50);

Dynamixel.moveSpeed(21, 467,50);
Dynamixel.moveSpeed(22, 463,50);
Dynamixel.moveSpeed(23, 421,50);

Dynamixel.moveSpeed(31, 579,50);
Dynamixel.moveSpeed(32, 560,50);
Dynamixel.moveSpeed(33, 512,50);

Dynamixel.moveSpeed(41, 445,50);
Dynamixel.moveSpeed(42, 464,50);
Dynamixel.moveSpeed(43, 512,50);

Dynamixel.moveSpeed(51, 467,50);
Dynamixel.moveSpeed(52, 463,50);
Dynamixel.moveSpeed(53, 421,50);

Dynamixel.moveSpeed(61, 557,50);
Dynamixel.moveSpeed(62, 561,50);
Dynamixel.moveSpeed(63, 603,50);
delay(10000);
*/
}
