
void berdiri() {
  myservo.write( 61, 70); //pasangan 1
  myservo.write( 41, 60); //pasangan 3
  myservo.write( 21, 50); // pasangan 5 , nilai genap makin kecil makin ke depan

  myservo.write( 51, 50);
  myservo.write( 31, 60);
  myservo.write( 11, 60);
  delay(500);
  turun2();
  turun4();
  turun6();
  turun1();
  turun3();
  turun5();
  delay(1000);
  myservo.write( 61, 70); //pasangan 1
  myservo.write( 41, 60); //pasangan 3
  myservo.write( 21, 50); // pasangan 5

  myservo.write( 51, 50);
  myservo.write( 31, 60);
  myservo.write( 11, 60);
  delay(500);
  turun2();
  turun4();
  turun6();
  turun1();
  turun3();
  turun5();
  delay(1000);
}

















void maju3() {
   myservo.setVelocity(150);
  angkat1();
  updatestate();
  turun3();
  updatestate();
  angkat5();

  turun2();
  updatestate();
  angkat4();
  updatestate();
  turun6();
  delay(100);
  updatestate();
  myservo.write( 61, 80);
  updatestate();//pasangan 1
  myservo.write( 41, 50); //pasangan 3
  updatestate();
  myservo.write( 21, 70); // pasangan 5
updatestate();
  myservo.write( 51, 65);
  updatestate();
  myservo.write( 31, 45);
  updatestate();
  myservo.write( 11, 70);
  delay(100);
  updatestate();
  angkat3();
  updatestate();
  turun1();
  updatestate();
  turun5();

  angkat2();
  updatestate();
  turun4();
  updatestate();
  angkat6();
  delay(100);
  updatestate();
  myservo.write( 61, 55); //pasangan 1
  updatestate();
  myservo.write( 41, 70); //pasangan 3
  updatestate();
  myservo.write( 21, 60); // pasangan 5
updatestate();
  myservo.write( 51, 40);
  updatestate();
  myservo.write( 31, 75);
  updatestate();
  myservo.write( 11, 50);
  updatestate();
  delay(100);
  updatestate();

}

void maju4() {
  myservo.setVelocity(150);
  angkat1();
  updatestate();
  turun3();
  updatestate();
  angkat5();
updatestate();
  turun2();
  updatestate();
  angkat4();
  updatestate();
  turun6();
  delay(100);
  updatestate();
  myservo.write( 61, 80); //pasangan 1
  updatestate();
  myservo.write( 41, 65); //pasangan 3
  updatestate();
  myservo.write( 21, 70); // pasangan 5
updatestate();
  myservo.write( 51, 65);
  updatestate();
  myservo.write( 31, 50);
  updatestate();
  myservo.write( 11, 70);
  updatestate();
  delay(100);
  updatestate();
  angkat3();
  updatestate();
  turun1();
  updatestate();
  turun5();
updatestate();
  angkat2();
  updatestate();
  turun4();
  updatestate();
  angkat6();
  delay(100);
  updatestate();
  myservo.write( 61, 60);
  updatestate();//pasangan 1
  myservo.write( 41, 75); 
  updatestate();//pasangan 3
  myservo.write( 21, 60); 
  updatestate();// pasangan 5

  myservo.write( 51, 40);
  updatestate();
  myservo.write( 31, 80);
  updatestate();
  myservo.write( 11, 50);
  delay(100);
  updatestate();

}

