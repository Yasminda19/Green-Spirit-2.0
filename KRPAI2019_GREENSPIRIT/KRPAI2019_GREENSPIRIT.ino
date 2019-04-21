#include <SPI.h>
#include <ServoCds56.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>
ServoCds56 myservo;
Adafruit_LSM303_Mag_Unified mag = Adafruit_LSM303_Mag_Unified(12345);


int duration;                                                          //Stores duration of pulse in
int distancekanan;
int distancekiri;
int distancedepan = 100;
int distancekanan1;
int distancekiri1;
float x_sementara ;
float y_sementara ;

int nilaisensorgaris;
int countline = 0;
int relay = 3;
int sensorpin = 7; //kanan
int sensorpin2 = 4; //kiri
int sensorpindepan = 2; //depan
int miringkanan = 5; //sensor miring kanan
int trigPin = 6; //sensor miring kiri
int linesensorpin = 8; //sensor garis
int voltPINlinesensor = 11; // sumber daya 5v untuk sensor garis

int servoNum = 3;
char inputCommand ;         // a string to hold incoming data

boolean
ruangan = true;
boolean ceksensorgaris = true ;

void setup () {
  Serial.begin (115200);
  myservo.begin ();
  mag.enableAutoRange(true);
  berdiri();
  delay(300);
  berdiri();
  delay(300);
  berdiri();
  pinMode(linesensorpin, INPUT);
  pinMode(voltPINlinesensor, OUTPUT);
  delay(300);
  digitalWrite(voltPINlinesensor, HIGH);
  myservo.setVelocity(150);
  if (!mag.begin())
  {
    /* There was a problem detecting the LSM303 ... check your connections */
    Serial.println("Ooops, no LSM303 detected ... Check your wiring!");
    //while(1);
  }
  delay(3000);
}
//-----------------------------------------------------------------------------
void loop() {
  delay(1);
  bacasensor();
  cekarah();
  jalan();


}


//--------------------------------------------------------------------------------
void jalan() {
  if (distancedepan > 14) {
    if ((distancekiri - distancekanan) >= 0) {
      maju3();
    }
    else if ((distancekiri - distancekanan) < 0) {
      maju4();
    }
  }
  bacasensor();
  if (distancedepan > 14) {
    if ((distancekiri - distancekanan) >= 0) {
      maju3();
    }
    else if ((distancekiri - distancekanan) < 0) {
      maju4();
    }
  }
  if (distancekiri < 5) {
    geserkanan();
  }
  else if (distancekanan < 6 && distancekanan > 0) {
    geserkiri();
  }
  else if (distancekanan1 < 6) {
    mundur();
    belokkiri15();
    belokkiri15();

  }
  else if (distancekiri1 <= 6 && distancekiri1 > 0 ) {
    mundur();
    belokkanan15();
    belokkanan15();

  }
  if (distancedepan <= 14) {
    delay(1000);
    bacasensor();
    if (distancekiri >= 25) {
      cekarah();
      int x_awal = x_sementara ;
      for (int i = 1; i < 6 ; i++) {
        belokkiri15(); //belok kiri 90
        //  bacasensor();
      }
      cekarah();
      if (abs(abs(x_awal) - abs(x_sementara)) < 20 ) {
        belokkiri15();
        cekarah();
      }

    }
    else if (distancekiri < 25) {
      if (distancekanan > 20) {
        cekarah();
        for (int i = 1; i < 6 ; i++) {
          belokkanan15(); //belok kiri 90
          // bacasensor();
        }
        if (abs(abs(x_awal) - abs(x_sementara)) < 20 ) {
          belokkiri15();
          cekarah();
        }
        bacasensor();


      }
      else {  putarpresisi();
      /*  for (int i = 1; i < 11 ; i++) {
          belokkanan15(); //belok kiri 90
          // bacasensor();
        } */
        bacasensor();
      }


    }

  }

}
