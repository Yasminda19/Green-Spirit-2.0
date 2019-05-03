/*
  # This Sample code is to test the Digital Servo Shield.
  # Editor : Leff, original by YouYou@DFRobot(Version1.0)
  # Date   : 2016-1-19
  # Ver    : 1.1
  # Product: Digital Servo Shield for Arduino

  # Hardwares:
  1. Arduino UNO
  2. Digital Servo Shield for Arduino
  3. Digital Servos( Compatible with AX-12,CDS55xx...etc)
  4. Power supply:6.5 - 12V

  # How to use:
  If you don't know your Servo ID number, please
  1. Open the serial monitor, and choose NewLine,115200
  2. Send command:'d',when it's finished, please close the monitor and re-open it
  3. Send the command according to the function //controlServo()//
*/

#include <SPI.h>
#include <ServoCds55.h>
ServoCds55 myservo;

int servoNum = 3;
char inputCommand ;         // a string to hold incoming data
boolean inputComplete = false;

void setup () {
  Serial.begin (115200);
  myservo.begin ();
 
}

void loop () {
   // myservo.rotate(servoNum, 150); //   Anti CW    ID:1  Velocity: 150_middle velocity  300_max
      delay(2000);
    //  myservo.rotate(servoNum, 0);
      delay(2000);
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
      myservo.write(254, 300);
      myservo.write(52, 300);
      myservo.write(23, 300);
      myservo.write(63, 300);
     /* for (int servoNum = 240; servoNum < 255; servoNum++) {
        myservo.write( servoNum, 300);
       Serial.println(servoNum);
       delay(300);
      }
      */
      Serial.print("Servo 300 : ");
      Serial.println(servoNum);
     //ID:1  Pos:300  velocity:150
      delay(3000);
      myservo.write(254, 0);
       myservo.write(52, 0);
       myservo.write(23, 0);
        myservo.write(63, 0);
    /*  for (int servoNum = 240; servoNum < 255; servoNum++) {
        myservo.write( servoNum, 0);
       Serial.println(servoNum);
       delay(300);
      } */
      delay(3000);
      Serial.println("ok");
      //ID:1  Pos:0  velocity:150
      break;
    case 'v':
      myservo.setVelocity(100);// set velocity to 100(range:0-300) in Servo mode
      break;
    case 'm':
      myservo.rotate(servoNum, 150); //   Anti CW    ID:1  Velocity: 150_middle velocity  300_max
      delay(2000);
      myservo.rotate(servoNum, -150); //  CW     ID:1  Velocity: -150_middle velocity  -300_max
      delay(2000);
      myservo.rotate(servoNum, 0); //Stop
      myservo.Reset(servoNum);    //Only Dynamixel AX need this instruction while changing working mode
      //CDS55xx don't need this, it can switch freely between its working mode
      break;
    case 'r':
      myservo.Reset(servoNum);//Restore ID2 servo to factory Settings ( ID:1  Baud rate:1000000)
      break;
    //        case 'i':
    //        myservo.SetID(2,1);//ID:1   newID:2
    //        break;
    case 'd':  //Reset servo to ID>>servoNum. If you don't know your Servo ID, please send "d".
      Serial.print("Please wait..");
      for (int buf = 0; buf < 255; buf++) {
        myservo.SetID( buf, servoNum);
        if (buf % 50 == 0) Serial.print(".");
      }
      delay(2000);
      Serial.println("");   Serial.println("Please close the monitor and re-open it to play your servo! ");
      break;
    default:
      Serial.println("Please give me an available instruction:");
      Serial.println("  Servo mode: p_Set position; v_Set velocity.");
      Serial.println("  Motor mode: m_Rotate; v_Set velocity.");
      Serial.println("  Others: r_Reset servo to factory settings; i_Change servo ID."); Serial.println("");
  }
}
