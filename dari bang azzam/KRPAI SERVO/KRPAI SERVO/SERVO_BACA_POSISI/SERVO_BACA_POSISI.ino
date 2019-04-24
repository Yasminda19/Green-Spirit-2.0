#include <DynamixelSerial.h>

int Position; //deklarasi variabel
void setup(){
Serial.begin(1000000);
Dynamixel.begin(1000000,2);  // setting kecepatan komunikasi untuk dynamixel dan pin 2 sebagai pengendali aliran data
delay(1000);}

void loop(){

int Pos1 = Dynamixel.readPosition(61);  //membaca posisi dynamixel
int Pos2 = Dynamixel.readPosition(62);
int Pos3 = Dynamixel.readPosition(63);

//menampilkan ke serial monitor
delay(1000);
Serial.print("Position1");
Serial.println(Pos1);
Serial.print("Position2");
Serial.println(Pos2);
Serial.print("Position3");
Serial.println(Pos3);


}
