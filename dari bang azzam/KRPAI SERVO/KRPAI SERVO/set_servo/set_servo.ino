
#include <DynamixelSerial.h>

int pundak[6] = {13, 23, 33, 43, 53, 63};
int lengan[6] = {12, 22, 32, 42, 52, 62};
int jari [6]  = {11, 21, 31, 41, 51, 61};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Dynamixel.begin(1000000, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
   for (int i = 0; i < 7; i++)
  {
    Dynamixel.setEndless (pundak[i], OFF);
    Dynamixel.setEndless (lengan[i], OFF);
  }

//coba
///*
Dynamixel.moveSpeed (pundak[0], 591, 100);    
Dynamixel.moveSpeed (lengan[0], 556, 5);
Dynamixel.moveSpeed (jari[0], 523, 29);
Dynamixel.moveSpeed (pundak[1], 432, 100);    
Dynamixel.moveSpeed (lengan[1], 467, 56);
Dynamixel.moveSpeed (jari[1], 500, 17);
Dynamixel.moveSpeed (pundak[2], 512, 100);    
Dynamixel.moveSpeed (lengan[2], 560, 122);
Dynamixel.moveSpeed (jari[2], 546, 192);
Dynamixel.moveSpeed (pundak[3], 512, 100);    
Dynamixel.moveSpeed (lengan[3], 463, 39);
Dynamixel.moveSpeed (jari[3], 477, 129);
Dynamixel.moveSpeed (pundak[4], 432, 100);    
Dynamixel.moveSpeed (lengan[4], 467, 5);
Dynamixel.moveSpeed (jari[4], 500, 29);
Dynamixel.moveSpeed (pundak[5], 591, 100);    
Dynamixel.moveSpeed (lengan[5], 556, 56);
Dynamixel.moveSpeed (jari[5], 523, 17);
delay(2000);


//*/
// Normal

//  if (state=='N')
/*
//Dynamixel.moveSpeed (pundak[0], 591, 100);    //angkat netral
//Dynamixel.moveSpeed (pundak[3], 512, 100);
//Dynamixel.moveSpeed (pundak[4], 432, 100);
Dynamixel.moveSpeed (lengan[0], 556, 100);
Dynamixel.moveSpeed (lengan[3], 463, 100);
Dynamixel.moveSpeed (lengan[4], 467, 100);
Dynamixel.moveSpeed (jari[0], 523, 76);
Dynamixel.moveSpeed (jari[3], 463, 75);
Dynamixel.moveSpeed (jari[4], 467, 76);
delay(2000);
/*
Dynamixel.moveSpeed (pundak[1], 512, 100);    // dorong
Dynamixel.moveSpeed (pundak[2], 432, 100);
Dynamixel.moveSpeed (pundak[5], 650, 100);
Dynamixel.moveSpeed (lengan[1], 463, 5);
Dynamixel.moveSpeed (lengan[2], 556, 5);
Dynamixel.moveSpeed (lengan[5], 533, 39);
Dynamixel.moveSpeed (jari[1], 477, 29);
Dynamixel.moveSpeed (jari[2], 523, 29);
Dynamixel.moveSpeed (jari[5], 447, 129);
delay(200);

Dynamixel.moveSpeed (pundak[0], 650, 100);    //maju
Dynamixel.moveSpeed (pundak[3], 432, 100);
Dynamixel.moveSpeed (pundak[4], 512, 100);
Dynamixel.moveSpeed (lengan[0], 533, 122);
Dynamixel.moveSpeed (lengan[3], 467, 69);
Dynamixel.moveSpeed (lengan[4], 463, 56);
Dynamixel.moveSpeed (jari[0], 447, 192);
Dynamixel.moveSpeed (jari[3], 500, 76);
Dynamixel.moveSpeed (jari[4], 477, 17);
delay(5000);
Dynamixel.moveSpeed (pundak[1], 432, 100);    // angkat 
Dynamixel.moveSpeed (pundak[2], 512, 100);    
Dynamixel.moveSpeed (pundak[5], 591, 100);
Dynamixel.moveSpeed (lengan[1], 418, 56);
Dynamixel.moveSpeed (lengan[2], 611, 69);
Dynamixel.moveSpeed (lengan[5], 605, 122);
Dynamixel.moveSpeed (jari[1], 463, 17);
Dynamixel.moveSpeed (jari[2], 584, 76);
Dynamixel.moveSpeed (jari[5], 560, 192);
Dynamixel.moveSpeed (pundak[0], 591, 100);    //dorong
Dynamixel.moveSpeed (pundak[3], 512, 100);
Dynamixel.moveSpeed (pundak[4], 432, 100);
Dynamixel.moveSpeed (lengan[0], 556, 39);
Dynamixel.moveSpeed (lengan[3], 463, 5);
Dynamixel.moveSpeed (lengan[4], 467, 5);
Dynamixel.moveSpeed (jari[0], 523, 129);
Dynamixel.moveSpeed (jari[3], 477, 29);
Dynamixel.moveSpeed (jari[4], 500, 29);
Dynamixel.moveSpeed (pundak[0], 512, 100);   
Dynamixel.moveSpeed (pundak[3], 591, 100);
Dynamixel.moveSpeed (pundak[4], 373, 100);
Dynamixel.moveSpeed (lengan[0], 560, 5);
Dynamixel.moveSpeed (lengan[3], 467, 5);
Dynamixel.moveSpeed (lengan[4], 490, 39);
Dynamixel.moveSpeed (jari[0], 546, 29);
Dynamixel.moveSpeed (jari[3], 500, 29);
Dynamixel.moveSpeed (jari[4], 576, 129);
delay(200);
Dynamixel.moveSpeed (pundak[1], 373, 100);    //maju 
Dynamixel.moveSpeed (pundak[2], 591, 100);    
Dynamixel.moveSpeed (pundak[5], 512, 100);
Dynamixel.moveSpeed (lengan[1], 490, 122);
Dynamixel.moveSpeed (lengan[2], 556, 70);
Dynamixel.moveSpeed (lengan[5], 560, 57);
Dynamixel.moveSpeed (jari[1], 576, 192);
Dynamixel.moveSpeed (jari[2], 523, 77);
Dynamixel.moveSpeed (jari[5], 546, 18);
delay(200);
Dynamixel.moveSpeed (pundak[0], 591, 100);    //angkat  
Dynamixel.moveSpeed (pundak[3], 512, 100);
Dynamixel.moveSpeed (pundak[4], 432, 100);
Dynamixel.moveSpeed (lengan[0], 605, 57);
Dynamixel.moveSpeed (lengan[3], 412, 70);
Dynamixel.moveSpeed (lengan[4], 418, 122);
Dynamixel.moveSpeed (jari[0], 560, 18);
Dynamixel.moveSpeed (jari[3], 439, 77);
Dynamixel.moveSpeed (jari[4], 463, 192);
Dynamixel.moveSpeed (pundak[1], 432, 100);    //dorong 
Dynamixel.moveSpeed (pundak[2], 512, 100);    
Dynamixel.moveSpeed (pundak[5], 591, 100);
Dynamixel.moveSpeed (lengan[1], 467, 39);
Dynamixel.moveSpeed (lengan[2], 560, 5);
Dynamixel.moveSpeed (lengan[5], 556, 5);
Dynamixel.moveSpeed (jari[1], 500, 129);
Dynamixel.moveSpeed (jari[2], 546, 29);
Dynamixel.moveSpeed (jari[5], 523, 29);
delay(200);
*/
// maju
/*
//if (state=='1')
Dynamixel.moveSpeed (pundak[0], 591, 100);    //angkat
Dynamixel.moveSpeed (pundak[3], 512, 100);
Dynamixel.moveSpeed (pundak[4], 432, 100);    
Dynamixel.moveSpeed (lengan[0], 605, 100);
Dynamixel.moveSpeed (lengan[3], 412, 100);
Dynamixel.moveSpeed (lengan[4], 418, 100);
Dynamixel.moveSpeed (jari[0], 605, 76);
Dynamixel.moveSpeed (jari[3], 412, 75);
Dynamixel.moveSpeed (jari[4], 418, 76);
delay(50);
Dynamixel.moveSpeed (pundak[1], 512, 100);    //dorong
Dynamixel.moveSpeed (pundak[2], 432, 100);
Dynamixel.moveSpeed (pundak[5], 650, 100);    
Dynamixel.moveSpeed (lengan[1], 463, 5);
Dynamixel.moveSpeed (lengan[2], 556, 5);
Dynamixel.moveSpeed (lengan[5], 533, 39);
Dynamixel.moveSpeed (jari[1], 477, 29);
Dynamixel.moveSpeed (jari[2], 523, 29);
Dynamixel.moveSpeed (jari[5], 447, 129);

Dynamixel.moveSpeed (pundak[0], 650, 100);    //maju
Dynamixel.moveSpeed (pundak[3], 432, 100);
Dynamixel.moveSpeed (pundak[4], 512, 100);    
Dynamixel.moveSpeed (lengan[0], 533, 122);
Dynamixel.moveSpeed (lengan[3], 467, 69);
Dynamixel.moveSpeed (lengan[4], 463, 56);
Dynamixel.moveSpeed (jari[0], 447, 192);
Dynamixel.moveSpeed (jari[3], 500, 76);
Dynamixel.moveSpeed (jari[4], 477, 17);


Dynamixel.moveSpeed (pundak[1], 432, 100);    
Dynamixel.moveSpeed (lengan[1], 418, 56);
Dynamixel.moveSpeed (jari[1], 463, 17);
delay(1000);
Dynamixel.moveSpeed (pundak[1], 373, 100);    
Dynamixel.moveSpeed (lengan[1], 490, 122);
Dynamixel.moveSpeed (jari[1], 576, 192);
delay(1000);
Dynamixel.moveSpeed (pundak[1], 432, 100);    
Dynamixel.moveSpeed (lengan[1], 467, 39);
Dynamixel.moveSpeed (jari[1], 500, 129);
delay(1000);
*/

// Mundur
/*
//if (state=='2')

Dynamixel.moveSpeed (lengan[0], 572, velocity);
Dynamixel.moveSpeed (lengan[3], 572, velocity);
Dynamixel.moveSpeed (lengan[4], 452, velocity);

Dynamixel.moveSpeed (pundak[0], 477, velocity);
Dynamixel.moveSpeed (pundak[3], 547, velocity);
Dynamixel.moveSpeed (pundak[4], 477, velocity);
delay (100);

Dynamixel.moveSpeed (pundak[1], 477, velocity);
Dynamixel.moveSpeed (pundak[2], 547, velocity);
Dynamixel.moveSpeed (pundak[5], 477, velocity);
delay (100);

Dynamixel.moveSpeed (lengan[0], 512, velocity);
Dynamixel.moveSpeed (lengan[3], 512, velocity);
Dynamixel.moveSpeed (lengan[4], 512, velocity);
delay(100);

Dynamixel.moveSpeed (lengan[1], 452, velocity);
Dynamixel.moveSpeed (lengan[2], 452, velocity);
Dynamixel.moveSpeed (lengan[5], 572, velocity);

Dynamixel.moveSpeed (pundak[1], 547, velocity);
Dynamixel.moveSpeed (pundak[2], 477, velocity);
Dynamixel.moveSpeed (pundak[5], 547, velocity);
delay(100);

Dynamixel.moveSpeed (pundak[0], 547, velocity);
Dynamixel.moveSpeed (pundak[3], 477, velocity);
Dynamixel.moveSpeed (pundak[4], 547, velocity);
delay (100);

Dynamixel.moveSpeed (lengan[1], 512, velocity);
Dynamixel.moveSpeed (lengan[2], 512, velocity);
Dynamixel.moveSpeed (lengan[5], 512, velocity);
delay(100);
*/

// Putar Kanan
/*
//if (state=='3')
Dynamixel.moveSpeed (lengan[0], 572, velocity);
Dynamixel.moveSpeed (lengan[3], 572, velocity);
Dynamixel.moveSpeed (lengan[4], 452, velocity);

Dynamixel.moveSpeed (pundak[0], 547, velocity);
Dynamixel.moveSpeed (pundak[3], 547, velocity);
Dynamixel.moveSpeed (pundak[4], 547, velocity);
delay(100);

Dynamixel.moveSpeed (pundak[1], 477, velocity);
Dynamixel.moveSpeed (pundak[2], 477, velocity);
Dynamixel.moveSpeed (pundak[5], 477, velocity);
delay(100);

Dynamixel.moveSpeed (lengan[0], 512, velocity);
Dynamixel.moveSpeed (lengan[3], 512, velocity);
Dynamixel.moveSpeed (lengan[4], 512, velocity);
delay(100);

Dynamixel.moveSpeed (lengan[1], 452, velocity);
Dynamixel.moveSpeed (lengan[2], 452, velocity);
Dynamixel.moveSpeed (lengan[5], 572, velocity);

Dynamixel.moveSpeed (pundak[1], 547, velocity);
Dynamixel.moveSpeed (pundak[2], 547, velocity);
Dynamixel.moveSpeed (pundak[5], 547, velocity);
delay(100);

Dynamixel.moveSpeed (pundak[0], 477, velocity);
Dynamixel.moveSpeed (pundak[3], 477, velocity);
Dynamixel.moveSpeed (pundak[4], 477, velocity);
delay(100);

Dynamixel.moveSpeed (lengan[1], 512, velocity);
Dynamixel.moveSpeed (lengan[2], 512, velocity);
Dynamixel.moveSpeed (lengan[5], 512, velocity);
delay(100);
*/


// Putar Kiri
/*
//if (state=='4')

Dynamixel.moveSpeed (lengan[0], 572, velocity);
Dynamixel.moveSpeed (lengan[3], 572, velocity);
Dynamixel.moveSpeed (lengan[4], 452, velocity);

Dynamixel.moveSpeed (pundak[0], 477, velocity);
Dynamixel.moveSpeed (pundak[3], 477, velocity);
Dynamixel.moveSpeed (pundak[4], 477, velocity);
delay(100);

Dynamixel.moveSpeed (pundak[1], 547, velocity);
Dynamixel.moveSpeed (pundak[2], 547, velocity);
Dynamixel.moveSpeed (pundak[5], 547, velocity);
delay(100);

Dynamixel.moveSpeed (lengan[0], 512, velocity);
Dynamixel.moveSpeed (lengan[3], 512, velocity);
Dynamixel.moveSpeed (lengan[4], 512, velocity);
delay(100);

Dynamixel.moveSpeed (lengan[1], 452, velocity);
Dynamixel.moveSpeed (lengan[2], 452, velocity);
Dynamixel.moveSpeed (lengan[5], 572, velocity);

Dynamixel.moveSpeed (pundak[1], 477, velocity);
Dynamixel.moveSpeed (pundak[2], 477, velocity);
Dynamixel.moveSpeed (pundak[5], 477, velocity);
delay(100);

Dynamixel.moveSpeed (pundak[0], 547, velocity);
Dynamixel.moveSpeed (pundak[3], 547, velocity);
Dynamixel.moveSpeed (pundak[4], 547, velocity);
delay(100);

Dynamixel.moveSpeed (lengan[1], 512, velocity);
Dynamixel.moveSpeed (lengan[2], 512, velocity);
Dynamixel.moveSpeed (lengan[5], 512, velocity);
delay(100);
*/

// Goyang Horizontal
/*
Dynamixel.moveSpeed (lengan[0], 512, velocity1);
Dynamixel.moveSpeed (lengan[1], 512, velocity1);
Dynamixel.moveSpeed (lengan[2], 512, velocity1);
Dynamixel.moveSpeed (lengan[3], 512, velocity1);
Dynamixel.moveSpeed (lengan[4], 512, velocity1);
Dynamixel.moveSpeed (lengan[5], 512, velocity1);
delay(2000);
Dynamixel.moveSpeed (pundak[0], 532, velocity1);
Dynamixel.moveSpeed (pundak[1], 532, velocity1);
Dynamixel.moveSpeed (pundak[2], 532, velocity1);
Dynamixel.moveSpeed (pundak[3], 532, velocity1);
Dynamixel.moveSpeed (pundak[4], 532, velocity1);
Dynamixel.moveSpeed (pundak[5], 532, velocity1);
delay(2000);
Dynamixel.moveSpeed (pundak[0], 532, velocity1);
Dynamixel.moveSpeed (pundak[1], 532, velocity1);
Dynamixel.moveSpeed (pundak[2], 532, velocity1);
Dynamixel.moveSpeed (pundak[3], 532, velocity1);
Dynamixel.moveSpeed (pundak[4], 532, velocity1);
Dynamixel.moveSpeed (pundak[5], 532, velocity1);
delay(2000);
*/
}
