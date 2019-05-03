const byte ledPin = 13;
const byte interruptPin = 2; // Pin sensor garis
const byte interruptPin2 = 3; // Pin Digital sensor api
volatile byte state = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(interruptPin, INPUT);
   pinMode(interruptPin2, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), garis, FALLING);
  attachInterrupt(digitalPinToInterrupt(interruptPin2), api, FALLING);
  digitalWrite(ledPin, 0);
  digitalWrite(7, 1);
}

void loop() {
  delay(50000);

}

void garis() {
  state = 1; // ketika sensor mendeteksi garis, LED akan menyala
  digitalWrite(ledPin, state);
}

void api() {
  state = 0; // ketika sensor mendeteksi api, LED akan mati
  digitalWrite(ledPin, state);
  
  }
