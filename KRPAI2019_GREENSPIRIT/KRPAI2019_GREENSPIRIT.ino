#include <SPI.h>
#include <ServoCds56.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>
ServoCds56 myservo;
Adafruit_LSM303_Mag_Unified mag = Adafruit_LSM303_Mag_Unified(12345);

#define UTARA   1 //heading : 330
#define TIMUR   2 //heading : 34
#define SELATAN   3 //heading : 160
#define BARAT   4 //heading : 270
int duration;                                                          //Stores duration of pulse in
int distancekanan;
int distancekiri;
int distancedepan = 100;
int distancekanan1;
int distancekiri1;
float x_sementara ;
float y_sementara ;
int x_awal;
int y_awal;
float orientasi_x_awal ;
float orientasi_y_awal ;
int jumlahruangan;
int heading;
// LED
int lampu1 = 32;
int lampu2 = 34;
int lampu3 = 36;
int lampu4 = 38;
int lampu5 = 33;
int lampu6 = 35;
int lampu7 = 37;
int lampu8 = 39;
//---------------------


//sensor kompas---------------------
int batas_atas_u = 170 ;
int batas_bawah_u = 150 ;
int batas_atas_b = 55 ;
int batas_bawah_b = 35 ;
int batas_atas_s = 340 ;
int batas_bawah_s = 320 ;
int batas_atas_t = 270  ;
int batas_bawah_t = 250 ;

//--------------------------------
int maze[200];
int pulang[100];
int i = 0;

int nilaisensorgaris;
int countline = 0;
//int relay = 3;
int sensorpin = 7; //kanan
int sensorpin2 = 4; //kiri
int sensorpindepan = 2; //depan
int miringkanan = 5; //sensor miring kanan
int trigPin = 6; //sensor miring kiri
int linesensorpin = 8; //sensor garis
int voltPINlinesensor = 11; // sumber daya 5v untuk sensor garis
int waterRelay = 10;

int servoNum = 3;
char inputCommand ;         // a string to hold incoming data

boolean
ruangan = true;
boolean ceksensorgaris = true ;
boolean rumah = true;
boolean orientasi = true;
boolean kondisiawal = true;
int arah;
boolean mulai_jalan = true;
int jumlahbelokan = 0;
int audio = 0;

void setup () {
  Serial.begin (115200);
  myservo.begin ();
  mag.enableAutoRange(true);
  berdiri();
   myservo.write( 100, 75);
  delay(300);
  berdiri();
  myservo.write( 100, 75);
  delay(300);
  berdiri();
  myservo.write( 100, 75);
  pinMode(linesensorpin, INPUT);
  pinMode(voltPINlinesensor, OUTPUT);
  delay(300);
  digitalWrite(voltPINlinesensor, HIGH);
  pinMode(waterRelay, OUTPUT);
  pinMode(lampu1, OUTPUT);
pinMode(lampu2, OUTPUT);
pinMode(lampu3, OUTPUT);
pinMode(lampu4, OUTPUT);
pinMode(lampu5, OUTPUT);
pinMode(lampu6, OUTPUT);
pinMode(lampu7, OUTPUT);
pinMode(lampu8, OUTPUT);
  digitalWrite(waterRelay, HIGH);
  myservo.setVelocity(150);
  if (!mag.begin())
  {
    /* There was a problem detecting the LSM303 ... check your connections */
    Serial.println("Ooops, no LSM303 detected ... Check your wiring!");
    //while(1);
  }
/* while (audio < 5) {
  if (analogRead(5) < 10) {
    audio = audio +1;
    }
  delay(200);
  } */
  
  delay(300);
}
//-----------------------------------------------------------------------------
void loop() {
  delay(1);
  bacasensor();
  cekarah();
  telusur_kiri();
  //jalan();

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
      else {
        // putarpresisi();
        for (int i = 1; i < 11 ; i++) {
          belokkanan15(); //belok kiri 90
          // bacasensor();
        }
        bacasensor();
      }


    }

  }

}

void telusur_kiri() {

  if (rumah == true ) {
    while (rumah == true) {
      jalan();
    }
  }
  else {
    if (kondisiawal) {
      // sekarang tentukan orientasi mata angin robot
      setnilaiawal();
      //
   }
belokkekanan();
    //kodingan di labirin
 //   belokkekiri();
  //  jalanmaju();
jalanmaju3();
jalanmaju3();

  belokkekiri();
   // belokkekanan();
    jalanmaju3();
    jalanmaju3();
    putarbalik();

  }
}

