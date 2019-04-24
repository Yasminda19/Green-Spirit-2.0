#include "DynamixelSerial/DynamixelSerial.h"

#define FireSensor1 A3
#define FireSensor2 A4
#define FireSensor3 A5
#define FireSensor4 A6
#define FireSensor5 A7
// Fire or Not

#include <SPI.h>
#include <ServoCds56.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>
ServoCds56 myservo;
Adafruit_LSM303_Mag_Unified mag = Adafruit_LSM303_Mag_Unified(12345);


int duration;                       //Stores duration of pulse in
int distancekanan;
int distancekiri;
int distancedepan = 100;
int distancekanan1;
int distancekiri1;
float x_sementara ;
float y_sementara ;

const float cx=2.65; //coxa
const float fm=4; //femur
const float tb=5.74; // tibia
float L, L1;
float alpha, alpha1,alpha2,beta,gama;

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

Servo servo1;
int servangle;// servo angle variable
int FireSensorPins[] = {3,4,5,6,7};          // 
/*int FireSensorPrevLow[] = {1,1,1,1,1};     // previously low flag set to true
int FireSensorUsed[]  = {0,0,0,0,0};*/     // previously used before going low
int currentFireSensorPin = 0; 
int SensorPin = 3; 
int ledPin = 13; //led to signal the calibration
int waterRelay = 12; //pin for waterpump relay
boolean Result; // result for fire sensor input
int index[4];
int angle;
int FireSensor1,FireSensor2,FireSensor3,FireSensor4,FireSensor5;


int servoNum = 3;
char inputCommand;                  // a string to hold incoming data

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


void trigono_xyz(float x, float y, float z)
{
 L1=sqrt(sq(x)+sq(y));
 gama=(atan2(y,x)/PI*180)+150;                               //sudut coxa
 L=sqrt(sq(L1-cx)+sq(z));
 beta=(acos((sq(tb)+sq(fm)-sq(L))/(2*tb*fm))/PI*180)+106;   //sudut tibia
 alpha1=acos(z/L)/PI*180;
 alpha2=acos((sq(fm)+sq(L)-sq(tb))/(2*fm*L))/PI*180;
 alpha=(alpha1+alpha2)-31.55;                                //sudut femur
 
}

void loop() {
  delay(1);
  ifApi();
}

