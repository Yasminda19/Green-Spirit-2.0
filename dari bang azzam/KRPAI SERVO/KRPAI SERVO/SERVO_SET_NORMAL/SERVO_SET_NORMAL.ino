#include <DynamixelSerial.h>
float R,R1,r; // in milimeter
float teta,beta,lamda,gamma,alpa;
float Teta[7];
float Gamma[7];
float Alpa[7];
int coxa = 27; // in milimeter
int femur = 40; // in milimeter
int tibia = 60;// in milimeter
int x=67;
int y=0;
int y1=0;
int z=50;
int a=1;
void setup() {
Serial.begin(1000000);
Dynamixel.begin(1000000, 2);
}

void loop() { 
  
x=60;
y=30;
z=50;
hitung_invers_kinematik();
Dynamixel.move (13, (Teta[1])) ;    //kaki 1
Dynamixel.move (12, (Gamma[1])) ;
Dynamixel.move (11, (Alpa[1])) ;
x=60;
y=0;
z=50;
hitung_invers_kinematik();
Dynamixel.move (43, Teta[4]) ;    //kaki4
Dynamixel.move (42, Gamma[4]) ;
Dynamixel.move (41, Alpa[4]) ;
x=60;
y=-30;
z=50;
hitung_invers_kinematik();
Dynamixel.move (53, Teta[5]) ;    //kaki5
Dynamixel.move (52, Gamma[5]) ;
Dynamixel.move (51, Alpa[5]) ;
//****************************************************************************************

x=60;
y=30;
z=50;
hitung_invers_kinematik();
Dynamixel.move (23, Teta[2]) ;    //kaki2
Dynamixel.move (22, Gamma[2]) ;
Dynamixel.move (21, Alpa[2]) ;
x=60;
y=0;
z=50;
hitung_invers_kinematik();
Dynamixel.move (33, Teta[3]) ;    //kaki3
Dynamixel.move (32, Gamma[3]) ;
Dynamixel.move (31, Alpa[3]) ;

x=60;
y=-30;
z=50;
hitung_invers_kinematik();
Dynamixel.move (63, Teta[6]) ;    //kaki6
Dynamixel.move (62, Gamma[6]) ;
Dynamixel.move (61, Alpa[6]) ;
Serial.println(y1);
}
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





////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void kaki_gerak_1(){
x=60;
y=60-y1;
z=50;
hitung_invers_kinematik();
Dynamixel.move (13, (Teta[1])) ;    //kaki 1
Dynamixel.move (12, (Gamma[1])) ;
Dynamixel.move (11, (Alpa[1])) ;
x=60;
y=30-y1;
z=50;
hitung_invers_kinematik();
Dynamixel.move (43, Teta[4]) ;    //kaki4
Dynamixel.move (42, Gamma[4]) ;
Dynamixel.move (41, Alpa[4]) ;
x=60;
y=0-y1;
z=50;
hitung_invers_kinematik();
Dynamixel.move (53, Teta[5]) ;    //kaki5
Dynamixel.move (52, Gamma[5]) ;
Dynamixel.move (51, Alpa[5]) ;
//****************************************************************************************
x=60;
y=y1;
z=40;
hitung_invers_kinematik();
Dynamixel.move (23, Teta[2]) ;    //kaki2
Dynamixel.move (22, Gamma[2]) ;
Dynamixel.move (21, Alpa[2]) ;
x=60;
y=-30+y1;
z=40;
hitung_invers_kinematik();
Dynamixel.move (33, Teta[3]) ;    //kaki3
Dynamixel.move (32, Gamma[3]) ;
Dynamixel.move (31, Alpa[3]) ;
x=60;
y=-60+y1;
z=40;
hitung_invers_kinematik();
Dynamixel.move (63, Teta[6]) ;    //kaki6
Dynamixel.move (62, Gamma[6]) ;
Dynamixel.move (61, Alpa[6]) ;
}
////////////////////////////////////////////////////////////////////////////////////////////////
void kaki_gerak_2(){
x=60;
y=60-y1;
z=40;
hitung_invers_kinematik();
Dynamixel.move (13, Teta[1]) ;    //kaki 1
Dynamixel.move (12, Gamma[1]) ;
Dynamixel.move (11, Alpa[1]) ; 
x=60;
y=30-y1;
z=40;
hitung_invers_kinematik();
Dynamixel.move (43, Teta[4]) ;    //kaki4
Dynamixel.move (42, Gamma[4]) ;
Dynamixel.move (41, Alpa[4]) ;
x=60;
y=0-y1;
z=40;
hitung_invers_kinematik();
Dynamixel.move (53, Teta[5]) ;    //kaki5
Dynamixel.move (52, Gamma[5]) ;
Dynamixel.move (51, Alpa[5]) ;
//****************************************************************************
x=60;
y=y1;
z=50;
hitung_invers_kinematik();
Dynamixel.move (23, Teta[2]) ;    //kaki2
Dynamixel.move (22, Gamma[2]) ;
Dynamixel.move (21, Alpa[2]) ;
x=60;
y=-30+y1;
z=50;
hitung_invers_kinematik();
Dynamixel.move (33, Teta[3]) ;    //kaki3
Dynamixel.move (32, Gamma[3]) ;
Dynamixel.move (31, Alpa[3]) ;
x=60;
y=-60+y1;
z=50;
hitung_invers_kinematik();
Dynamixel.move (63, Teta[6]) ;    //kaki6
Dynamixel.move (62, Gamma[6]) ;
Dynamixel.move (61, Alpa[6]) ;

}
