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
int echoPin = 9; //sensor miring kiri

int servoNum = 3;
char inputCommand ;         // a string to hold incoming data
boolean inputComplete = false;

void setup () {
  Serial.begin (115200);
  myservo.begin ();
   pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  berdiri2();
  bacasensor();
  delay(100);
  bacasensor();
  berdiri2();
  delay(100);
  bacasensor();
  berdiri2();
  delay(100);
  bacasensor();
  myservo.setVelocity(150);
  delay(100);
}
//-----------------------------------------------------------------------------
void loop() {
serialEvent();
  if (inputComplete) {
    Serial.print("Your command is: "); Serial.println(inputCommand); Serial.println("");
    controlServo(inputCommand);
    // clear the command:
    inputCommand = 0;
    inputComplete = false;
  }


  
}

//--------------------------------------------------------------------------------
void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    if (inChar == '\n') {
      inputComplete = true;
      break;
    }
    inputCommand += inChar;
  }
}

void controlServo(char val) {
  switch (val) {
    case 'p':
    maju1();
    maju1();
      break;
    case 'v':
      maju2();
      maju2();
      break;
    case 'm':
      geserkanan();
      break;
    case 'r':
     belokkiri18();
      break;
      case 't':
     belokkanan18();
      break;
    case 'y':
     bacasensor();
      break;
      case 'u':
     mundur();
      break;
      case 'i':
     maju3();
     maju3();
      break;
      case 'z':
     berdiri();
      break;
      case 'x':
     berdiri2();
     
      break;
    case 'd':  //Reset servo to ID>>servoNum. If you don't know your Servo ID, please send "d".
      
      break;
    default:
      Serial.println("Please give me an available instruction:");
     
  }
}

void maju1() {
   myservo.setVelocity(150);
  angkat1();
  turun3();
  angkat5();

  turun2();
  angkat4();
  turun6();
  delay(100);
  myservo.write( 61, 80); //pasangan 1
  myservo.write( 41, 45); //pasangan 3
  myservo.write( 21, 70); // pasangan 5

  myservo.write( 51, 65);
  myservo.write( 31, 45);
  myservo.write( 11, 70);
  delay(100);
  angkat3();
  turun1();
  turun5();

  angkat2();
  turun4();
  angkat6();
  delay(100);
  myservo.write( 61, 55); //pasangan 1
  myservo.write( 41, 75); //pasangan 3
  myservo.write( 21, 50); // pasangan 5

  myservo.write( 51, 40);
  myservo.write( 31, 75);
  myservo.write( 11, 50);
  delay(100);




}


void mundur() {
  myservo.setVelocity(250);
  delay(50); //angkat 2
  angkat6();
  angkat2();
  angkat3();
  delay(50);
  myservo.write( 61, 100); //geser tekan
//  delay(300);
  myservo.write( 41, 30); //geser
 //  delay(1000);
  myservo.write( 21, 50); //geser tekan
// delay(1000);
  myservo.write( 31, 30); //geser tekan
  // delay(1000);
  myservo.write( 11, 100); //tetap
  // delay(1000);
  myservo.write( 51, 40); //geser
 //  delay(300);
 /*
  myservo.write( 61, 70);//geser
  myservo.write( 41, 90); //tekan
  myservo.write( 21, 10);// geser

  myservo.write( 31, 90);// geser
  myservo.write( 11, 60); //tekan
  myservo.write( 51, 10); //tetap
  */
  delay(50);
  turun6();
  turun2();
  turun3();
  delay(50);
  angkat4();
  angkat1();
  angkat5();
  delay(50);
  myservo.write( 61, 70);//geser
   delay(300);
  myservo.write( 41, 90); //tekan
 //  delay(1000);
  myservo.write( 21, 10);// geser
//delay(1000);
  myservo.write( 31, 90);// geser
//   delay(1000);
  myservo.write( 11, 60); //tekan
//   delay(1000);
  myservo.write( 51, 10); //tetap
   delay(300);
  /*
  myservo.write( 61, 100); //geser tekan
  myservo.write( 41, 30); //geser
  myservo.write( 21, 50); //geser tekan

  myservo.write( 31, 30); //geser tekan
  myservo.write( 11, 100); //tetap
  myservo.write( 51, 40); //geser
  */
  delay(50);
  turun4();
  turun1();
  turun5();
  delay(50);
  angkat6();
  angkat2();
  angkat3();
  delay(50);
  myservo.write( 61, 100); //tekan
  myservo.write( 41, 30); // geser
  myservo.write( 21, 50); //tekan

  myservo.write( 31, 30); //tekan
  myservo.write( 11, 100); // geser
  myservo.write( 51, 40); // geser
  
  /*
  myservo.write( 61, 70); //tetap
  myservo.write( 41, 90); // tekan
  myservo.write( 21, 10); //geser ke normal

  myservo.write( 31, 90); //geser ke normal
  myservo.write( 11, 60); // tekan
  myservo.write( 51, 10); // tekan
  */
  delay(50);
  turun6();
  turun2();
  turun3();
  delay(50);
 /* angkat4();
  angkat1();
  angkat5();
  delay(50); */
  /*
  myservo.write( 61, 100); //tekan
  myservo.write( 41, 30); // geser
  myservo.write( 21, 50); //tekan

  myservo.write( 31, 30); //tekan
  myservo.write( 11, 100); // geser
  myservo.write( 51, 40); // geser
  */
/*myservo.write( 61, 70); //tetap
  myservo.write( 41, 90); // tekan
  myservo.write( 21, 10); //geser ke normal

  myservo.write( 31, 90); //geser ke normal
  myservo.write( 11, 60); // tekan
  myservo.write( 51, 10); // tekan
  turun4();
  turun1();
  turun5();
  delay(50);
*/



}