void jalanmaju () {
  while (distancedepan > 14) {
    if ((distancekiri - distancekanan) >= 0) {
      maju3();
    }
    else if ((distancekiri - distancekanan) < 0) {
      maju4();
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
      bacasensor();
    }
    bacasensor();
    /* if (distancedepan > 14) {
       if ((distancekiri - distancekanan) >= 0) {
         maju3();
       }
       else if ((distancekiri - distancekanan) < 0) {
         maju4();
       }
      } */
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
    if (mulai_jalan) {
      maze[i] = arah ;
      i = i + 1;
      mulai_jalan = false;
    }
    else if (mulai_jalan == false) {
      maze[i] = maze[i - 1] ;
      i = i + 1;

    }
   cekarah();
    if (arah == UTARA && heading >= 340  ) {
          belokkiri15();
          cekarah();
        }
        else if (arah == TIMUR && heading >= 44  ) {
          belokkiri15();
          cekarah();
        }
        else if (arah == SELATAN && heading >= 170  ) {
          belokkiri15();
          cekarah();
        }
        else if (arah == BARAT && heading >= 280  ) {
          belokkiri15();
          cekarah();
        }
    if (arah == UTARA && heading <= 320  ) {
        belokkanan15();
        cekarah();
      }
      else if (arah == TIMUR && heading <= 24  ) {
        belokkanan15();
        cekarah();
      }
      else if (arah == SELATAN && heading <= 150  ) {
        belokkanan15();
        cekarah();
      }
      else if (arah == BARAT && heading <= 260  ) {
        belokkanan15();
        cekarah();
      }    
    bacasensor();
  }
}

void jalanmaju2 () {
  if (distancedepan > 14) {
    digitalWrite(lampu1,LOW);
    digitalWrite(lampu2,HIGH);
    digitalWrite(lampu3,HIGH);
    digitalWrite(lampu4,LOW);
    if ((distancekiri - distancekanan) >= 0) {
      maju3();
    }
    else if ((distancekiri - distancekanan) < 0) {
      maju4();
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
      bacasensor();
    }
    bacasensor();
    /* if (distancedepan > 14) {
       if ((distancekiri - distancekanan) >= 0) {
         maju3();
       }
       else if ((distancekiri - distancekanan) < 0) {
         maju4();
       }
      } */
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
    if (mulai_jalan) {
      maze[i] = arah ;
      i = i + 1;
      mulai_jalan = false;
    }
    else if (mulai_jalan == false) {
      maze[i] = maze[i - 1] ;
      i = i + 1;

    }
   cekarah();
    if (arah == UTARA && heading >= batas_atas_u  ) {
          belokkiri15();
          cekarah();
        }
        else if (arah == TIMUR && heading >= batas_atas_t  ) {
          belokkiri15();
          cekarah();
        }
        else if (arah == SELATAN && heading >= batas_atas_s  ) {
          belokkiri15();
          cekarah();
        }
        else if (arah == BARAT && heading >= batas_atas_b  ) {
          belokkiri15();
          cekarah();
        }
    if (arah == UTARA && heading <= batas_bawah_u  ) {
        belokkanan15();
        cekarah();
      }
      else if (arah == TIMUR && heading <= batas_bawah_t  ) {
        belokkanan15();
        cekarah();
      }
      else if (arah == SELATAN && heading <= batas_bawah_s  ) {
        belokkanan15();
        cekarah();
      }
      else if (arah == BARAT && heading <= batas_bawah_b  ) {
        belokkanan15();
        cekarah();
      }    
    bacasensor();
  }
}