void jalan() {
    trigono_xyz(6.65, -3, 0); //contoh x,y,z
    Serial.print("gama= ");
    Serial.print((gama/300)*1023);
    Serial.print(", alpha= ");
    Serial.print((alpha/300)*1023);
    Serial.print(", beta= ");
    Serial.print((beta/300)*1023);
    Serial.println();
  void leftwall_follow(){

  //sets the PID_value to be lowest to -45 and highest to 45
  if(PID_value< -correctionSpeed){
    PID_value = -correctionSpeed;
    //Serial.println(PID_value);
    //delay(1000);
  }
  if(PID_value> correctionSpeed){
    PID_value = correctionSpeed;
    //Serial.println(PID_value);
    // delay(1000);
  }

  if(PID_value < 0)
  {
    //away from the wall
    rightWheelSpeed = base_speedRight - PID_value   ;
    leftWheelSpeed = base_speedLeft - PID_value;
  }
  else
  {
    //right turn
    rightWheelSpeed = base_speedRight - PID_value;
    leftWheelSpeed = base_speedLeft - PID_value;
  }

  servoLeft.write(leftWheelSpeed);
  servoRight.write(rightWheelSpeed);
  digitalWrite(ledPin,HIGH);


  //sharp right turn(90 degree turn) when theres a wall on the left and wall at the front as well

  if(SonarDistance <7 && SonarDistance!=0  && IrDistance > 100)
  {
    sharp_right();
  }
}

void sharp_right()
{
  //servoLeft.write(90);
  //servoRight.write(90);
  //digitalWrite(ledPin,LOW);
  //delay(500);
  servoLeft.write(0);
  servoRight.write(0);
  digitalWrite(ledPin,HIGH);
  delay(430);
  //servoLeft.write(90);
  //servoRight.write(90);
  //digitalWrite(ledPin,LOW);
  //delay(500);
}

//Can only use either right or left wall following at one time. No point using both left and right wall follow
//Right wall follow is just here to show that it can follow right wall as well if need be. IT is exactlyt he same as left 
//wall following, nothing fancy
//----------------------------rightwallfollow--------------------------------------------------
void rightwall_follow(){

  
  if(PID_value< -correctionSpeedR){
    PID_value = -correctionSpeedR;
    //Serial.println(PID_value);
    //delay(1000);
  }
  if(PID_value> correctionSpeedR){
    PID_value = correctionSpeedR;
    //Serial.println(PID_value);
    // delay(1000);
  }

  if(PID_value < 0)
  {
    //away from the wall
    leftWheelSpeed = base_speedLeft + PID_value;
    rightWheelSpeed = base_speedRight + PID_value;
  }
  else
  {
    //left turn
    leftWheelSpeed = base_speedLeft + PID_value;
    rightWheelSpeed = base_speedRight + PID_value;
  }

  servoLeft.write(leftWheelSpeed);
  servoRight.write(rightWheelSpeed);
  digitalWrite(ledPin,HIGH);


  //sharp right turn when theres a wall on the left and wall at the front as well

  if(SonarDistance <8 && SonarDistance!=0  && IrDistance > 150)
  {
    sharp_left();
  }
}

void sharp_left()
{
  //servoLeft.write(90);
  //servoRight.write(90);
  //digitalWrite(ledPin,LOW);
  //delay(500);
  servoLeft.write(180);
  servoRight.write(180);
  digitalWrite(ledPin,HIGH);
  delay(480);
  //servoLeft.write(90);
  //servoRight.write(90);
  //digitalWrite(ledPin,LOW);
  //delay(500);
}



void bluetooth_control(){
 lastButton_r = LOW;  
 currentButton_r = LOW;  
 lastButton_l = LOW;     
 currentButton_l = LOW;
  
  if( Serial.available()>0 )       // if data is available to read
  {
    //declared val as char to keep it simple
    val = Serial.read();         // read it and store it in 'val'
  }
  if( val == 'f' )               // if 'f' was received--forward movement
  {
    Serial.println("forward movement activated"); 
    servoLeft.write(10); 
    servoRight.write(180);
    //delay(500);
    digitalWrite(ledPin,HIGH);
  } 
  else if(val == 'b') {            // b is for backward movement   
    servoLeft.write(180);
    servoRight.write(10);   
    digitalWrite(ledPin,HIGH);
  }
  else if(val == 'l')              // l is for 90 degree left movement
  {
    digitalWrite(ledPin,HIGH);
    servoLeft.write(180);
    servoRight.write(180);
    delay(460);
    val = 's';                     //stops after 90 degree movement 
  }
  else if(val == 'r')               // r is for right turn
  {
    digitalWrite(ledPin,HIGH);
    servoLeft.write(0);
    servoRight.write(0);
    delay(410);
    
    val = 's';                     //stops after 90 degree turn
  }
  else if(val == 's')               //s is for stop
  {
    digitalWrite(ledPin,LOW);
    servoLeft.write(90);
    servoRight.write(90);
    delay(480); 
    
  }
  else if(val == 'a')               //left little 
  {
    digitalWrite(ledPin,LOW);
    servoLeft.write(97);
    servoRight.write(97);
    delay(490); 
    
  } 
  else if(val == 'A')               //right little 
  {
    digitalWrite(ledPin,LOW);
    servoLeft.write(84);
    servoRight.write(84);
    delay(490); 
    
  }  
  delay(50);
}

//debounce function gives current state of the button...can input left button or right button as an attribute
boolean debounce (boolean last,int controlPin)
{
  boolean current = digitalRead(controlPin);
  //if the state has changed
  if(last !=current)
  {
    delay(5);
    current = digitalRead(controlPin);
  }
  return current;
}
        bacasensor();
      }


    }

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




void belokkananpresisi() {

  cekarah();
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
  }

void putarpresisi() {

  cekarah();
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