void maju2() {
  myservo.setVelocity(150);
  delay(50); //angkat 2
  angkat6();
  angkat2();
  angkat3();
  delay(50);
  myservo.write( 61, 70);//geser
  myservo.write( 41, 90); //tekan
  myservo.write( 21, 10);// geser

  myservo.write( 31, 90);// geser
  myservo.write( 11, 60); //tekan
  myservo.write( 51, 10); //tetap
  delay(50);
  turun6();
  turun2();
  turun3();
  delay(50);
  angkat4();
  angkat1();
  angkat5();
  delay(50);
  myservo.write( 61, 100); //geser tekan
  myservo.write( 41, 30); //geser
  myservo.write( 21, 50); //geser tekan

  myservo.write( 31, 30); //geser tekan
  myservo.write( 11, 100); //tetap
  myservo.write( 51, 40); //geser
  delay(50);
  turun4();
  turun1();
  turun5();
  delay(50);
  angkat6();
  angkat2();
  angkat3();
  delay(50);
  myservo.write( 61, 70); //tetap
  myservo.write( 41, 90); // tekan
  myservo.write( 21, 10); //geser ke normal

  myservo.write( 31, 90); //geser ke normal
  myservo.write( 11, 60); // tekan
  myservo.write( 51, 10); // tekan
  delay(50);
  turun6();
  turun2();
  turun3();
  delay(50);
  angkat4();
  angkat1();
  angkat5();
  delay(50);
  myservo.write( 61, 100); //tekan
  myservo.write( 41, 30); // geser
  myservo.write( 21, 50); //tekan

  myservo.write( 31, 30); //tekan
  myservo.write( 11, 100); // geser
  myservo.write( 51, 40); // geser

  turun4();
  turun1();
  turun5();
  delay(50);




}

void maju3() {
   myservo.setVelocity(150);
  angkat1();
  turun3();
  angkat5();

  turun2();
  angkat4();
  turun6();
  delay(100);
  myservo.write( 61, 80); //pasangan 1
  myservo.write( 41, 50); //pasangan 3
  myservo.write( 21, 70); // pasangan 5

  myservo.write( 51, 65);
  myservo.write( 31, 45);
  myservo.write( 11, 70);
  delay(100);
  angkat3();
  turun1();
  turun5();

  angkat2();
  turun4();
  angkat6();
  delay(100);
  myservo.write( 61, 55); //pasangan 1
  myservo.write( 41, 70); //pasangan 3
  myservo.write( 21, 60); // pasangan 5

  myservo.write( 51, 40);
  myservo.write( 31, 75);
  myservo.write( 11, 50);
  delay(100);

}


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

void angkat61() {
  myservo.write( 62, 70);
  myservo.write( 63, 70);
}
void angkat41() {
  myservo.write( 42, 70);
  myservo.write( 43, 70);
}
void angkat21() {
  myservo.write( 22, 70);
  myservo.write( 23, 70);
}
void angkat11() {
  myservo.write( 12, 40);
  myservo.write( 13, 40);
}
void angkat31() {
  myservo.write( 32, 40);
  myservo.write( 33, 40);
}
void angkat51() {
  myservo.write( 52, 40);
  myservo.write( 53, 40);
}
void turun11() {
  myservo.write( 12, 30);
  myservo.write( 13, 60);
}
void turun31() {
  myservo.write( 32, 30);
  myservo.write( 33, 50);
}
void turun51() {
  myservo.write( 52, 30);
  myservo.write( 53, 50);
}