void jalanmaju3 () {
  if (distancedepan > 7) {
    digitalWrite(lampu1,LOW);
    digitalWrite(lampu2,HIGH);
    digitalWrite(lampu3,HIGH);
    digitalWrite(lampu4,LOW);
    if ((distancekiri - distancekanan) >= 0) {
      maju3();
      maju3();
    }
    else if ((distancekiri - distancekanan) < 0) {
      maju4();
      maju4();
    }
   /* if (distancekiri < 5) {
      geserkanan();
    }
    else if (distancekanan < 6 && distancekanan > 0) {
      geserkiri();
    }
    else if (distancekanan1 < 6) {
      mundur();
      belokkiri15();
      belokkiri15();
      bacasensor();
    }
    */
    bacasensor();
    /* if (distancedepan > 14) {
       if ((distancekiri - distancekanan) >= 0) {
         maju3();
       }
       else if ((distancekiri - distancekanan) < 0) {
         maju4();
       }
      } */

      /*
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

    } */
    
    if (mulai_jalan) {
      maze[i] = arah ;
      i = i + 1;
      mulai_jalan = false;
    }
    else if (mulai_jalan == false) {
      maze[i] = maze[i - 1] ;
      i = i + 1;

    }
   cekarah();
    if (arah == UTARA && heading >= batas_atas_u  ) {
          belokkiri15();
          cekarah();
        }
        else if (arah == TIMUR && heading >= batas_atas_t  ) {
          belokkiri15();
          cekarah();
        }
        else if (arah == SELATAN && heading >= batas_atas_s  ) {
          belokkiri15();
          cekarah();
        }
        else if (arah == BARAT && heading >= batas_atas_b  ) {
          belokkiri15();
          cekarah();
        }
    if (arah == UTARA && heading <= batas_bawah_u  ) {
        belokkanan15();
        cekarah();
      }
      else if (arah == TIMUR && heading <= batas_bawah_t  ) {
        belokkanan15();
        cekarah();
      }
      else if (arah == SELATAN && heading <= batas_bawah_s  ) {
        belokkanan15();
        cekarah();
      }
      else if (arah == BARAT && heading <= batas_bawah_b  ) {
        belokkanan15();
        cekarah();
      }    
    bacasensor();
  }
}

  void belokkekiri() {
    if (jumlahbelokan < 3 ) {
      if (distancekiri >= 25) {
        jumlahbelokan = jumlahbelokan + 1;
        cekarah();
        int x_awal = x_sementara ;
        
    digitalWrite(lampu1,LOW);
    digitalWrite(lampu2,LOW);
    digitalWrite(lampu3,LOW);
    digitalWrite(lampu4,HIGH);
    jalanmaju3();
      jalanmaju3();
      jalanmaju3();
        for (int i = 1; i < 6 ; i++) {
          belokkiri15(); //belok kiri 90
          //  bacasensor();
        }
        cekarah();
        if (arah == UTARA && heading >= 280  ) {
          belokkiri15();
          cekarah();
        }
        else if (arah == TIMUR && heading >= 340  ) {
          belokkiri15();
          cekarah();
        }
        else if (arah == SELATAN && heading >= 44  ) {
          belokkiri15();
          cekarah();
        }
        else if (arah == BARAT && heading >= 170  ) {
          belokkiri15();
          cekarah();
        }
        if (maze[i - 1] == 1) {
          maze[i] = 4;
          i = i + 1;
          arah = BARAT;
          digitalWrite(lampu5,LOW);
    digitalWrite(lampu6,HIGH);
    digitalWrite(lampu7,LOW);
    digitalWrite(lampu8,LOW);
    
        }
        else if (maze[i - 1] == 2) {
          maze[i] = 1;
          i = i + 1;
          arah = UTARA;
          digitalWrite(lampu5,HIGH);
    digitalWrite(lampu6,LOW);
    digitalWrite(lampu7,LOW);
    digitalWrite(lampu8,LOW);
    
        }
        else if (maze[i - 1] == 3) {
          maze[i] = 2;
          i = i + 1;
          arah = TIMUR;
    digitalWrite(lampu5,LOW);
    digitalWrite(lampu6,LOW);
    digitalWrite(lampu7,HIGH);
    digitalWrite(lampu8,LOW);
    
        }
        else if (maze[i - 1] == 4) {
          maze[i] = 3;
          i = i + 1;
          arah = SELATAN;
    digitalWrite(lampu5,LOW);
    digitalWrite(lampu6,LOW);
    digitalWrite(lampu7,LOW);
    digitalWrite(lampu8,HIGH);
    
        }
      jalanmaju3();
      jalanmaju3();
      jalanmaju3();
      jalanmaju3();
      jalanmaju3();
      jalanmaju3();
      jalanmaju3();
      jalanmaju3();
      }
      bacasensor();
    }
    else if (jumlahbelokan >= 3 ) {
      if (distancekiri > 25) {
        if (distancedepan < 14 && distancekanan > 20) {
          belokkekanan();
        }
        else if (distancedepan < 14 && distancekanan <= 20) {

          putarbalik();
        }
        jalanmaju();

      }
      else if (distancekiri < 17) {
        jumlahbelokan = 0;
      }
    }
  delay(5);  
  bacasensor();
  
 // jalanmaju();
  }

  void belokkekanan() {
    if (distancekanan >= 25) {
      cekarah();
      int x_awal = x_sementara ;
      
    digitalWrite(lampu1,HIGH);
    digitalWrite(lampu2,LOW);
    digitalWrite(lampu3,LOW);
    digitalWrite(lampu4,LOW);
    jalanmaju3();
      jalanmaju3();
      jalanmaju3();
      for (int i = 1; i < 6 ; i++) {
        belokkanan15(); //belok kiri 90
        //  bacasensor();
      }
      cekarah();
      if (arah == UTARA && heading <= 24  ) {
        belokkanan15();
        cekarah();
      }
      else if (arah == TIMUR && heading <= 150  ) {
        belokkanan15();
        cekarah();
      }
      else if (arah == SELATAN && heading <= 260  ) {
        belokkanan15();
        cekarah();
      }
      else if (arah == BARAT && heading <= 320  ) {
        belokkanan15();
        cekarah();
      }
      if (maze[i - 1] == 1) {
        maze[i] = 2;
        i = i + 1;
        arah = TIMUR;
    digitalWrite(lampu5,LOW);
    digitalWrite(lampu6,LOW);
    digitalWrite(lampu7,HIGH);
    digitalWrite(lampu8,LOW);
      }
      else if (maze[i - 1] == 2) {
        maze[i] = 3;
        i = i + 1;
        arah = SELATAN ;
         digitalWrite(lampu5,LOW);
    digitalWrite(lampu6,LOW);
    digitalWrite(lampu7,LOW);
    digitalWrite(lampu8,HIGH);
      }
      else if (maze[i - 1] == 3) {
        maze[i] = 4;
        i = i + 1;
        arah = BARAT;
        digitalWrite(lampu5,LOW);
    digitalWrite(lampu6,HIGH);
    digitalWrite(lampu7,LOW);
    digitalWrite(lampu8,LOW);
      }
      else if (maze[i - 1] == 4) {
        maze[i] = 1;
        i = i + 1;
        arah = UTARA ;
    digitalWrite(lampu5,HIGH);
    digitalWrite(lampu6,LOW);
    digitalWrite(lampu7,LOW);
    digitalWrite(lampu8,LOW);
      }
    
      jalanmaju3();
      jalanmaju3();
      jalanmaju3();
      jalanmaju3();
      jalanmaju3();
      jalanmaju3();
      jalanmaju3();
      jalanmaju3();
    
    }

    bacasensor();
  }

  void putarbalik() {
    bacasensor();
    if (distancedepan <= 14 && distancekiri < 25 && distancekanan < 20) {
      
    digitalWrite(lampu1,LOW);
    digitalWrite(lampu2,HIGH);
    digitalWrite(lampu3,HIGH);
    digitalWrite(lampu4,HIGH);
      for (int i = 1; i < 11 ; i++) {
        belokkanan15(); //belok kiri 90
        //
      }
      if (arah == UTARA && heading <= 24  ) {
        belokkanan15();
        delay(50);
        cekarah();
        if (heading <= 24) {
          belokkanan15();
        }
        cekarah();
      }
      else if (arah == TIMUR && heading <= 150  ) {
        belokkanan15();
        delay(50);
        cekarah();
        if (heading <= 150) {
          belokkanan15();
        }
        cekarah();
      }
      else if (arah == SELATAN && heading <= 260  ) {
        belokkanan15();
        delay(50);
        cekarah();
        if (heading <= 260) {
          belokkanan15();
        }
        cekarah();
      }
      else if (arah == BARAT && heading <= 320  ) {
        belokkanan15();
        delay(50);
        cekarah();
        if (heading <= 320) {
          belokkanan15();
        }
      }

      bacasensor();
      if (maze[i - 1] == 1) {
        maze[i] = 3;
        i = i + 1;
        arah = SELATAN;
    digitalWrite(lampu5,LOW);
    digitalWrite(lampu6,LOW);
    digitalWrite(lampu7,LOW);
    digitalWrite(lampu8,HIGH);
      }
      else if (maze[i - 1] == 2) {
        maze[i] = 4;
        i = i + 1;
        arah = BARAT ;
    digitalWrite(lampu5,LOW);
    digitalWrite(lampu6,HIGH);
    digitalWrite(lampu7,LOW);
    digitalWrite(lampu8,LOW);
      }
      else if (maze[i - 1] == 3) {
        maze[i] = 1;
        i = i + 1;
        arah = UTARA ;
    digitalWrite(lampu5,HIGH);
    digitalWrite(lampu6,LOW);
    digitalWrite(lampu7,LOW);
    digitalWrite(lampu8,LOW);
      }
      else if (maze[i - 1] == 4) {
        maze[i] = 2;
        i = i + 1;
        arah = TIMUR ;
    digitalWrite(lampu5,LOW);
    digitalWrite(lampu6,LOW);
    digitalWrite(lampu7,HIGH);
    digitalWrite(lampu8,LOW);
      }


    }
  }
