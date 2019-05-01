#include "DynamixelSerial/DynamixelSerial.h"

#include <SPI.h>
#include <ServoCds56.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>
ServoCds56 myservo;
Adafruit_LSM303_Mag_Unified mag = Adafruit_LSM303_Mag_Unified(12345);

/* TOLONG DI SET PIN NYA

// --------------------- SETUP UNTUK TRIGONOMETRI --------------------------//
float R,R1,r; // in milimeter
float teta,beta,lamda,gamma,alpa;
float Teta[7];
float Gamma[7];
float Alpa[7];
int coxa = 27; // in milimeter
int femur = 29; // in milimeter
int tibia = 50;// in milimeter // tibia juga harus diubah
int x=60;
int y=0;
int y1=0;
float z=50;
int a=1;  
float b=0.5;
float z1=0;
ServoCds56 myservo;


// ------------------------------- NAVIGASI DAN MOBILISASI -----------------------------------------------------//

int duration;                       //Stores duration of pulse in
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
int sensorpin = 7;                  //kanan
int sensorpin2 = 4;                 //kiri
int sensorpindepan = 2;             //depan
int miringkanan = 5;                //sensor miring kanan
int trigPin = 6;                    //sensor miring kiri
int linesensorpin = 8;              //sensor garis
int voltPINlinesensor = 11;         // sumber daya 5v untuk sensor garis


// -------------------- SETUP UNTUK API ------------------------//
Servo servo1;
int servangle;// servo angle variable
int FireSensorPins[] = {3,4,5,6,7};          // 
/*int FireSensorPrevLow[] = {1,1,1,1,1};     // previously low flag set to true
int FireSensorUsed[]  = {0,0,0,0,0};    // previously used before going low
int currentFireSensorPin = 0; 
int SensorPin = 3; 
int ledPin = 13; //led to signal the calibration
int waterRelay = 12; //pin for waterpump relay
boolean Result; // result for fire sensor input
int index[4];
int angle;
int FireSensor1,FireSensor2,FireSensor3,FireSensor4,FireSensor5;


int servoNum = 3;
char inputCommand;
*/        

// --------------------- SETUP UNTUK SENSOR GARIS ----------------------//
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
  servo1.attach(9); //attach servo to pin 9
  servo1.write(0); //servo starts at 0 degree
  delay(1000);


  pinMode(FireSensor1, INPUT);
  pinMode(FireSensor2, INPUT);
  pinMode(FireSensor3, INPUT);
  pinMode(FireSensor4, INPUT);
  pinMode(FireSensor5, INPUT);

  pinMode(ledPin, OUTPUT);
  delay(10000); // 10 seconds calibrate
  servo1.write(90); // put servo at center to begin

  pinMode(waterRelay, OUTPUT);
  digitalWrite(waterRelay, HIGH);
  if (!mag.begin())
  {
    /* There was a problem detecting the LSM303 ... check your connections */
    Serial.println("Ooops, no LSM303 detected ... Check your wiring!");
    //while(1);
  }
  delay(3000);
}

 //initialize minimum variable to each sensors
  int minimum1 = 400; 
  int minimum2 = 400;
  int minimum3 = 400;
  int minimum4 = 400;
  int minimum5 = 400;
  int minTotal = 400;
  //index to points to find the most minimum value
  int minimum[4];


void loop() {
  delay(1);
  ifApi();
}

// ---------------------------- INVERSE KINEMATIC ----------------------------------//
void hitung_invers_kinematik(){
R = sqrt((x*x) + (y*y));
R1 = sqrt((z*z) + (R*R));
r = sqrt((z*z) + ((R-coxa)*(R-coxa)));
teta = degrees ( asin(y/R));  //sudut servo pundak
beta = acos(z/r);  //sudut segitiga tungkai femur
lamda = acos(( (femur*femur) +(r*r)  -(tibia*tibia) )/(2*femur*r) );
gamma = degrees (beta+lamda);
alpa = degrees (acos(( (femur*femur) + (tibia*tibia) -(r*r) )/(2*femur*tibia) )); //sudut servo tungkai
Teta[1]= (teta + 150)/300*1024;
Teta[2]= (150 - teta)/300*1024;
Teta[3]= (teta + 150)/300*1024;
Teta[4]= (150 - teta)/300*1024;
Teta[5]= (teta + 150)/300*1024;
Teta[6]= (150 - teta)/300*1024;
Gamma[1]= (gamma + 60 )/300*1024;
Gamma[2]= (240 - gamma)/300*1024;
Gamma[3]= (gamma + 60 )/300*1024;
Gamma[4]= (240 - gamma)/300*1024;
Gamma[5]= (240 - gamma)/300*1024;
Gamma[6]= (gamma + 60 )/300*1024;
Alpa[1]= (240 - alpa)/300*1024;
Alpa[2]= (alpa + 60 )/300*1024;
Alpa[3]= (240 - alpa)/300*1024;
Alpa[4]= (alpa + 60 )/300*1024;
Alpa[5]= (alpa + 60 )/300*1024;
Alpa[6]= (240 - alpa)/300*1024;
//        θ       γ       α      konversi ke masing2 kaki
//1      n+150  n+60    240-n
//2      150-n  240-n   60+n
//3      n+150  n+60    240-n
//4      150-n  240-n   60+n
//5      n+150  240-n   60+n
//6      150-n  n+60    240-n
// 1 tungkai
// 2 tengah
// 3 atas
}


