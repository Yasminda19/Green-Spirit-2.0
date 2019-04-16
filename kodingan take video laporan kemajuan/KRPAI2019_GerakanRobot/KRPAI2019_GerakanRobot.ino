#include <SPI.h>
#include <ServoCds55.h>
ServoCds55 myservo;

int servoNum = 3;
char inputCommand ;         // a string to hold incoming data
boolean inputComplete = false;

void setup () {
  Serial.begin (115200);
  myservo.begin ();
delay(300);
berdiri();
delay(300);
berdiri();
 delay(300);
berdiri();
delay(300);
berdiri();
delay(300);
berdiri();
delay(300);
berdiri();
}

void loop() {
  //maju(); 
 //maju2();
 
 angkat1();
 angkat5();
 angkat4();
myservo.setVelocity(50);
  myservo.write( 61, 80); //pasangan 1
myservo.write( 41, 90); //pasangan 3
myservo.write( 21, 10); // pasangan 5

myservo.write( 51, 30);
myservo.write( 31, 60);
myservo.write( 11, 100);
delay(300);
turun1();
turun5();
turun4();
delay(300);
angkat2();
angkat3();
angkat6();
delay(300);
myservo.write( 61, 100); //pasangan 1
myservo.write( 41, 60); //pasangan 3
myservo.write( 21, 50); // pasangan 5

myservo.write( 51, 10);
myservo.write( 31, 90);
myservo.write( 11, 80);
delay(300);
turun2();
turun3();
turun6();
delay(300);
angkat1();
 angkat5();
 angkat4();
delay(300);
  myservo.write( 61, 100); //pasangan 1
myservo.write( 41, 90); //pasangan 3
myservo.write( 21, 50); // pasangan 5

myservo.write( 51, 30);
myservo.write( 31, 90);
myservo.write( 11, 100);
delay(300);
turun1();
turun5();
turun4();
delay(300);
angkat2();
angkat3();
angkat6();
delay(300);
 myservo.write( 61, 80); //pasangan 1
myservo.write( 41, 90); //pasangan 3
myservo.write( 21, 10); // pasangan 5

myservo.write( 51, 30);
myservo.write( 31, 60);
myservo.write( 11, 100);
delay(300);
turun2();
turun3();
turun6();
delay(300);//--------------------------
 turun1();
turun5();
turun4();
delay(200);
angkat2();
angkat3();
angkat6();
delay(300);
myservo.write( 61, 100); //pasangan 1
myservo.write( 41, 60); //pasangan 3
myservo.write( 21, 50); // pasangan 5

myservo.write( 51, 10);
myservo.write( 31, 90);
myservo.write( 11, 80);
delay(300);
turun2();
turun3();
turun6();
delay(300);
angkat1();
 angkat5();
 angkat4();
delay(300);
  myservo.write( 61, 100); //pasangan 1
myservo.write( 41, 90); //pasangan 3
myservo.write( 21, 50); // pasangan 5

myservo.write( 51, 30);
myservo.write( 31, 90);
myservo.write( 11, 100);
delay(300);
turun1();
turun5();
turun4();
delay(300);
angkat2();
angkat3();
angkat6();
delay(300);
 myservo.write( 61, 80); //pasangan 1
myservo.write( 41, 90); //pasangan 3
myservo.write( 21, 10); // pasangan 5

myservo.write( 51, 30);
myservo.write( 31, 60);
myservo.write( 11, 100);
delay(300);
turun2();
turun3();
turun6();
delay(200);
}
/*void maju2() {
  myservo.write( 61, 100); //pasangan 1
myservo.write( 41, 60); //pasangan 3
myservo.write( 21, 10); // pasangan 5

myservo.write( 51, 10);
myservo.write( 31, 60);
myservo.write( 11, 100);
delay(500);
turun2();
turun4();
turun6();
turun1();
turun3();
turun5();
delay(800); //angkat 2
angkat6();
angkat2();
angkat3();
delay(200);
myservo.write( 61, 70);//geser
myservo.write( 41, 60); //tetap
myservo.write( 21, 10);// geser

myservo.write( 31, 90);// geser
myservo.write( 11, 100); //tetap
myservo.write( 51, 10); //tetap
delay(800);
turun6();
turun2();
turun3();
delay(300);
angkat4();
angkat1();
angkat5();
delay(300);
myservo.write( 61, 100); //geser tekan
myservo.write( 41, 30); //geser
myservo.write( 21, 50); //geser tekan

myservo.write( 31, 30); //geser tekan
myservo.write( 11, 100); //tetap
myservo.write( 51, 40); //geser
 delay(800);
 turun4();
 turun1();
 turun5();
 delay(300);
 angkat6();
 angkat2();
 angkat3();
delay(300);
 myservo.write( 61, 100); //tetap
myservo.write( 41, 90); // tekan
myservo.write( 21, 10); //geser ke normal

myservo.write( 31, 60); //geser ke normal
myservo.write( 11, 60); // tekan
myservo.write( 51, 10); // tekan
delay(800);
turun6();
turun2();
turun3();
delay(300);
angkat4();
angkat1();
angkat5();
delay(1000);  
  
  }
void kanan() {
  myservo.write( 61, 100); //pasangan 1
myservo.write( 41, 60); //pasangan 3
myservo.write( 21, 10); // pasangan 5

myservo.write( 51, 10);
myservo.write( 31, 60);
myservo.write( 11, 100);
  
  
  }
  
/* void maju() {
   delay(500);
   myservo.setPoslimit(350);
delay(100);//-----------------------------------
      myservo.write( 62, 30); // 2 kaki naik
      myservo.write( 63, 30);

      myservo.write( 22, 30);
      myservo.write( 23, 30);

      myservo.write( 32, 80); // 1 kaki naik
      myservo.write( 33, 80);
delay(200);//-----------------------------------
      myservo.write( 61, 60); // geser
                              //
      myservo.write( 41, 80); // tetap
                              //
      myservo.write( 21, 60); // geser

       myservo.write( 11, 30); // tetap
                              //
      myservo.write( 31, 50); // geser
                              //
      myservo.write( 51, 30); // tetap
      
      Serial.println("servoNum ");
      Serial.println(3);
delay(500); //----------------------------------
      myservo.write( 62, 80); // 2 kaki turun
      myservo.write( 63, 80);
      
      myservo.write( 22, 80);
      myservo.write( 23, 80);

       myservo.write( 32, 30); // 1 kaki turun
      myservo.write( 33, 30);
      
delay(300); //---------------------------------------

      myservo.write( 42, 30); //1 kaki naik
      myservo.write( 43, 30);

       myservo.write( 12, 80); //2 kaki naik
      myservo.write( 13, 80);
      
      myservo.write( 52, 80); 
      myservo.write( 53, 80);

      delay(200); //----------------------------------
   myservo.write( 61, 80); //tetap
 
   myservo.write( 41, 60); // geser
 
   myservo.write( 21, 80); // tetap

    myservo.write( 11, 50); //geser
 
   myservo.write( 31, 30); // tetap
 
   myservo.write( 51, 50); // geser
 
 delay(500); //-----------------------------------
 
     myservo.write( 42, 80); //1 kaki turun
      myservo.write( 43, 80);

     myservo.write( 12, 30); //2 kaki turun
      myservo.write( 13, 30);
      
      myservo.write( 52, 30); 
      myservo.write( 53, 30); 
 delay(300); //------------------------------------
     myservo.write( 22, 30); //2 kaki naik
      myservo.write( 23, 30);
     
      myservo.write( 62, 30); 
      myservo.write( 63, 30);

       myservo.write( 32, 80); //1 kaki naik
      myservo.write( 33, 80);
 
 delay(200); //------------------------------------
  myservo.write( 41, 80); // geser
  
  myservo.write( 11, 30); //geser

  myservo.write( 51, 30); //geser
 delay(500); //-------------------------------------
      myservo.write( 22, 80); //2 kaki turun
      myservo.write( 23, 80);
     
      myservo.write( 62, 80); 
      myservo.write( 63, 80);

      myservo.write( 32, 30); //1 kaki turun
      myservo.write( 33, 30);
      
      delay(500);
  
   
  } */

 void angkat6() {
  myservo.write( 62, 70); 
  myservo.write( 63, 70);
  }
 void angkat4() {
  myservo.write( 42, 70); 
  myservo.write( 43, 70);
  } 
 void angkat2() {
  myservo.write( 22, 70); 
  myservo.write( 23, 70);
 }
 void angkat1() {
  myservo.write( 12, 40); 
  myservo.write( 13, 40);
  }
 void angkat3() {
  myservo.write( 32, 40); 
  myservo.write( 33, 40);
  } 
 void angkat5() {
  myservo.write( 52, 40); 
  myservo.write( 53, 40);
  }
   void turun1() {
  myservo.write( 12, 30); 
  myservo.write( 13, 30);
  }
 void turun3() {
  myservo.write( 32, 30); 
  myservo.write( 33, 30);
  } 
 void turun5() {
  myservo.write( 52, 30); 
  myservo.write( 53, 30);
  }

 void turun6() {
  myservo.write( 62, 80); 
  myservo.write( 63, 80);
  }
 void turun4() {
  myservo.write( 42, 80); 
  myservo.write( 43, 80);
  } 
 void turun2() {
  myservo.write( 22, 80); 
  myservo.write( 23, 80);
 } 
    
void berdiri() {
  myservo.write( 61, 100); //pasangan 1
myservo.write( 41, 60); //pasangan 3
myservo.write( 21, 10); // pasangan 5

myservo.write( 51, 10);
myservo.write( 31, 60);
myservo.write( 11, 100);
delay(500);
turun2();
turun4();
turun6();
turun1();
turun3();
turun5();
  delay(1000);
  myservo.write( 61, 100); //pasangan 1
myservo.write( 41, 60); //pasangan 3
myservo.write( 21, 10); // pasangan 5

myservo.write( 51, 10);
myservo.write( 31, 60);
myservo.write( 11, 100);
delay(500);
turun2();
turun4();
turun6();
turun1();
turun3();
turun5();
  delay(1000);
 }

     
