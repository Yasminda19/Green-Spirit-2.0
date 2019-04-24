#include <Servo.h>
//KRPAI SERVO TRACKING FIRE SENSOR MECHANISM WITH 12V WATER PUMP

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

void setup(){
  Serial.begin(9600);

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

/* void legsstop(){} */

void loop(){
  //FireSensorNumbers read if sensor starts to notice fire
  FireSensor1= digitalRead(FireSensor1);
  FireSensor2= digitalRead(FireSensor2);
  FireSensor3= digitalRead(FireSensor3);
  FireSensor4= digitalRead(FireSensor4);
  FireSensor5= digitalRead(FireSensor5);

  //if there's at least on sensor on, then turn off the legs
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

  //index is the angle of the minimum value
  //minimum[] is minimum analog result

    
  servo1.write(angle);
  digitalWrite(waterRelay, HIGH); //turn on the water pump
  delay(1000);
  digitalWrite(waterRelay, LOW); //turn off water pump
  delay(1000);
  }

//forever loop but still searching for fire


