void mundur() {
  myservo.setVelocity(250);
  delay(50); //angkat 2
  angkat6();
  angkat2();
  angkat3();
  delay(50);
  myservo.write( 61, 100); //geser tekan
  myservo.write( 41, 30); //geser
  myservo.write( 21, 50); //geser tekan
  myservo.write( 31, 30); //geser tekan
  myservo.write( 11, 100); //tetap
  myservo.write( 51, 40); //geser
 
 
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
  myservo.write( 21, 10);// geser
  myservo.write( 31, 90);// geser
  myservo.write( 11, 60); //tekan
  myservo.write( 51, 10); //tetap
   delay(300);
  
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
  
  
  delay(50);
  turun6();
  turun2();
  turun3();
  delay(50);
 


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




void belokkanan15() {
  myservo.setVelocity(200);
  delay(10);
  myservo.write( 61, 70); //pasangan 1
  myservo.write( 41, 60); //pasangan 3
  myservo.write( 21, 50); // pasangan 5 nilai genap makin kecil makin maju ke depan

  myservo.write( 51, 50);
  myservo.write( 31, 60);
  myservo.write( 11, 60);
  delay(50);

  angkat2();
  angkat6();
  angkat3();
  delay(50);

  myservo.write( 61, 90); //------kaki genap menuju gerakan
  myservo.write( 41, 60);
  myservo.write( 21, 70);

  myservo.write( 51, 50);
  myservo.write( 31, 80);
  myservo.write( 11, 60);
  delay(50);
  //turun1();
  turun2();
  turun6();
  turun3();
  delay(50);
  angkat1();
  angkat5();
  angkat4();
  delay(50);
  myservo.write( 61, 70); //kaki genap menekan
  myservo.write( 41, 80);
  myservo.write( 21, 50);

  myservo.write( 51, 70);//dari 10
  myservo.write( 31, 60);
  myservo.write( 11, 80);
  delay(50);
  turun1();
  turun5();
  turun4();
   delay(50);

  angkat2();
  angkat6();
  angkat3();
  delay(50);
   myservo.write( 61, 70); //pasangan 1
  myservo.write( 41, 60); //pasangan 3
  myservo.write( 21, 50); // pasangan 5 nilai genap makin kecil makin maju ke depan

  myservo.write( 51, 50);
  myservo.write( 31, 60);
  myservo.write( 11, 60);
  delay(50);
   turun2();
  turun6();
  turun3();
}

void belokkiri15() {
 //myservo.setVelocity(200);
  delay(10);
  myservo.write( 61, 70); //pasangan 1
  myservo.write( 41, 60); //pasangan 3
  myservo.write( 21, 50); // pasangan 5 nilai genap makin kecil makin maju ke depan

  myservo.write( 51, 50);
  myservo.write( 31, 60);
  myservo.write( 11, 60);
  delay(50);

  angkat2();
  angkat6();
  angkat3();
  delay(50);

  myservo.write( 61, 50); //------kaki genap menuju gerakan
  myservo.write( 41, 60);
  myservo.write( 21, 30);

  myservo.write( 51, 50);
  myservo.write( 31, 40);
  myservo.write( 11, 60);
  delay(50);
  //turun1();
  turun2();
  turun6();
  turun3();
  delay(50);
  angkat1();
  angkat5();
  angkat4();
  delay(50);
  myservo.write( 61, 70); //kaki genap menekan
  myservo.write( 41, 40);
  myservo.write( 21, 50);

  myservo.write( 51, 30);//dari 10
  myservo.write( 31, 60);
  myservo.write( 11, 40);
  delay(50);
  turun1();
  turun5();
  turun4();
   delay(50);

  angkat2();
  angkat6();
  angkat3();
  delay(50);
   myservo.write( 61, 70); //pasangan 1
  myservo.write( 41, 60); //pasangan 3
  myservo.write( 21, 50); // pasangan 5 nilai genap makin kecil makin maju ke depan

  myservo.write( 51, 50);
  myservo.write( 31, 60);
  myservo.write( 11, 60);
  delay(50);
   turun2();
  turun6();
  turun3();
} 



void geserkiri() {
  
  delay(100);
  myservo.write( 11, 60); //
   myservo.write( 12, 60);
  myservo.write( 13, 20);

  myservo.write( 31, 60); //
  myservo.write( 32, 60);
  myservo.write( 33, 20); //
  
   myservo.write( 51, 50); // naik
  myservo.write( 52, 60);
  myservo.write( 53, 20);

  myservo.write( 21, 50); //
   myservo.write( 22, 80);
  myservo.write( 23, 30);

  myservo.write( 41, 60); //
  myservo.write( 42, 70);
  myservo.write( 43, 80); //
  
   myservo.write( 61, 70); //
  myservo.write( 62, 80);
  myservo.write( 63, 30);
  //-----------------------------------------
  delay(100);
  myservo.write( 11, 60); //
   myservo.write( 12, 60);
  myservo.write( 13, 80);

  myservo.write( 31, 60); //
  myservo.write( 32, 60);
  myservo.write( 33, 80); //
  
   myservo.write( 51, 50); // naik
  myservo.write( 52, 60);
  myservo.write( 53, 80);

  myservo.write( 21, 50); //
   myservo.write( 22, 80);
  myservo.write( 23, 90);

  myservo.write( 41, 60); //
  myservo.write( 42, 70);
  myservo.write( 43, 80); //
  
   myservo.write( 61, 70); //
  myservo.write( 62, 80);
  myservo.write( 63, 90);
//----------------------------------
   delay(100);
  myservo.write( 11, 60); //
   myservo.write( 12, 70);
  myservo.write( 13, 20);

  myservo.write( 31, 60); //
  myservo.write( 32, 60);
  myservo.write( 33, 70); //
  
  myservo.write( 51, 50); // naik
  myservo.write( 52, 70);
  myservo.write( 53, 20);

  myservo.write( 21, 50); //
  myservo.write( 22, 80);
  myservo.write( 23, 90);

  myservo.write( 41, 60); //
  myservo.write( 42, 70);
  myservo.write( 43, 80); //
  
   myservo.write( 61, 70); //
  myservo.write( 62, 80);
  myservo.write( 63, 90);
  //---------------------------------------------
  delay(100);
  myservo.write( 11, 60); //
   myservo.write( 12, 70);
  myservo.write( 13, 20);

  myservo.write( 31, 60); //
  myservo.write( 32, 50);
  myservo.write( 33, 80); //
  
  myservo.write( 51, 50); // naik
  myservo.write( 52, 70);
  myservo.write( 53, 20);

  myservo.write( 21, 50); //
  myservo.write( 22, 80);
  myservo.write( 23, 100);

  myservo.write( 41, 60); //
  myservo.write( 42, 70);
  myservo.write( 43, 80); //
  
   myservo.write( 61, 70); //
  myservo.write( 62, 80);
  myservo.write( 63, 100);
  //-----------------------------------------------------------
  delay(100);
  myservo.write( 11, 60); //
   myservo.write( 12, 50);
  myservo.write( 13, 20);

  myservo.write( 31, 60); //
  myservo.write( 32, 60);
  myservo.write( 33, 80); //
  
  myservo.write( 51, 50); // naik
  myservo.write( 52, 50);
  myservo.write( 53, 20);

  myservo.write( 21, 50); //
  myservo.write( 22, 70);
  myservo.write( 23, 100);

  myservo.write( 41, 60); //
  myservo.write( 42, 80);
  myservo.write( 43, 90); //
  
   myservo.write( 61, 70); //
  myservo.write( 62, 70);
  myservo.write( 63, 100);
  //-----------------------------------------------------------
  delay(100);

  myservo.write( 11, 60); //
   myservo.write( 12, 50);
  myservo.write( 13, 20);

  myservo.write( 31, 60); //
  myservo.write( 32, 60);
  myservo.write( 33, 80); //
  
  myservo.write( 51, 50); // naik
  myservo.write( 52, 50);
  myservo.write( 53, 20);

  myservo.write( 21, 50); //
  myservo.write( 22, 70);
  myservo.write( 23, 40);

  myservo.write( 41, 60); //
  myservo.write( 42, 80);
  myservo.write( 43, 90); //
  
   myservo.write( 61, 70); //
  myservo.write( 62, 70);
  myservo.write( 63, 40);
  //-----------------------------------------------------------
  delay(100);

  myservo.write( 31, 60); //
  myservo.write( 32, 80);
  myservo.write( 33, 80); //
  delay(100);
  myservo.write( 11, 60); //
   myservo.write( 12, 60);
  myservo.write( 13, 20);

  myservo.write( 31, 60); //
  myservo.write( 32, 60);
  myservo.write( 33, 20); //
  
   myservo.write( 51, 50); // naik
  myservo.write( 52, 60);
  myservo.write( 53, 20);

  myservo.write( 21, 50); //
   myservo.write( 22, 80);
  myservo.write( 23, 30);

  myservo.write( 41, 60); //
  myservo.write( 42, 70);
  myservo.write( 43, 80); //
  
   myservo.write( 61, 70); //
  myservo.write( 62, 80);
  myservo.write( 63, 30);
  //-----------------------------------------
  delay(100);
  myservo.write( 11, 60); //
   myservo.write( 12, 60);
  myservo.write( 13, 80);

  myservo.write( 31, 60); //
  myservo.write( 32, 60);
  myservo.write( 33, 80); //
  
   myservo.write( 51, 50); // naik
  myservo.write( 52, 60);
  myservo.write( 53, 80);

  myservo.write( 21, 50); //
   myservo.write( 22, 80);
  myservo.write( 23, 90);

  myservo.write( 41, 60); //
  myservo.write( 42, 70);
  myservo.write( 43, 80); //
  
   myservo.write( 61, 70); //
  myservo.write( 62, 80);
  myservo.write( 63, 90);
//----------------------------------
   delay(100);
  myservo.write( 11, 60); //
   myservo.write( 12, 70);
  myservo.write( 13, 20);

  myservo.write( 31, 60); //
  myservo.write( 32, 60);
  myservo.write( 33, 70); //
  
  myservo.write( 51, 50); // naik
  myservo.write( 52, 70);
  myservo.write( 53, 20);

  myservo.write( 21, 50); //
  myservo.write( 22, 80);
  myservo.write( 23, 90);

  myservo.write( 41, 60); //
  myservo.write( 42, 70);
  myservo.write( 43, 80); //
  
   myservo.write( 61, 70); //
  myservo.write( 62, 80);
  myservo.write( 63, 90);
  //---------------------------------------------
  delay(100);
  myservo.write( 11, 60); //
   myservo.write( 12, 70);
  myservo.write( 13, 20);

  myservo.write( 31, 60); //
  myservo.write( 32, 50);
  myservo.write( 33, 80); //
  
  myservo.write( 51, 50); // naik
  myservo.write( 52, 70);
  myservo.write( 53, 20);

  myservo.write( 21, 50); //
  myservo.write( 22, 80);
  myservo.write( 23, 100);

  myservo.write( 41, 60); //
  myservo.write( 42, 70);
  myservo.write( 43, 80); //
  
   myservo.write( 61, 70); //
  myservo.write( 62, 80);
  myservo.write( 63, 100);
  //-----------------------------------------------------------
  delay(100);
  myservo.write( 11, 60); //
   myservo.write( 12, 50);
  myservo.write( 13, 20);

  myservo.write( 31, 60); //
  myservo.write( 32, 60);
  myservo.write( 33, 80); //
  
  myservo.write( 51, 50); // naik
  myservo.write( 52, 50);
  myservo.write( 53, 20);

  myservo.write( 21, 50); //
  myservo.write( 22, 70);
  myservo.write( 23, 100);

  myservo.write( 41, 60); //
  myservo.write( 42, 80);
  myservo.write( 43, 90); //
  
   myservo.write( 61, 70); //
  myservo.write( 62, 70);
  myservo.write( 63, 100);
  //-----------------------------------------------------------
  delay(100);

  myservo.write( 11, 60); //
   myservo.write( 12, 50);
  myservo.write( 13, 20);

  myservo.write( 31, 60); //
  myservo.write( 32, 60);
  myservo.write( 33, 80); //
  
  myservo.write( 51, 50); // naik
  myservo.write( 52, 50);
  myservo.write( 53, 20);

  myservo.write( 21, 50); //
  myservo.write( 22, 70);
  myservo.write( 23, 40);

  myservo.write( 41, 60); //
  myservo.write( 42, 80);
  myservo.write( 43, 90); //
  
   myservo.write( 61, 70); //
  myservo.write( 62, 70);
  myservo.write( 63, 40);
  //-----------------------------------------------------------
  delay(100);

  myservo.write( 31, 60); //
  myservo.write( 32, 80);
  myservo.write( 33, 80);
  delay(100);
  turun1();
  turun2();
  turun3();
  turun4();
  turun5();
  turun6();
  delay(100);
  
  }

void geserkanan() {
  myservo.setVelocity(150);
 
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



void padam_api() {
 // digitalWrite(3, LOW);
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
//  digitalWrite(relay, HIGH);
  delay(1000);


}