void turun61() {
  myservo.write( 62, 50);
  myservo.write( 63, 100);
}
void turun41() {
  myservo.write( 42, 70);
  myservo.write( 43, 100);
}
void turun21() {
  myservo.write( 22, 50);
  myservo.write( 23, 100);
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

void berdiri2() {
  myservo.write( 61, 70); //pasangan 1
  myservo.write( 41, 60); //pasangan 3
  myservo.write( 21, 50); // pasangan 5

  myservo.write( 51, 50);
  myservo.write( 31, 60);
  myservo.write( 11, 60);
  delay(500);
  turun21();
  turun41();
  turun61();
  turun11();
  turun31();
  turun51();
  delay(1000);
  myservo.write( 61, 70); //pasangan 1
  myservo.write( 41, 60); //pasangan 3
  myservo.write( 21, 50); // pasangan 5

  myservo.write( 51, 50);
  myservo.write( 31, 60);
  myservo.write( 11, 60);
  delay(500);
  turun21();
  turun41();
  turun61();
  turun11();
  turun31();
  turun51();
  delay(1000);
}

void belokkiri18() {
  myservo.setVelocity(150);
  myservo.write( 61, 100);
  myservo.write( 41, 60);
  myservo.write( 21, 10);

  myservo.write( 51, 10);
  myservo.write( 31, 60);
  myservo.write( 11, 100);
  delay(100);

  angkat2();
  angkat6();
  angkat3();
  delay(100);

  myservo.write( 61, 70); //------kaki genap menuju gerakan
  myservo.write( 41, 60);
  myservo.write( 21, 10);

  myservo.write( 51, 10);
  myservo.write( 31, 30);
  myservo.write( 11, 100);
  delay(100);
  turun1();
  turun2();
  turun6();
  turun3();
  delay(100);
  angkat1();
  angkat5();
  angkat4();
  delay(100);
  myservo.write( 61, 100); //kaki genap menekan
  myservo.write( 41, 60);
  myservo.write( 21, 50);

  myservo.write( 51, 0);//dari 10
  myservo.write( 31, 90);
  myservo.write( 11, 60);
  delay(100);
  turun1();
  turun5();
  turun4();
  delay(100);
}

void belokkanan18() {
  myservo.write( 61, 100);
  myservo.write( 41, 60);
  myservo.write( 21, 10);

  myservo.write( 51, 10);
  myservo.write( 31, 60);
  myservo.write( 11, 100);
  delay(100);

  angkat1();
  angkat5();
  angkat4();
  delay(100);
  myservo.write( 61, 100); //kaki ganjil menuju gerakan
  myservo.write( 41, 90); //1
  myservo.write( 21, 10);

  myservo.write( 51, 40); //2
  myservo.write( 31, 60);
  myservo.write( 11, 100);
  delay(100);
  turun1();
  turun5();
  turun4();
  delay(100);
  angkat2();
  angkat6();
  angkat3();
  delay(100);
  myservo.write( 61, 100); //kaki ganjil menekan
  myservo.write( 41, 60); //
  myservo.write( 21, 10);

  myservo.write( 51, 10); //
  myservo.write( 31, 60);
  myservo.write( 11, 60); //
  delay(100);
  turun2();
  turun6();
  turun3();
  delay(100);

}

void geserkanan1() {
  
  myservo.write( 11, 100); //kaki ganjil menekan
   myservo.write( 12, 30);
  myservo.write( 13, 50);

  myservo.write( 31, 10); //
  myservo.write( 32, 30);
  myservo.write( 33, 50); //
  
   myservo.write( 51, 10); //
  myservo.write( 52, 30);
  myservo.write( 53, 50);
  
  }
  
  void geserkanan() {
  myservo.setVelocity(150);
  /* myservo.write( 11, 60); //kaki ganjil menekan
   myservo.write( 12, 30);
  myservo.write( 13, 60);

  myservo.write( 31, 60); //
  myservo.write( 32, 30);
  myservo.write( 33, 60); //
  
   myservo.write( 51, 50); //
  myservo.write( 52, 30);
  myservo.write( 53, 60);

  myservo.write( 21, 50); //kaki ganjil menekan
   myservo.write( 22, 50);
  myservo.write( 23, 100);

  myservo.write( 41, 60); //
  myservo.write( 42, 70);
  myservo.write( 43, 100); //
  
   myservo.write( 61, 70); //
  myservo.write( 62, 50);
  myservo.write( 63, 100); */
  //---------------------------------------------------------
  delay(150);
  myservo.write( 11, 60); //kaki ganjil menekan
   myservo.write( 12, 30);
  myservo.write( 13, 10);

  myservo.write( 31, 60); //
  myservo.write( 32, 30);
  myservo.write( 33, 10); //
  
   myservo.write( 51, 50); //
  myservo.write( 52, 30);
  myservo.write( 53, 10);

  myservo.write( 21, 50); //kaki ganjil menekan
   myservo.write( 22, 80);
  myservo.write( 23, 100);

  myservo.write( 41, 60); //
  myservo.write( 42, 65);
  myservo.write( 43, 100); //
  
   myservo.write( 61, 70); //
  myservo.write( 62, 80);
  myservo.write( 63, 100);
  //-----------------------------------------
  delay(150);
myservo.write( 41, 60); //
  myservo.write( 42, 80);
  myservo.write( 43, 100);
  delay(150);
  //-----------------------------------------
  myservo.write( 11, 60); //kaki ganjil menekan
  myservo.write( 12, 50);
  myservo.write( 13, 60);

  myservo.write( 31, 60); //
  myservo.write( 32, 30);
  myservo.write( 33, 10); //
  
  myservo.write( 51, 50); //
  myservo.write( 52, 50);
  myservo.write( 53, 60);

  myservo.write( 21, 50); //kaki ganjil menekan
  myservo.write( 22, 80);
  myservo.write( 23, 70);

  myservo.write( 41, 60); //
  myservo.write( 42, 80);
  myservo.write( 43, 70); //
  
  myservo.write( 61, 70); //
  myservo.write( 62, 80);
  myservo.write( 63, 70);
  //-------------------------------------------repeat
delay(150);
  myservo.write( 12, 30);
  myservo.write( 13, 60);

  myservo.write( 52, 30);
  myservo.write( 53, 60);

delay(150);
myservo.write( 11, 60); //kaki ganjil menekan
   myservo.write( 12, 30);
  myservo.write( 13, 10);

  myservo.write( 31, 60); //
  myservo.write( 32, 30);
  myservo.write( 33, 10); //
  
   myservo.write( 51, 50); //
  myservo.write( 52, 30);
  myservo.write( 53, 10);

  myservo.write( 21, 50); //kaki ganjil menekan
   myservo.write( 22, 80);
  myservo.write( 23, 60);

  myservo.write( 41, 60); //
  myservo.write( 42, 80);
  myservo.write( 43, 60); //
  
   myservo.write( 61, 70); //
  myservo.write( 62, 80);
  myservo.write( 63, 60);


  //------------------------------------------repeat2
   delay(150);
   myservo.write( 11, 60); //kaki ganjil menekan
   myservo.write( 12, 50);
  myservo.write( 13, 60);

  myservo.write( 31, 60); //
  myservo.write( 32, 30);
  myservo.write( 33, 10); //
  
   myservo.write( 51, 50); //
  myservo.write( 52, 50);
  myservo.write( 53, 60);

  myservo.write( 21, 50); //kaki ganjil menekan
   myservo.write( 22, 70);
  myservo.write( 23, 70);

  myservo.write( 41, 60); //
  myservo.write( 42, 60);
  myservo.write( 43, 100); //
  
   myservo.write( 61, 70); //
  myservo.write( 62, 70);
  myservo.write( 63, 70);
//----------------------------------
  delay(150);
   myservo.write( 11, 60); //kaki ganjil menekan
   myservo.write( 12, 30);
  myservo.write( 13, 60);

  myservo.write( 31, 60); //
  myservo.write( 32, 30);
  myservo.write( 33, 10); //
  
   myservo.write( 51, 50); //
  myservo.write( 52, 30);
  myservo.write( 53, 60);

  myservo.write( 21, 50); //kaki ganjil menekan
   myservo.write( 22, 70);
  myservo.write( 23, 70);

  myservo.write( 41, 60); //
  myservo.write( 42, 70);
  myservo.write( 43, 100); //
  
   myservo.write( 61, 70); //
  myservo.write( 62, 70);
  myservo.write( 63, 70);
  //--------------------------------
  delay(150);
   myservo.write( 11, 60); //kaki ganjil menekan
   myservo.write( 12, 30);
  myservo.write( 13, 10);

  myservo.write( 31, 60); //
  myservo.write( 32, 30);
  myservo.write( 33, 10); //
  
   myservo.write( 51, 50); //
  myservo.write( 52, 30);
  myservo.write( 53, 10);

  myservo.write( 21, 50); //kaki ganjil menekan
   myservo.write( 22, 70);
  myservo.write( 23, 60);

  myservo.write( 41, 60); //
  myservo.write( 42, 70);
  myservo.write( 43, 60); //
  
   myservo.write( 61, 70); //
  myservo.write( 62, 70);
  myservo.write( 63, 60);
  }

void bacakanan() {
  pinMode(sensorpin, OUTPUT);
  digitalWrite(sensorpin, LOW);                          // Make sure pin is low before sending a short high to trigger ranging
  delayMicroseconds(2);
  digitalWrite(sensorpin, HIGH);                         // Send a short 10 microsecond high burst on pin to start ranging
  delayMicroseconds(10);
  digitalWrite(sensorpin, LOW);                                  // Send pin low again before waiting for pulse back in
  pinMode(sensorpin, INPUT);
  duration = pulseIn(sensorpin, HIGH);                        // Reads echo pulse in from SRF05 in micro seconds
  distancekanan = duration / 58;
}
void bacaserongkanan() {
  pinMode(miringkanan, OUTPUT);
  digitalWrite(miringkanan, LOW);                          // Make sure pin is low before sending a short high to trigger ranging
  delayMicroseconds(2);
  digitalWrite(miringkanan, HIGH);                         // Send a short 10 microsecond high burst on pin to start ranging
  delayMicroseconds(10);
  digitalWrite(miringkanan, LOW);                                  // Send pin low again before waiting for pulse back in
  pinMode(miringkanan, INPUT);
  duration = pulseIn(miringkanan, HIGH);                        // Reads echo pulse in from SRF05 in micro seconds
  distancekanan1 = duration / 58;
}
void bacaserongkiri() {
 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distancekiri1 = duration / 58 ;
}

void bacakiri() {
  pinMode(sensorpin2, OUTPUT);
  digitalWrite(sensorpin2, LOW);                          // Make sure pin is low before sending a short high to trigger ranging
  delayMicroseconds(2);
  digitalWrite(sensorpin2, HIGH);                         // Send a short 10 microsecond high burst on pin to start ranging
  delayMicroseconds(10);
  digitalWrite(sensorpin2, LOW);                                  // Send pin low again before waiting for pulse back in
  pinMode(sensorpin2, INPUT);
  duration = pulseIn(sensorpin2, HIGH);                        // Reads echo pulse in from SRF05 in micro seconds
  distancekiri = duration / 58;
}

void bacadepan() {
  pinMode(sensorpindepan, OUTPUT);
  digitalWrite(sensorpindepan, LOW);                          // Make sure pin is low before sending a short high to trigger ranging
  delayMicroseconds(2);
  digitalWrite(sensorpindepan, HIGH);                         // Send a short 10 microsecond high burst on pin to start ranging
  delayMicroseconds(10);
  digitalWrite(sensorpindepan, LOW);                                  // Send pin low again before waiting for pulse back in
  pinMode(sensorpindepan, INPUT);
  duration = pulseIn(sensorpindepan, HIGH);                        // Reads echo pulse in from SRF05 in micro seconds
  distancedepan = duration / 58;
}

void bacasensor () {
  bacadepan();
  bacakiri();
  bacaserongkiri();
  bacakanan();
  bacaserongkanan();
nilaijarak();

}

void ceksensor() {
  bacakiri();
  if (distancekiri < 5 ) {
    belokkanan18();
    distancekiri = 10;
  }
  bacakanan();
  if (distancekanan < 5 ) {
    belokkiri18();
    distancekanan = 10;
  }
  delay(5);

}

void cekdepan() {
  bacadepan();
  if (distancedepan < 70) {
    maju2();

  }
}

void padam_api() {
  digitalWrite(3, LOW);
  myservo.write( 61, 100);
  myservo.write( 41, 60);
  myservo.write( 21, 10);

  myservo.write( 51, 10);
  myservo.write( 31, 60);
  myservo.write( 11, 100);
  delay(100);
  myservo.write( 61, 80);
  myservo.write( 41, 30);
  myservo.write( 21, 0);

  myservo.write( 51, 10);
  myservo.write( 31, 40);
  myservo.write( 11, 80);
  delay(3000);
  digitalWrite(relay, HIGH);
  delay(1000);


}

void nilaijarak() {
  Serial.print(" kiri : ");
Serial.print(distancekiri);
Serial.print("   |||  depan : ") ;
Serial.print(distancedepan);
Serial.print("   |||  serong kiri : ") ;
Serial.print(distancekiri1);
Serial.print("   |||  serong kanan: ") ;
Serial.print(distancekanan1);
Serial.print("   |||  kanan : ") ;
Serial.println(distancekanan);
 
  }

 
