#include <SPI.h>
#include <ServoCds56.h>
//#include <Wire.h>
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

void setup() {
Serial.begin(115200);
 myservo.begin ();
//Dynamixel.begin(1000000, 2);
}

//------------------------------------------- HITUNG INVERSE KINEMATIC -------------------------------------//

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

// ------------------------------------------ GERAK MULAI DISINI --------------------------------------------//

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
