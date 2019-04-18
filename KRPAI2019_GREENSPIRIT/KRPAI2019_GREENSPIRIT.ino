#include <SPI.h>
#include <ServoCds56.h>
ServoCds56 myservo;

int duration;                                                          //Stores duration of pulse in
int distancekanan;
int distancekiri;
int distancedepan = 100;
int distancekanan1;
int distancekiri1;
int relay = 3;
int sensorpin = 7; //kanan
int sensorpin2 = 4; //kiri

int sensorpindepan = 2; //depan
int miringkanan = 5; //sensor miring kanan
int trigPin = 6; //sensor miring kiri
int echoPin = 9; //

int servoNum = 3;
char inputCommand ;         // a string to hold incoming data
boolean inputComplete = false;

void setup () {
  Serial.begin (115200);
  myservo.begin ();
  berdiri();
  delay(300);
  berdiri();
  delay(300);
  berdiri();
  delay(300);
  myservo.setVelocity(150);
  delay(3000);
}
//-----------------------------------------------------------------------------
void loop() {
  delay(1);
  bacasensor();
  int range = map(distancedepan, 40, 0, 1, 2);
jalan();

  
}


//--------------------------------------------------------------------------------
 void jalan() {
  if (distancedepan > 14) {
    if ((distancekiri - distancekanan) <= 0) {
    maju3();
    }
    else if ((distancekiri - distancekanan) > 0) {
    maju4();
    }
    }
    bacasensor();
    if (distancedepan > 14) {
      if ((distancekiri - distancekanan) <= 0) {
    maju3();
    }
    else if ((distancekiri - distancekanan) > 0) {
    maju4();
    }
      }
    if (distancekiri < 5) {
      geserkanan();
    }
     if (distancekanan < 6 && distancekanan > 0) {
      geserkiri();
    }
     if (distancekanan1 < 6) {
      mundur();
      belokkiri15();
      belokkiri15();
      
    }
    if (distancekiri1 <= 6 && distancekiri1 > 0 ) {
      mundur();
      belokkanan15();
      belokkanan15();
      
    }
if (distancedepan <= 10) {
    delay(1000);
    bacasensor();
    if (distancekiri >= 25) {
      for (int i = 1; i < 5 ; i++) {
        belokkiri15(); //belok kiri 90
      //  bacasensor();
      }
    }
    if (distancekiri < 25) {
      if (distancekanan > 20){
      for (int i = 1; i < 5 ; i++) {
        belokkanan15(); //belok kiri 90
       // bacasensor();
      }
      }
else { for (int i = 1; i < 10 ; i++) {
        belokkanan15(); //belok kiri 90
        bacasensor();
        }
      }
    

  }

}
    
  }
  
 
