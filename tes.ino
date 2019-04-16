/*OutPuts*/
int IN_1 = 13; 
int IN_2 = 12; 
int IN_3 = 11; 
int IN_4 = 10; 
int INa=8;
int INb=9;
/*Inputs*/
int trigPin1 = 3;    // Trigger
int echoPin1 = 2;    // Echo
int trigPin2 = 5;    // Trigger
int echoPin2 = 4;    // Echo
int trigPin3 = 7;    // Trigger
int echoPin3 = 6;    // Echo
long duration1, cm1, inches1, duration2, cm2, inches2, duration3, cm3, inches3;
//inisialisasi sensor 1 sebelah kiri

#define echo1    2
#define trigger1 3

//inisialisasi sensor 2 sebelah depan
#define echo2    4
#define trigger2 5


//inisialisasi sensor 2 sebelah kanan
#define echo3    6
#define trigger3 7


void setup() {
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
}

void loop() {
 if(isRightOpen){
  turnRight();
 }
 else if(isFrontOpen){
  moveForward();
 }
 else if(isLeftOpen){
  turnLeft();
 }
 else
  turnAround();
}
boolean isRightOpen(){
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  pinMode(echoPin3, INPUT);
  duration3 = pulseIn(echoPin3, HIGH);
  cm3 = (duration3/2) / 29.1;
  if(cm3>3) return 1;
  else return 0;
}
boolean isLeftOpen(){
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  pinMode(echoPin1, INPUT);
  duration1 = pulseIn(echoPin1, HIGH);
  cm1 = (duration1/2) / 29.1;
  if(cm1>2) return 1;
  else return 0;
}
boolean isFrontOpen(){
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  pinMode(echoPin2, INPUT);
  duration2 = pulseIn(echoPin2, HIGH);

  cm2 = (duration2/2) / 29.1;  
  if(cm2>2) return 1;
  else return 0;
}

void moveForward(){
  digitalWrite(IN_1,HIGH);
  digitalWrite(IN_2,LOW);
  digitalWrite(IN_3,HIGH);
  digitalWrite(IN_4,LOW);
  delay(514);
}
void turnRight(){
  digitalWrite(IN_1,HIGH);
  digitalWrite(IN_2,LOW);
  digitalWrite(IN_3,LOW);
  digitalWrite(IN_4,HIGH);
  delay(514);
}
void turnLeft(){
  digitalWrite(IN_1,LOW);
  digitalWrite(IN_2,HIGH);
  digitalWrite(IN_3,HIGH);
  digitalWrite(IN_4,LOW);
  delay(514);
}
void turnAround(){
  
}