//----------------------------------- BELOK ---------------------------------------------------// 
void belokkananpresisi() {
  cekarah();
  maju();

  int x_awal = x_sementara ;
  Serial.println(" ");
  Serial.print("x awal  : ");
  Serial.println (x_awal);
  while (abs(abs(x_awal) - abs(x_sementara)) < 15 ) {
    belokkanan15();
    cekarah();
    }
  }
void belokkiripresisi() {

  cekarah();
  maju();
  int x_awal = x_sementara ;
  int y_awal = y_sementara ;
  Serial.println(" ");
  Serial.print("y awal  : ");
  Serial.println (y_awal);
  Serial.println (" ");
  do {
    belokkiri15();
    cekarah();
    } while (abs(abs(y_awal) - abs(y_sementara)) < 15 ) ;
Serial.print("selisih : ");
Serial.println(abs(abs(y_awal) - abs(y_sementara)));
    if (abs(abs(x_awal) - abs(x_sementara)) < 15) {
      belokkiri15();
      Serial.println("tambah 1");
      cekarah();
      }

void putarpresisi() {

  cekarah();
  maju();
  int x_awal = x_sementara ;
  int y_awal = y_sementara ;
  Serial.println(" ");
  Serial.print("x awal  : ");
  Serial.println (x_awal);
  if (x_awal <= 0 && y_awal <= 0 ) {//utara
  while (x_sementara < 0  || y_sementara < 0 || y_sementara < abs(y_awal)) {
    belokkanan15();
    cekarah();
    }
  }

 else if (x_awal <= 0 && y_awal >= 0 ) { //barat
  while (x_sementara < 0  || y_sementara > 0 || x_sementara < abs(x_awal) ) {
    belokkanan15();
    cekarah();
    }
  }

 else if (x_awal >= 0 && y_awal <= 0 ) { //timur
  while (x_sementara >= 0  || y_sementara <= 0 || y_sementara < abs(y_awal)  ) {
    belokkanan15();
    cekarah();
    }
  }

 else if (x_awal > 0 && y_awal > 0 ) { //selatan
  while (x_sementara > 0  || y_sementara > 0 || abs(y_sementara) < (y_awal-12))   {
    belokkanan15();
    cekarah();
    }
  }

  }

void cekarah () {
 // myservo.end();

 sensor_t sensor;
  mag.getSensor(&sensor);
  sensors_event_t event;
  mag.getEvent(&event);
  x_sementara = event.magnetic.x ;
  y_sementara = event.magnetic.y ;
  Serial.print("X: "); Serial.print(x_sementara); Serial.print("  ");
  Serial.print("Y: "); Serial.print(event.magnetic.y); Serial.print("  ");
  Serial.print("Z: "); Serial.print(event.magnetic.z);
  Serial.print("  ");Serial.println("uT");

  Serial.print("X Raw: "); Serial.print(mag.raw.x); Serial.print("  ");
  Serial.print("Y Raw: "); Serial.print(mag.raw.y); Serial.print("  ");
  Serial.print("Z Raw: "); Serial.print(mag.raw.z); Serial.println("");
  delay(10);
  //myservo.begin ();

  }

}


