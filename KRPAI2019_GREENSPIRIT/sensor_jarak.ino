void bacakanan() {
  pinMode(sensorpin, OUTPUT);
  digitalWrite(sensorpin, LOW);                          // Make sure pin is low before sending a short high to trigger ranging
  delayMicroseconds(2);
  digitalWrite(sensorpin, HIGH);                         // Send a short 10 microsecond high burst on pin to start ranging
  delayMicroseconds(10);
  digitalWrite(sensorpin, LOW);                                  // Send pin low again before waiting for pulse back in
  pinMode(sensorpin, INPUT);
  duration = pulseIn(sensorpin, HIGH);                        // Reads echo pulse in from SRF05 in micro seconds
  distancekanan = duration / 58;
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
  digitalWrite(trigPin, LOW);                          // Make sure pin is low before sending a short high to trigger ranging
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);                         // Send a short 10 microsecond high burst on pin to start ranging
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);                                  // Send pin low again before waiting for pulse back in
  pinMode(trigPin, INPUT);
  duration = pulseIn(trigPin, HIGH);                        // Reads echo pulse in from SRF05 in micro seconds
  distancekiri1 = duration / 58 ;
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
  distancekiri = duration / 58;
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

void bacasensor () {
  bacadepan();
  bacakiri();
  bacaserongkiri();
  bacakanan();
  bacaserongkanan();
  nilaijarak();

}

void ceksensor() {
  bacakiri();
  if (distancekiri < 5 ) {
    belokkanan18();
    distancekiri = 10;
  }
  bacakanan();
  if (distancekanan < 5 ) {
    belokkiri18();
    distancekanan = 10;
  }
  delay(5);

}

void cekdepan() {
  bacadepan();
  if (distancedepan < 70) {
    maju2();

  }
}

void nilaijarak() {
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

}
