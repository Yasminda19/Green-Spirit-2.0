/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;
Servo myservo2;// create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 110;
int pos2 = 80 ; // variable to store the servo position

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  myservo2.attach(10);
   myservo.write(pos);
   myservo2.write(pos2);
   delay(8000);// attaches the servo on pin 9 to the servo object
}

void loop() {
  
  for (pos = 90; pos <= 130; pos += 1) { // goes from 0 degrees to 180 degrees
    
    myservo.write(pos);
    if (pos2 == 80 ) {
      pos2= pos2 - 5 ;
      Serial.println("------1a-----");
      }
      else if (pos2 == 75) {
        Serial.println("------1b-----");
      pos2 = pos2 - 5;
      }
     else if (pos2 == 70) {
      Serial.println("------1c-----");
      pos2 = pos2 - 5;
      }
      else if (pos2 == 66) {
        Serial.println("------1d-----");
      pos2 = 65 ;
      }
     else if (pos2 == 65) {
      Serial.println("------1e-----");
      pos2 = pos2 - 5;
      }
      else if (pos2 == 60) {
        Serial.println("------1f-----");
      pos2 = pos2 - 5;
      }
      else if (pos2 == 55) {
        Serial.println("------1g-----");
      pos2 = pos2 - 5;
      }
    else if (pos2 == 50) {  
    myservo2.write(50);
    pos2 = 51 ;// tell servo to go to position in variable 'pos'
    delay (100);
    }
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  Serial.print("pos = ");
  Serial.println(pos);
  Serial.print("pos2 = ");
  Serial.println(pos2);
  for (pos = 130; pos >= 90; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);
    if (pos2 == 51) {
      pos2 = pos2 + 5;
      Serial.println("------2a-----");
      }
     else if (pos2 == 56) {
      Serial.println("------2b-----");
      pos2 = pos2 + 5;
      }
     else if (pos2 == 61) {
      Serial.println("------2c-----");
      pos2 = pos2 + 5;
      }
      myservo2.write(pos2);
    delay(15);        ;// waits 15ms for the servo to reach the position
  }
       
    Serial.print("pos = ");
  Serial.println(pos);
  Serial.print("pos2 = ");
  Serial.println(pos2);
}