//checks whether fire is on or not
void ifApi(){
  FireSensor1= digitalRead(FireSensor1);
  FireSensor2= digitalRead(FireSensor2);
  FireSensor3= digitalRead(FireSensor3);
  FireSensor4= digitalRead(FireSensor4);
  FireSensor5= digitalRead(FireSensor5);

//if fire is on
 if(FireSensor1 == HIGH || FireSensor2 == HIGH || FireSensor3 == HIGH || FireSensor4 == HIGH || FireSensor5 == HIGH){
  
  //function all legs low

//int servangle is the angle of servo.
    //loop to read the analog value of the sensors
for(servangle = 0;servangle<180;servangl++){
  for(int k=0;k<180;k++){
    servo1.write(servangle); //write degree on servo based on loops

    serial.println(servangle); //print the serv angle of the servo

    FireSensor1= analogRead(FireSensor1);
    Serial.println(FireSensor1[k]);

    FireSensor2= analogRead(FireSensor2);
    Serial.println(FireSensor2[k]);


    FireSensor3= analogRead(FireSensor3);
    Serial.println(FireSensor3[k]);


    FireSensor4= analogRead(FireSensor4);
    Serial.println(FireSensor4[k]);


    FireSensor2= analogRead(FireSensor5);
    Serial.println(FireSensor5[k]);
  }
}

//loop to find the index of the most minimum value
  for (int c = 0; c < 180; c++){
        if (FireSensor1[c] < minimum1)
        {
           minimum[0] = FireSensor1[c];
           index[0] = c+1;
           
        }

        if (FireSensor2[c] < minimum2)
        {
           minimum[1] = FireSensor2[c];
           index[1] = c+1;
        }

        if (FireSensor3[c] < minimum3)
        {
           minimum[2] = FireSensor3[c];
           index[2] = c+1
        }

        if (FireSensor4[c] < minimum4)
        {
           minimum[3] = FireSensorPins[c];
           index4 = c+1;
        }
        
        if (FireSensor5[c] < minimum5)
        {
           minimum[4] = FireSensorPins[c];
           index5 = c+1;
        }
  }

//loop to find the position of the most minimum value

        for(int i=0;i<5;i++){
        if(minimum[i] < minTotal) 
        {
          minAll = minimum[i];
          angle = index[i];
        }
      }

  //angle needs to be positioned according the fixed position of the servo
  if(angle = index[0]){
    angle = angle + 0;
  }
  //if the minimum value is located on the minimum 1 then angle is between 0 to 24.
  if(angle = index[1]){
    angle = angle + 24;
  }
  if(angle = index[1]){
    angle = angle + 48;
  }
  if(angle = index[2]){
    angle = angle + 72;
  }
  if(angle = index[3]){
    angle = angle + 96;
  }
  if(angle = index[4]){
    angle = angle - 120;
  }

  //index is the angle of the minimum value
  //minimum[] is minimum analog result  
  servo1.write(angle);
  digitalWrite(waterRelay, HIGH); //turn on the water pump
  delay(1000);
  digitalWrite(waterRelay, LOW); //turn off water pump
  delay(1000);
  }



// if fire is off
else {
bacasensor();
cekarah();
jalan();}

}

void maju(){
///////////////////////////////////////////////////kaki 1 4 5 angkat
  if(y1<=0, z1<=0){
    a=1;
  }
  if(a==1){
     b==0.5;
    y1=y1+a; z1=z1+b;
x=60;
y=y1;
z=50-z1;
hitung_invers_kinematik();
myservo.write (13, (Teta[1])) ;    //kaki 1
myservo.write (12, (Gamma[1])) ;
myservo.write (11, (Alpa[1])) ;}
x=60;
y=y1-30;
z=50-z1;
hitung_invers_kinematik();
myservo.write (43, Teta[4]) ;    //kaki4
myservo.write (42, Gamma[4]) ;
myservo.write (41, Alpa[4]) ;
x=60;
y=y1-60;
z=50-z1;
hitung_invers_kinematik();
myservo.write (53, Teta[5]) ;    //kaki5
myservo.write (52, Gamma[5]) ;
myservo.write (51, Alpa[5]) ;
////////////////////////////////////////////////////// kaki 2 3 6 dorong
x=60;
y=60-y1;
z=50-z1+z1;
hitung_invers_kinematik();
myservo.write (23, Teta[2]) ;    //kaki2
myservo.write (22, Gamma[2]) ;
myservo.write (21, Alpa[2]) ;
x=60;
y=30-y1;
z=50-z1+z1;
hitung_invers_kinematik();
myservo.write (33, Teta[3]) ;    //kaki3
myservo.write (32, Gamma[3]) ;
myservo.write (31, Alpa[3]) ;
x=60;
y=0-y1;
z=50-z1+z1;
hitung_invers_kinematik();
myservo.write (6, Teta[6]) ;    //kaki6
myservo.write (62, Gamma[6]) ;
myservo.write (3, Alpa[6]) ;
  }
