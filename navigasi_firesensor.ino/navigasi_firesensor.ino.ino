#include <Servo.h> 
 
Servo tracker;
char inputCommand ;         // a string to hold incoming data
boolean inputComplete = false;
int eastpin = A0;
int westpin = A1;
int middlepin = A2;
int servoNum ;
int w1 = 0;   //Create variables for the east and west sensor values
int w2 = 0;   
int error = 0;          
int calibration = 204;  //Calibration offset to set error to zero when both sensors receive an equal amount of light
int trackerPos = 90;    //Create a variable to store the servo position
 
void setup() 
{ Serial.begin(9600);
  tracker.attach(11);
  tracker.write(90);
  delay(3000);
   tracker.write(20);
   delay(1000);// attaches the servo on pin 11 to the servo object
} 
 
 
void loop() 
{ 
 /* east = analogRead(eastpin);   
  middle = analogRead(middlepin);
  west = analogRead(westpin); */
 // if (servoNum==0){
 /* for (servoNum = 20; servoNum < 160; servoNum++) {
        tracker.write( servoNum);
       Serial.print("pos : "); Serial.print(servoNum);
       Serial.print("  Kanan : ");
       Serial.print(analogRead(eastpin));
       Serial.print("  Tengah : ");
       Serial.print(analogRead(middlepin));
       Serial.print("  Kiri : ");
       Serial.println(analogRead(westpin));
       delay(20);
      } 
   */
  serialEvent();
  
  if (inputComplete) {
    Serial.print("Your command is: "); Serial.println(inputCommand); Serial.println("");
    controlServo(inputCommand);
    // clear the command:
    inputCommand = 0;
    inputComplete = false;
  }
}

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

      for (servoNum = 0; servoNum < 180; servoNum++) {
        for(int i=0;i<=180;i++){
        Serial.print(analogRead(eastpin));
        }
        tracker.write( servoNum);
       Serial.println("pos : "); Serial.print(servoNum);
       Serial.print("  Kanan : ");
       Serial.println(analogRead(eastpin));
       Serial.print("  Tengah : ");
       Serial.println(analogRead(middlepin));
       Serial.print("  Kiri : ");
       Serial.println(analogRead(westpin));
       delay(10);
      }
      break;
      case 'l':
     for (int x = 0 ; x < 30; x++){
      Serial.print(analogRead(westpin));
      delay(100);
      }
     
      break;
      case 'm':
      for (int x = 0 ; x < 30; x++){
      Serial.print(analogRead(middlepin));
      delay(100);
      }
      
      break;
       case 'r':
       for (int x = 0 ; x < 30; x++){
      Serial.print(analogRead(eastpin));
      delay(100);
      }
      
       
      break;
      case 'g':
       tracker.write( 90);
      break;
      
      case 'a':
       for (int x = 0 ; x < 30; x++) {
        Serial.print(x); Serial.println("  Kanan : ");
        Serial.println(analogRead(eastpin));
        Serial.println("  Tengah : ");
        Serial.print(analogRead(middlepin));
        Serial.print("  Kiri : ");
        Serial.println(analogRead(westpin));
        delay(100); 
        }
      break;
   default:
      Serial.println("Please give me an available instruction:");  
      break; 
  }
} 

