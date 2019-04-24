/*
 Sensor serong kiri pakai HC SR04 
 
*/
int duration;                                                          //Stores duration of pulse in
int distancekanan;
int distancekiri;
int distancedepan = 100;
int distancekanan1;
int distancekiri1;
int relay = 3;
int sensorpin = 7; //kanan
int sensorpin2 = 4; //kiri

int sensorpindepan = 2; //depan
int miringkanan = 5; //sensor miring kanan
int trigPin = 6; //sensor miring kiri
int echoPin = 9; //sensor miring kiri Pin for SR 04

void setup()
{
Serial.begin(115200);
}

void loop()
{
bacakiri();
delay(10);
bacakanan();
delay(10);
bacadepan();
delay(10);
bacaserongkanan();
delay(10);
bacaserongkiri();
delay(10);
Serial.print(" kiri : ");
Serial.print(distancekiri);
Serial.print("   |||  depan : ") ;
Serial.print(distancedepan);
Serial.print("   |||  serong kiri : ") ;
Serial.print(distancekiri1);
Serial.print("   |||  serong kanan: ") ;
Serial.print(distancekanan1);
Serial.print("   |||  kanan : ") ;
Serial.println(distancekanan);
delay(100);
  
}

void bacakanan() {
   pinMode(sensorpin, OUTPUT);
  digitalWrite(sensorpin, LOW);                          // Make sure pin is low before sending a short high to trigger ranging
  delayMicroseconds(2);
  digitalWrite(sensorpin, HIGH);                         // Send a short 10 microsecond high burst on pin to start ranging
  delayMicroseconds(10);
  digitalWrite(sensorpin, LOW);                                  // Send pin low again before waiting for pulse back in
  pinMode(sensorpin, INPUT);
  duration = pulseIn(sensorpin, HIGH);                        // Reads echo pulse in from SRF05 in micro seconds
  distancekanan = duration/58;
  }

void bacakiri() {
   pinMode(sensorpin2, OUTPUT);
  digitalWrite(sensorpin2, LOW);                          // Make sure pin is low before sending a short high to trigger ranging
  delayMicroseconds(2);
  digitalWrite(sensorpin2, HIGH);                         // Send a short 10 microsecond high burst on pin to start ranging
  delayMicroseconds(10);
  digitalWrite(sensorpin2, LOW);                                  // Send pin low again before waiting for pulse back in
  pinMode(sensorpin2, INPUT);
  duration = pulseIn(sensorpin2, HIGH);                        // Reads echo pulse in from SRF05 in micro seconds
  distancekiri = duration/58;
  }

 void bacaserongkanan() {
  pinMode(miringkanan, OUTPUT);
  digitalWrite(miringkanan, LOW);                          // Make sure pin is low before sending a short high to trigger ranging
  delayMicroseconds(2);
  digitalWrite(miringkanan, HIGH);                         // Send a short 10 microsecond high burst on pin to start ranging
  delayMicroseconds(10);
  digitalWrite(miringkanan, LOW);                                  // Send pin low again before waiting for pulse back in
  pinMode(miringkanan, INPUT);
  duration = pulseIn(miringkanan, HIGH);                        // Reads echo pulse in from SRF05 in micro seconds
  distancekanan1 = duration / 58;
}
void bacaserongkiri() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);             
  distancekiri1 = duration /58 ;
} 

void bacadepan() {
  pinMode(sensorpindepan, OUTPUT);
  digitalWrite(sensorpindepan, LOW);                          // Make sure pin is low before sending a short high to trigger ranging
  delayMicroseconds(2);
  digitalWrite(sensorpindepan, HIGH);                         // Send a short 10 microsecond high burst on pin to start ranging
  delayMicroseconds(10);
  digitalWrite(sensorpindepan, LOW);                                  // Send pin low again before waiting for pulse back in
  pinMode(sensorpindepan, INPUT);
  duration = pulseIn(sensorpindepan, HIGH);                        // Reads echo pulse in from SRF05 in micro seconds
  distancedepan = duration / 58;
}