//***************************************************** kaki 1 4 5 angkat
if(z1==15){
  a=1;  
}
if(a==1){
  b=-0.5;
y1=y1+a;  z1=z1+b;
x=60;
y=y1;
z=50-z1;
hitung_invers_kinematik();
myservo.write (13, (Teta[1])) ;    //kaki 1
myservo.write (12, (Gamma[1])) ;
myservo.write (11, (Alpa[1])) ;}
x=60;
y=y1-30;
z=50-z1;
hitung_invers_kinematik();
myservo.write (43, Teta[4]) ;    //kaki4
myservo.write (42, Gamma[4]) ;
myservo.write (41, Alpa[4]) ;
x=60;
y=y1-60;
z=50-z1;
hitung_invers_kinematik();
myservo.write (53, Teta[5]) ;    //kaki5
myservo.write (52, Gamma[5]) ;
myservo.write (51, Alpa[5]) ;
//////////////////////////////////////////////////////// kaki 2 3 6 dorong
x=60;
y=60-y1;
z=50-z1+z1;
hitung_invers_kinematik();
myservo.write (23, Teta[2]) ;    //kaki2
myservo.write (22, Gamma[2]) ;
myservo.write (21, Alpa[2]) ;
x=60;
y=30-y1;
z=50-z1+z1;
hitung_invers_kinematik();
myservo.write (33, Teta[3]) ;    //kaki3
myservo.write (32, Gamma[3]) ;
myservo.write (31, Alpa[3]) ;
x=60;
y=0-y1;
z=50-z1+z1;
hitung_invers_kinematik();
myservo.write (6, Teta[6]) ;    //kaki6
myservo.write (62, Gamma[6]) ;
myservo.write (3, Alpa[6]) ;
}
/////////////////////////////////////////////////////////kaki 1 4 5 dorong
if (y1>=60, z1<=0){
  a=1;  
}
if (a==1){
  b=0.5;
  y1=y1-a;  z1=z1+b;
x=60;
y=y1;
z=50-z1+z1;
hitung_invers_kinematik();
myservo.write (13, Teta[1]) ;    //kaki 1
myservo.write (12, Gamma[1]) ;
myservo.write (11, Alpa[1]) ; }
x=60;
y=y1-30;
z=50-z1+z1;
hitung_invers_kinematik();
myservo.write (43, Teta[4]) ;    //kaki4
myservo.write (42, Gamma[4]) ;
myservo.write (41, Alpa[4]) ;
x=60;
y=y1-60;
z=50-z1+z1;
hitung_invers_kinematik();
myservo.write (53, Teta[5]) ;    //kaki5
myservo.write (52, Gamma[5]) ;
myservo.write (51, Alpa[5]) ;
//**************************************************** kaki 2 3 6 angkat
x=60;
y=y1;
z=50-z1;
hitung_invers_kinematik();
myservo.write (23, Teta[2]) ;    //kaki2
myservo.write (22, Gamma[2]) ;
myservo.write (21, Alpa[2]) ;
x=60;
y=-30+y1;
z=50-z1;
hitung_invers_kinematik();
myservo.write (33, Teta[3]) ;    //kaki3
myservo.write (32, Gamma[3]) ;
myservo.write (31, Alpa[3]) ;
x=60;
y=-60+y1;
z=50-z1;
hitung_invers_kinematik();
myservo.write (6, Teta[6]) ;    //kaki6
myservo.write (62, Gamma[6]) ;
myservo.write (3, Alpa[6]) ;
}
////////////////////////////////////////////////////// kaki 1 4 5 dorong
if(z1==15){
  a=1;  
}
if(a==1){
  b=-0.5;
y1=y1-a;  z1=z1+b;
x=60;
y=y1;
z=50-z1+z1;
hitung_invers_kinematik();
myservo.write (13, (Teta[1])) ;    //kaki 1
myservo.write (12, (Gamma[1])) ;
myservo.write (11, (Alpa[1])) ;}}
x=60;
y=y1-30;
z=50-z1+z1;
hitung_invers_kinematik();
myservo.write (43, Teta[4]) ;    //kaki4
myservo.write (42, Gamma[4]) ;
myservo.write (41, Alpa[4]) ;
x=60;
y=y1-60;
z=50-z1+z1;
hitung_invers_kinematik();
myservo.write (53, Teta[5]) ;    //kaki5
myservo.write (52, Gamma[5]) ;
myservo.write (51, Alpa[5]) ;
//////////////////////////////////////////////////////// kaki 2 3 6 angkat
x=60;
y=60-y1;
z=50-z1+z1;
hitung_invers_kinematik();
myservo.write (23, Teta[2]) ;    //kaki2
myservo.write (22, Gamma[2]) ;
myservo.write (21, Alpa[2]) ;
x=60;
y=30-y1;
z=50-z1+z1;
hitung_invers_kinematik();
myservo.write (33, Teta[3]) ;    //kaki3
myservo.write (32, Gamma[3]) ;
myservo.write (31, Alpa[3]) ;
x=60;
y=0-y1;
z=50-z1+z1;
hitung_invers_kinematik();
myservo.write (61, Teta[6]) ;    //kaki6
myservo.write (62, Gamma[6]) ;
myservo.write (63, Alpa[6]) ;
}






