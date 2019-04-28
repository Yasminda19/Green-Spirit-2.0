int servangle;// servo angle variable
int FireSensorPins[] = {42,44,46,48,50};
int FireSensor1 ;
int FireSensor2 ;
int FireSensor3 ;
int FireSensor4 ;
int FireSensor5 ;
int FireSensor11[150] ;
int FireSensor21[150] ;
int FireSensor31[150] ;
int FireSensor41[150] ;
int FireSensor51[150] ;  
int angle;
int arahangle;


void cek_api(){
  pinMode(FireSensorPins[0], INPUT);
  pinMode(FireSensorPins[1], INPUT);
  pinMode(FireSensorPins[2], INPUT);
  pinMode(FireSensorPins[3], INPUT);
  pinMode(FireSensorPins[4], INPUT);
  delay(100);
  FireSensor1= digitalRead(FireSensorPins[0]);
  FireSensor2= digitalRead(FireSensorPins[1]);
  FireSensor3= digitalRead(FireSensorPins[2]);
  FireSensor4= digitalRead(FireSensorPins[3]);
  FireSensor5= digitalRead(FireSensorPins[4]);
  }

 void scan_api(){
  int k = 0;
myservo.write( 100, 150);
delay(500);
for(servangle = 150;servangle>0;servangle--){
  
myservo.write( 100, servangle); //write degree on servo based on loops

    Serial.print("servangle : ");
    // Serial.println(servangle);//print the serv angle of the servo

    FireSensor11[k]= analogRead(0);
   // Serial.println(FireSensor11[k]);

    FireSensor21[k]= analogRead(1);
  //  Serial.println(FireSensor21[k]);


    FireSensor31[k]= analogRead(2);
   // Serial.println(FireSensor31[k]);


    FireSensor41[k]= analogRead(3);
  //  Serial.println(FireSensor41[k]);


    FireSensor51[k]= analogRead(4);
  //  Serial.println(FireSensor51[k]);
  k = k +1 ;
delay(100);
}

for (int c = 0; c < 150 ; c++) {
  if (FireSensor31[c] >= FireSensor41[c] && FireSensor31[c] >= FireSensor21[c] && FireSensor31[c] >= 590 )
  arahangle = 150 - c ;
//  Serial.print("sudut akhir : ");
 // Serial.println(arahangle);
  }
   myservo.write( 100, arahangle);
  
  
  } 
