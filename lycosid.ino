/*

* COPYRIGHT
    Copyright (C) 2016  IR64 POLITEKNIK NEGERI JEMBER, http://www.polije.ac.id/

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

* AUTHOR
    Faruq Sandi (faruq.sandi@gmail.com)
    Muhammad Fadlullah (muhammadfadlullah9@gmail.com)
    Ahmad Waris Al H (warishafidz@gmail.com)

*/

/* 
 * The library DynamixelSerial can be moved to arduino instalation-path/libraries 
 * so autocorrect can detected for the Dynamixel syntaxt on arduino IDE
 * 
 * move directory DynamixelSerial library to default instalation of arduino
 * default is
 * 
 * #su
 * #mv DynamixelSerial /usr/share/arduino/libraries/
 * #chmod 751 /usr/share/arduino/libraries/DynamixelSerial
 * 
 */
 
#include "DynamixelSerial/DynamixelSerial.h"

//  Directive macro for every PIN on arduino nano
#define RX    0  //  RX from IC 74HC (Dynamixel IC buffer)
#define TX    1  //  TX to IC 74HC
#define PING5 2  
#define SIG   3  //  Triger Dynamixel
#define START 4  //  Tombol Start
#define LED   5  //  LED indicator fire detection before distinguish
#define MOT   6  //  Fan to distinguish the fire
#define PLANB 7  //  Plan for the fastest way to the fire, left way seeker or right way seeker
#define PLAN  8   
#define PING1 9
#define PING2 10
#define PING3 11
#define PING4 12
#define MIC   A0  //  Sound activator
#define PING6 A1
#define PING7 A2
#define PING8 A3
#define FRA2  A5    //  Fire sense Buttom
#define FRA1  A4    //  Fire sense Top
#define PROXY0 A6   //  Proxymity
#define SHARP A7    //  Sharp sense

//  Servo ID [ LOOK AT PICTURE X.X]
#define SA1   12
#define SA2   10
#define SB1   17
#define SB2   9
#define SC1   18
#define SC2   8
#define SD1   13
#define SD2   11
#define SE1   3
#define SE2   15
#define SF1   14
#define SF2   1
#define SHEAD 100

//  the other macro
#define FIRE 1
#define HOME 0
#define TKIRI 0
#define TKANAN 1
#define SERVO 12        //  total servo
#define STEP 4          //  step to walk
#define RANGE_SUDUT 30  //  degree range to move servo into walk
#define VAR_S 5

int rmap(int number);
void indicator(int count, int delaytime);

int 
timer = 70,         // Spesific delay time needed by every servo to make fully steps
sspeed = 300,       // Velocity of dynamixel to move
save_step = 0,      // last step temp variable
proxyState = 0,            
countLine = 1,      //  Line counter to know inside or outside the room
proxyControl = 0,   //  variable counter to the next line Counter
fireC1,
fireC2,           
temp,               //  for temporary value saving
proxyC, 

//  PID additional
v_dyn, 
ts,  
error, 
l_error = 0,  
v_kanan, 
v_kiri ;

unsigned long int 
lastTime;

boolean 
kiri = false, 
plan = TKIRI, 
dest = FIRE,      //  first destination is find fire 
Home = true,
enableWater = false;

//  PID main control 
float 
set_point, 
Pv, 
Pv1, 
Pv2, 
Kp, 
Kd, 
Ki, 
Vp, 
Vi, 
Vd, 
PID;

//  inisialisation PING into an array to make easy of access
const unsigned char PINGS[8] = {
  PING1, PING2, PING3, PING4, PING5, PING6, PING7, PING8
};

//  inisialisation of ID servo
const unsigned char ID[SERVO] = {
  SA1, SA2, SE1, SE2, SC1, SC2, SF1, SF2, SB1, SB2, SD1, SD2
};

//  inisialisation servo degree step into an array to make easy of access
//  0 value mean do not execute, look at jalan funtion
//  degree maped directly into dynamixel degree, it's on 0-1023 mean 0-300 degree
int POS[SERVO][STEP] = {
  
  {rmap(190), 0, rmap(160), 0},  //  SA1
  {rmap(110), rmap(150), 0, 0},  //  SA2

  {rmap(135), 0, rmap(165), 0},  //  SE1
  {rmap(190), rmap(150), 0, 0},  //  SE2

  {rmap(140), 0, rmap(110), 0},  //  SC1
  {rmap(110), rmap(150), 0, 0},  //  SC2

  {rmap(140), 0, rmap(110), 0},  //  SF1
  {0, 0, rmap(190), rmap(150)},   //  SF2

  {rmap(135), 0, rmap(165), 0},  //  SB1
  {0, 0, rmap(110), rmap(150)},  //  SB2

  {rmap(190), 0, rmap(160), 0},  //  SD1
  {0, 0, rmap(190), rmap(150)}  //  SD2

};

void setup () {
  //  wait until boot clearly and finished
  delay(100);
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);

  //  define PIN mode
  pinMode(START, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  pinMode(PLANB, INPUT_PULLUP);
  pinMode(PLAN, INPUT_PULLUP);
  pinMode(MOT, OUTPUT);
  pinMode(FRA1, INPUT);
  pinMode(FRA2, INPUT);

  //  Start dynamixel communication
  Dynamixel.begin(1000000, SIG);

  stand();
  setHead();
  proxyC = 500;   //  proxymity sensor controler
  fireC1 = 976;   //  fire sense top value
  fireC2 = 987;   //  fire sense buttom value

  //  this code to get out from non-arbitary start
  //  make proxymiti sensor get out from non-arbitary start
  while (1) {
    int kiri = Ping_sense(PING3, 2);
    int kanan = Ping_sense(PING7, 2);
    if (digitalRead(START) == LOW || analogRead (MIC) >= 590) {
      delay (2000);
      while ( Ping_sense(PING2,2) > 20 )
      putar_KananComp(1,30);

      if (kiri < kanan){
        while (Ping_sense(PING2, 2 ) != 5555)
          putar_KananComp(1, 15);
          
        if (Ping_sense(PING4, 2) != 5555)
          putar_KiriComp(1, 10);
      }
      else{
        while (Ping_sense(PING8, 2 ) != 5555)
          putar_KiriComp(1, 15);
          
        if (Ping_sense(PING6, 2) != 5555)
           putar_KananComp(1, 10);
      }
        
      stand();

      if (Ping_sense(PING1,2) > 30 && Ping_sense(PING7,2) >30)
        putar_KananComp(3,30);
      else if (Ping_sense(PING1,2) < 30 && Ping_sense(PING7,2) < 30)
        putar_KiriComp(3,30);
      else if (Ping_sense(PING1,2) < 30 && Ping_sense(PING7,2) > 30)
        putar_KananComp(6,30);
  
      temp = 4;
      while (temp--)
        jalan(30,30);
      
      break;
    }

    
    if (digitalRead(PLANB) == LOW)
      kiri = true;
    else
      kiri = false;

    //  check the plan
    //  we use only right way seeker for the safest trip (avoiding the doll and home start) [LOOK AT FIELD PICT]
    if ((millis() - lastTime) > 1000)
    {
      if (kiri)
      {
        plan = TKIRI;
        //  check plan with head position
        Dynamixel.move(SHEAD, rmap(200));
      }
      else
      {
        plan = TKANAN;
        //  check plan with head position
        Dynamixel.move(SHEAD, rmap(100));
      }
      lastTime = millis();
    }
  }
}
void loop() {
    setHead();
  while (countLine != 2)
  {
    if (kiri == true)
      telusur_Kiri();
    else
      telusur_Kanan();
  }
  countLine = 0;
  fireFinder();
}

/*
  //  -----------------------------------
  //  FUNCTION MOVEMENT
  //  --------------------------

*/
//  This funtion used to close the wall for arbitary start, not used on non-arbitary start
void Wall_seeker() {
  int
  s_closer,         
  s_present,        
  i,                
  var_putar = 0,    
  verify = 0;              

  unsigned char 
  dir;  //  direction, left/right

  temp = s_closer = Ping_sense(PING1, 1000);

recheck:  //  start verifikasi

  //  scanning wall position. [ colose or far]
  //  45 is value for position every PING))) sensor at 45 degree. 45, 90, 135, and so on
  for (i = 1; i < 8; i++) {
    if ( (s_present = Ping_sense(PINGS[i], 1000)) > s_closer) {
      s_closer = s_present;
      var_putar = i * 45;
    }
  }

  // verification to make sure the value
  if (temp == s_closer)
    verify++;
  else {
    temp = s_closer;
    delay(100);
    verify = 0;
  }

  if (verify < 3) {
    delay(100);
    goto recheck;
  }

  if (var_putar > 180) {
    var_putar = abs(var_putar - 2 * 180);
    dir = 1;
  }
  else
    dir = 0;

  while (var_putar > 0) {
    if (var_putar >= 30) {
      if (dir)
        putar_KananComp(1, 30);
      else
        putar_KiriComp(1, 30);
    }

    else if (dir)
      putar_KananComp(1, var_putar);
    else
      putar_KiriComp(1, var_putar);

    var_putar -= 30;
  }

  //  this to make sure the robot not face to the front
  putar_KananComp (2, 30);

  stand();
  delay(50);

  //  close to the wall
  while (Ping_sense(PING1, 2) > 12 && Ping_sense(PING8, 2) > 12)
    jalan(30, 30);

  //  Reset the proxymity control
  proxyControl = 6;
  countLine = 0;

  if (Ping_sense(PING1, 2) < 13)
    putar_KiriComp(3, 30);
  else if (Ping_sense(PING8, 2) < 13)
    putar_KiriComp(1, 20);

  telusur_Wall();

  //  make sure robot outside the room
  i = 3;
  while (i--)
    jalan(26, 30);
}

//  funcion to find the fire
void fireFinder() {
  int
  x,              
  sapukanan = 0,    //  value of right scanning
  sapukiri = 0,     //  value of left scanning
  varJalan = 7,     //  walk as many as
  movement;         

  unsigned int
  sMax = 220,       //  max left scanning
  sMin = 80,        //  min right scanning
  sRange = 2,       //  steo scanning
  dTime = 20,       //  step delay
  dSpeed = 900;     //  scanner speed

  boolean
  fireStat = false, //  scanning result
  SGUNstat = true,  
  enter = false;   

  //  make sure robot inside the room
  while ( varJalan--  && Ping_sense(PING1, 5) > 14)
    jalan(30, 30);

  stand();


  if (dest == FIRE) {

reScan:

    //  turn robot to look widely on left side
    if (!fireStat) {
      putar_KiriComp(1, 30);
      stand();
    }

    Dynamixel.moveSpeed(100, rmap(sMax), 500);
    delay(500);

    //  scanning
    for (int x = sMax; x >= sMin; x -= sRange) {
      Dynamixel.moveSpeed(100, rmap(x), dSpeed);

      //  fire found
      if (FR_sense(FRA1) <= fireC1 || FR_sense(FRA2) <= fireC2) {

        if (!fireStat) {
          fireStat = true;
          goto reScan;
        }

        //  save leg position
        sapukanan = x - 10;
        break;
      }

      delay(dTime);
    }

    //  look to right side
    if (!fireStat) {
      putar_KananComp(2, 30);
      stand();
    }

    Dynamixel.moveSpeed(100, rmap(sMin), 500);
    delay(500);

    //  left scanning
    for (int x = sMin; x <= sMax; x += sRange) {
      Dynamixel.moveSpeed(100, rmap(x), dSpeed);

      if (FR_sense(FRA1) <= fireC1 || FR_sense(FRA2) <= fireC2) {

        //  jika menemukan api maka scan lagi tanpa merubah haluan
        if (!fireStat) {
          fireStat = true;
          goto reScan;
        }

        sapukiri = x + 10;
        break;
      }

      delay(dTime);
    }

    delay(500);

    //  fire funded
    if (sapukanan != 0 && sapukiri != 0) {
      Dynamixel.moveSpeed(100, rmap(150), 500);

      x = (sapukanan + sapukiri) / 2;

      if (x < 150) {
        delay(500);
        temp = abs(150 - x);

        while (temp >= 30) {
          putar_KananComp(1, 30);
          temp -= 30;
        }

        if (temp > 0)
          putar_KananComp(1, temp);
      }

      if (x > 150) {
        delay(500);
        temp = abs(150 - x);

        while (temp >= 30) {
          putar_KiriComp(1, 30);
          temp -= 30;
        }

        if (temp > 0)
          putar_KiriComp(1, temp);
      }

      stand();

      //  define how many step(walk) needed according to the distance of the object (1x step = 5cm)
      //  15 to make sure robot not crash the object
      varJalan = ( Ping_sense(PING1, 1000) - 15 ) / 5;

      if (varJalan >= 2)
        enter = true;

      movement = 0;

      while ( Ping_sense(PING1, 2) > 15 && varJalan--) {
        jalan(30, 30);
        jalan(30, 30);
        movement++;
      }

      //  if robot move, try to rescan again to make sure robot enaugh close to the object
      if (movement != 0)
        goto reScan;

reSweep:
      stand();

      sapukanan = sapukiri = 0;
      Dynamixel.moveSpeed(100, rmap(sMax), 500);
      delay(500);

      for (int x = sMax; x >= sMin; x -= sRange) {
        Dynamixel.moveSpeed(100, rmap(x), dSpeed);

        if (FR_sense(FRA2) < fireC2) {
          sapukanan = x + 15;
          break;
        }
        delay(dTime);
      }

      Dynamixel.moveSpeed(100, rmap(sMin), 500);
      delay(500);

      for (int x = sMin; x <= sMax; x += sRange) {
        Dynamixel.moveSpeed(100, rmap(x), dSpeed);
        if (FR_sense(FRA2) < fireC2) {
          sapukiri = x - 15;
          break;
        }
        delay(dTime);
      }

      x = (sapukanan + sapukiri) / 2;

      if (abs(sapukanan - sapukiri) < 100 && sapukanan != 0 && sapukiri != 0) {
        dest = HOME;

        if (SGUNstat == true) {
          indicator(5, 500);
          kill(x + 10, 10);
          SGUNstat = false;
          delay (3000);

          sapukanan = sapukiri = 0;

          goto reSweep;
        }
        else {
          indicator(5, 500);
          x = (sapukanan + sapukiri) / 2;
          kill(x - 10, 10);
          setHead();
        }
      }

      int
      closer,
      putaran;

      if (plan == TKIRI) {
        closer = Ping_sense(PING8, 1000);
        putaran = 45;

        if ( closer > (temp = Ping_sense(PING7, 1000) )) {
          closer = temp;
          putaran = 90;
        }

        if ( closer > (temp = Ping_sense(PING6, 1000) )) {
          closer = temp;
          putaran = 135;
        }

        while ( putaran >= 30) {
          putar_KananComp(1, 30);
          putaran -= 30;
        }
        if (putaran > 0)
          putar_KananComp(1, putaran);

        countLine = 0;
        proxyControl = 6;

        if ( enter == false ) {
          putar_KananComp(3, 30);
          varJalan = 4;

          while (varJalan-- && Ping_sense(PING1, 2 > 12)) {
            jalan(30, 30);
          }

          countLine = 1;
          proxyControl = 0;
          enter = false;

          return;
        }

        while (Ping_sense(PING1, 2) > 12) {
          if (countLine == 1)
            return;

          jalan(30, 30);
        }
        putar_KananComp(3, 30);
        return;
      }

      else if (plan == TKANAN) {
        closer = Ping_sense(PING2, 1000);
        putaran = 45;

        if ( closer > (temp = Ping_sense(PING3, 1000) )) {
          closer = temp;
          putaran = 90;
        }

        if ( closer > (temp = Ping_sense(PING4, 1000) )) {
          closer = temp;
          putaran = 135;
        }

        while ( putaran >= 30) {
          putar_KiriComp(1, 30);
          putaran -= 30;
        }
        if (putaran > 0)
          putar_KiriComp(1, putaran);

        countLine = 0;
        proxyControl = 6;

        if ( enter == false ) {
          putar_KiriComp(3, 30);
          varJalan = 4;
          while (varJalan-- && Ping_sense(PING1, 2 > 12)) {
            jalan(30, 30);
          }
          countLine = 1;
          proxyControl = 0;
          enter = false;
          return;
        }

        while (Ping_sense(PING1, 2) > 12) {
          if (countLine == 1)
            return;

          jalan(30, 30);
        }
        putar_KiriComp(3, 30);

        return;
      }
      //goto balik_lek;
      //break;
    }

    setHead();
balik_lek:
    stand();
    delay(500);

    putar_KananComp(4 , 30);
    varJalan = 5;
    while (varJalan--)
      jalan(30, 28);
    countLine = 1;
    proxyControl = 0;
  }

  else if (dest == HOME) {
    putar_KananComp(6, 30);
    varJalan = 3;
    while (varJalan--)
      jalan(30, 30);
    countLine = 1;
    proxyControl = 0;
  }
  stand();
} // end of function


//  left way seeker
//  this funtion will run unlimated as many as counline != 2, where it's global variable
void telusur_Kiri() {
  int 
  front,
  xix = 8;

  //  this value set manually
  //  controlled by PID (google it "self driving PID control")
  set_point = 9;
  Kp = 1.5;
  Kd = 1.5;
  Ki = 1;
  ts = 1;
  v_dyn = 30;

  while (countLine != 2)
  {
    Pv = Ping_sense(PING3, 5);
    Pv1 = Ping_sense(PING2, 2);
    Pv2 = Ping_sense(PING4, 2);
    front = Ping_sense(PING1, 1000);

    Pv = RPD_sum(Pv, Pv1, Pv2);

    error = set_point - Pv;

    Vp = Kp * error;
    Vd = Kd * 10 / ts * (error - l_error);
    Vi = Ki / 10 * (error + l_error) * ts;

    l_error = error;
    PID = Vp + Vi + Vd;

    v_kanan = v_dyn - PID;
    v_kiri = v_dyn + PID;


    if (v_kanan > 30)
      v_kanan = 30;
    else if (v_kanan < 6)
      v_kanan = 4;
    if (v_kiri > 30)
      v_kiri = 30;
    else if (v_kiri < 6)
      v_kiri = 4;

    //  doll detector condition [bug known]
    if (front == 5555 && analogRead(SHARP) > 200) {
      putar_KananComp(3, 30);
      putar_KananComp(1, 20);
      xix = 6;
      while (xix-- && Ping_sense(PING1, 2) > 12)
        jalan(30, 30);
    }
    else if (v_kiri == 4 && Ping_sense(PING2, 2) < 11) {
      while (Ping_sense (PING1, 2) > 10 && Ping_sense(PING2, 2) > 10 && countLine != 2)
        jalan(6, 30);
    }
    else if ( front > 12 || ( Pv > 30 && front > 10)) {
      jalan(v_kiri, v_kanan);
    }
    else {
      putar_KananComp(1, 30);
    }

  }
}

//  right way seeker funtion
void telusur_Kanan()
{
  int 
  front,
  xix;

  set_point = 8;
  Kp = 1.5;
  Kd = 1.5;
  Ki = 1;
  ts = 1;
  v_dyn = 30;

  while (countLine != 2) {
    Pv = Ping_sense(PING7, 2);
    Pv1 = Ping_sense(PING8, 2);
    Pv2 = Ping_sense(PING6, 2);
    front = Ping_sense(PING1, 1000);

    Pv = RPD_sum(Pv, Pv1, Pv2);

    error = set_point - Pv;

    Vp = Kp * error;
    Vd = Kd * 10 / ts * (error - l_error);
    Vi = Ki / 10 * (error + l_error) * ts;

    l_error = error;
    PID = Vp + Vi + Vd;

    v_kanan = v_dyn + PID;
    v_kiri = v_dyn - PID;

    if (v_kanan > 30)
      v_kanan = 30;
    else if (v_kanan < 6)
      v_kanan = 4;
    if (v_kiri > 30)
      v_kiri = 30;
    else if (v_kiri < 6)
      v_kiri = 4;

did_it:
    if (front == 5555 && analogRead(SHARP) > 200) {
      putar_KiriComp(3, 30);
      putar_KiriComp(1, 20);
      xix = 6;
      while (xix-- && Ping_sense(PING1, 2) > 12)
        jalan(30, 30);
    }
    else if (v_kanan == 4 && Ping_sense(PING7, 2) < 11) {
      while (Ping_sense (PING1, 2) > 10 && Ping_sense(PING7, 2) > 10 && countLine != 2)
        jalan(6, 30);
    }
    else if ( front > 12 || ( Pv > 30 && front > 10)) {
      jalan(v_kiri, v_kanan);
    }
    else {
      putar_KiriComp(1, 30);
    }
  }
}

//  function to seek inside the room when on arbitary start
//  this funtion not used on non-arbitary start
void telusur_Wall() {
  int 
  front,
  xix = 8;

  set_point = 12;
  Kp = 2;
  Kd = 3;
  Ki = 1;
  ts = 1;
  v_dyn = 30;

  while (proxyState != 1) {
    Pv = Ping_sense(PING7, 2);
    Pv1 = Ping_sense(PING8, 2);
    Pv2 = Ping_sense(PING6, 2);
    front = Ping_sense(PING1, 1000);

    Pv = RPD_sum(Pv, Pv1, Pv2);

    error = set_point - Pv;

    Vp = Kp * error;
    Vd = Kd * 10 / ts * (error - l_error);
    Vi = Ki / 10 * (error + l_error) * ts;

    l_error = error;
    PID = Vp + Vi + Vd;

    v_kanan = v_dyn + PID;
    v_kiri = v_dyn - PID;

    if (v_kanan > 30)
      v_kanan = 30;
    else if (v_kanan < 10)
      v_kanan = 10;
    if (v_kiri > 30)
      v_kiri = 30;
    else if (v_kiri < 10)
      v_kiri = 10;


    if (Ping_sense(PING1, 2) > 14) {
      jalan(v_kiri, v_kanan);
    }
    else {
      putar_KiriComp(1, 30);
    }

  }
}

//  this walk funtion used to move robot to front using left speed (v_kiri) and right speed (v_kanan)
//  where the maximum speed is 30, otherwise servo will crash each other

void jalan (int v_kiri0, int v_kanan0)
{
  int id, steps, dgree, v_kiri, v_kanan, i;

  //  inverting speed
  v_kiri = rmap(RANGE_SUDUT) - rmap(v_kiri0);
  v_kanan = rmap(RANGE_SUDUT) - rmap(v_kanan0);

  if (save_step >= 4)
    save_step = 0;

  steps = save_step;

  //  steps scanner
  for (steps, i = 0; i < 2; steps++, i++) {
    for (id = 0; id < SERVO; id++) {
      dgree = POS[id][steps];
      if ( id % 2 == 0 && dgree != 0 ) {
        if ( (ID[id] == SC1 || ID[id] == SF1 ) && steps == 2)
          dgree = (ID[id] == SC1) ? POS[id][steps] + v_kiri : POS[id][steps] + v_kanan;
        else if ( ID[id] == SB1 || ID[id] == SE1 ) {
          if (steps == 0)
            dgree = (ID[id] == SB1) ? POS[id][steps] + v_kiri / 2 : POS[id][steps] + v_kanan / 2;
          else if (steps == 2)
            dgree = (ID[id] == SB1) ? POS[id][steps] - v_kiri / 2 : POS[id][steps] - v_kanan / 2;
        }
        else if ( (ID[id] == SA1 || ID[id] == SD1) && steps == 0 )
          dgree = (ID[id] == SA1) ? POS[id][steps] - v_kiri : POS[id][steps] - v_kanan;

        //  update proxystate every one servo move
        updateState();
      } 

      //  ececute only if step on array not zero
      if (dgree != 0) 
        Dynamixel.moveSpeed(ID[id], dgree, sspeed);
      
    }
    delay(timer);
  }
  save_step = steps;

  if (proxyControl < 6)
    proxyControl++;

  //  control to make sure just scaning the line at onece
  if (proxyState == 1 && proxyControl == 6) {
    countLine++;
    proxyControl = 0;
  }

} 

//  this funtion is inverted of funtion jalan
void mundur (int v_kiri0, int v_kanan0)
{
  int id, steps, dgree, v_kiri, v_kanan;
  v_kiri = rmap(RANGE_SUDUT) - rmap(v_kiri0);
  v_kanan = rmap(RANGE_SUDUT) - rmap(v_kanan0);

  for (steps = save_step; steps < STEP; steps++) {
    for (id = 0; id < SERVO; id++) {
      dgree = POS[id][steps];
      if ( id % 2 == 0 && dgree != 0 ) {
        if ( (ID[id] == SC1 || ID[id] == SF1 ) && steps == 2)
          dgree = (ID[id] == SC1) ? POS[id][steps] + v_kiri : POS[id][steps] + v_kanan;
        else if ( ID[id] == SB1 || ID[id] == SE1 ) {
          if (steps == 0)
            dgree = (ID[id] == SB1) ? POS[id][steps] + v_kiri / 2 : POS[id][steps] + v_kanan / 2;
          else if (steps == 2)
            dgree = (ID[id] == SB1) ? POS[id][steps] - v_kiri / 2 : POS[id][steps] - v_kanan / 2;
        }
        else if ( (ID[id] == SA1 || ID[id] == SD1) && steps == 0 )
          dgree = (ID[id] == SA1) ? POS[id][steps] - v_kiri : POS[id][steps] - v_kanan;
      }    

      if (id % 2 != 0) {
        if (POS[id][steps] != 0)
          dgree = 0;
        else {
          if (steps == 0 || steps == 1)
            dgree = steps == 0 ? POS[id][2] : POS[id][3];
          else
            dgree = steps == 2 ? POS[id][0] : POS[id][1];
        }
      }

      if (dgree != 0) 
        Dynamixel.moveSpeed(ID[id], dgree, sspeed);
 
    }   
    delay(timer);
    save_step = 0;
    if ( Ping_sense(PING1, 2) < 15) {
      save_step = steps;
      return;
    }
  }  

  save_step = 0;
}  


/*
  This function is used to turn right or left at a certain angular displacement
  the parameters used are a lot of steps ( x ) and a large displacement angle ( y ) which is one of the steps
  time steps executed with a large displacement in accordance with the parameter y .
  direction:
  --------------------
  putar_KananComp ( int steps , angular )
  --------------------
  minimum step is 2 and the maximum displacement is 30 min 0 (no transfer ) . angle servo movement has been restricted
  so that the displacement of more than 30 will not make servo crash but will not spoil the movement of the robot
*/

void putar_KananComp(int x, int y)
{
  int id, steps, dgree, Move = rmap(30 - y);
  if (save_step >= 4)
    save_step = 0;

  while (x) {
    for (steps = save_step; steps < STEP; steps++) {
      for (id = 0; id < SERVO; id++) {
        dgree = POS[id][steps];
        if ( POS[id][steps] != 0 && (ID[id] == SF1 || ID[id] == SE1 || ID[id] == SD1)) {
          if (POS[id][steps] == rmap(140) || POS[id][steps] == rmap(190))
            dgree = POS[id][2];
          else if (POS[id][steps] == rmap(110) || POS[id][steps] == rmap(160))
            dgree = POS[id][0] - Move;
          else
            dgree = POS[id][steps] == rmap(135) ? POS[id][2] - Move / 2 : POS[id][0] + Move / 2;
        }
        else if ( POS[id][steps] != 0 && (ID[id] == SA1 || ID[id] == SB1 || ID[id] == SC1)) {
          if (POS[id][steps] == rmap(140) || POS[id][steps] == rmap(190))
            dgree = POS[id][0] - Move;
          else if (POS[id][steps] == rmap(110) || POS[id][steps] == rmap(160))
            dgree = POS[id][2];
          else
            dgree = POS[id][steps] == rmap(135) ? POS[id][0] + Move / 2 : POS[id][2] - Move / 2;

        }
        if (dgree != 0)
          Dynamixel.moveSpeed(ID[id], dgree, sspeed);
      }
      delay(timer);
      save_step = 0;
    }
    x--;
  }
  save_step = 0;
}


void putar_KiriComp(int x, int y)
{
  int id, steps, dgree, Move = rmap(30 - y);
  if (save_step >= 4)
    save_step = 0;

  while (x) {
    for (steps = save_step; steps < STEP; steps++) {
      for (id = 0; id < SERVO; id++) {
        dgree = POS[id][steps];
        if ( POS[id][steps] != 0 && (ID[id] == SF1 || ID[id] == SE1 || ID[id] == SD1)) {
          if (POS[id][steps] == rmap(140) || POS[id][steps] == rmap(190))
            dgree = POS[id][0] - Move;
          else if (POS[id][steps] == rmap(110) || POS[id][steps] == rmap(160))
            dgree = POS[id][2];
          else
            dgree = POS[id][steps] == rmap(135) ? POS[id][0] + Move / 2 : POS[id][2] - Move / 2;
        }
        else if ( POS[id][steps] != 0 && (ID[id] == SA1 || ID[id] == SB1 || ID[id] == SC1)) {
          if (POS[id][steps] == rmap(140) || POS[id][steps] == rmap(190))
            dgree = POS[id][2];
          else if (POS[id][steps] == rmap(110) || POS[id][steps] == rmap(160))
            dgree = POS[id][0] - Move;
          else
            dgree = POS[id][steps] == rmap(135) ? POS[id][2] - Move / 2 : POS[id][0] + Move / 2;

        }
        if (dgree != 0)
          Dynamixel.moveSpeed(ID[id], dgree, sspeed);
      }
      delay(timer);
      save_step = 0;
    }
    x--;
  }
  save_step = 0;
}


void setHead()
{
  Dynamixel.moveSpeed(SHEAD, rmap(150), 300);
  delay(1000);
}

void stand()
{
  unsigned char delay_ms = 44;
  Dynamixel.moveSpeed(SF2, rmap(150), 1023);
  Dynamixel.moveSpeed(SB2, rmap(150), 1023);
  Dynamixel.moveSpeed(SD2, rmap(150), 1023);
  delay(delay_ms);
  Dynamixel.moveSpeed(SA2, rmap(120), 1023);
  Dynamixel.moveSpeed(SE2, rmap(180), 1023);
  Dynamixel.moveSpeed(SC2, rmap(120), 1023);
  delay(delay_ms);
  Dynamixel.moveSpeed(SA1, rmap(190), 1023);
  Dynamixel.moveSpeed(SE1, rmap(150), 1023);
  Dynamixel.moveSpeed(SC1, rmap(110), 1023);
  delay(delay_ms);
  Dynamixel.moveSpeed(SA2, rmap(150), 1023);
  Dynamixel.moveSpeed(SE2, rmap(150), 1023);
  Dynamixel.moveSpeed(SC2, rmap(150), 1023);
  delay(delay_ms);

  Dynamixel.moveSpeed(SF2, rmap(180), 1023);
  Dynamixel.moveSpeed(SB2, rmap(120), 1023);
  Dynamixel.moveSpeed(SD2, rmap(180), 1023);
  delay(delay_ms);
  Dynamixel.moveSpeed(SF1, rmap(110), 1023);
  Dynamixel.moveSpeed(SB1, rmap(150), 1023);
  Dynamixel.moveSpeed(SD1, rmap(190), 1023);
  delay(delay_ms);
  Dynamixel.moveSpeed(SF2, rmap(150), 1023);
  Dynamixel.moveSpeed(SB2, rmap(150), 1023);
  Dynamixel.moveSpeed(SD2, rmap(150), 1023);
  delay(delay_ms + 50);
  save_step = 0;
}
/*
  //  ---------------------------------------------------
  //  FUNCTION CONTROL
  //  ---------------------

  Ping sensor function declared. each sensor devided to their position become Front, Left and other directions
  Each function give a return value according to the time of wave return
*/

int Ping_sense(char PingPIN, int delayTime)
{
  delayTime = delayTime * 1000;
  int duration = 0;
  unsigned int delay_ms;
  delay_ms = 10;
  delay(2);
  pinMode(PingPIN, OUTPUT); //set PING to transmit wave
  digitalWrite(PingPIN, LOW); //ensure PING no produce a pulse
  delayMicroseconds(2);  //Ensure in not pruducing pulse
  digitalWrite(PingPIN, HIGH); //Produce a pulse
  delayMicroseconds(5);
  digitalWrite(PingPIN, LOW);

  pinMode(PingPIN, INPUT); //standby to receive a pulse
  duration = (int) pulseIn(PingPIN, HIGH, delayTime);
  if (duration != 0) {
    return duration / 38 / 2;
  }
  return 5555;
}


// Function to calculate the real ping distance
//  our robot ping position on wrong position, so we use this funtion to control robot more stable
int RPD_sum(int Pv, int Pv1, int Pv2)
{
  int x0, x1, x2, Pvx;

  if (Pv1 < Pv + 8) {
    x1 = abs(Pv1 - Pv);
    x2 = 4 - x1;
    x0 = x1 > x2 ? x1 : x2;

    Pvx = Pv1;
  }
  else if (Pv2 < Pv + 8) {
    x1 = abs(Pv2 - Pv);
    x2 = 4 - x1;
    x0 = x1 > x2 ? x1 : x2;

    Pvx = Pv2;
  }
  else
    Pvx = 5555;

  if (Pv != 5555) {
    if (Pvx > Pv && Pvx != 5555)
      return (Pvx - x0);
    else if (Pv > Pvx) {
      if (Pv > Pv1)
        return (Pv - x0 - 4);
      else if (Pv > Pv2)
        return (Pv - x0 + 4);
    }
    else if (Pv == Pvx)
      return (Pv - 3);
    else if (Pvx > Pv + 4)
      return Pv;
    else
      return (Pvx - x0);
  }
  return Pvx;
}

int FR_sense(int PORT)
{
  return analogRead(PORT);
}


void indicator(int count, int delaytime)
{
  while (count--)
  {
    digitalWrite(LED, HIGH);
    delay(delaytime);
    digitalWrite(LED, LOW);
    delay(delaytime);
  }
}


//  ---------------------------------------------------
//  MATH FUNCTIONS
//----------------------------------------------------

int rmap(int number)
{
  return (map(number, 0, 300, 0, 1023));
}
//  ----------------------------------------------------
//  FUNCTION PROTOTYPE
//  ---------------------
void ping_test()
{
  Dynamixel.end();
  Serial.begin(9600);
  while (1) {
    for (int i = 0; i < 8; i++) {
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(Ping_sense(PINGS[i], 1000));
      Serial.print("-");
    }
    Serial.println();
  }
}

void debugtab() {
  Dynamixel.end();
  Serial.begin(9600);
  delay(10);
  Serial.print("\t");
  delay(10);
  Serial.end();
  Dynamixel.begin(1000000, SIG);
}
void debugln(long input)
{
  Dynamixel.end();
  Serial.begin(9600);
  delay(10);
  Serial.println(input);
  delay(10);
  Serial.end();
  Dynamixel.begin(1000000, SIG);
}

void debug(long input)
{
  Dynamixel.end();
  Serial.begin(9600);
  delay(10);
  Serial.print(input);
  delay(10);
  Serial.end();
  Dynamixel.begin(1000000, SIG);

}

void updateState()
{
  if (analogRead(PROXY0) < proxyC)
    proxyState = 1;
  else
    proxyState = 0;
}

void dynamixelon()
{
  Serial.end();
  Dynamixel.begin(1000000, SIG);
}

void serialon()
{
  Dynamixel.end();
  Serial.begin(9600);
}

void kill(int servoPos, int radius)
{
  int timeFan = 5000, limitCW = servoPos - abs(radius), limitCCW = servoPos + abs(radius);
  boolean rotation = true;
  lastTime = millis();

  if (limitCCW < 80 )
  {
    limitCCW = 80;
  }
  else if (limitCCW > 220)
  {
    limitCCW = 220;
  }
  if (limitCW < 80) {
    limitCW = 80;
  } else if (limitCW > 220) {
    limitCW = 220;
  }
  if (enableWater)
  {

    //digitalWrite(SGUN,  HIGH);
    Dynamixel.moveSpeed(SHEAD, rmap(servoPos), 900);
    Dynamixel.moveSpeed(SHEAD, rmap(servoPos), 900);
    while ((millis() - lastTime) < 5000)
    {
    }
    //digitalWrite(SGUN, LOW);
    enableWater = false;
    Dynamixel.moveSpeed(SHEAD, rmap(150), 900);
  }
  else
  {
    digitalWrite(MOT, HIGH);
    while ((millis() - lastTime) < 5000)
    {
      for (int x = limitCW; x <= limitCCW; x++)
      {
        Dynamixel.moveSpeed(SHEAD, rmap(x), 900);
      }
      for (int x = limitCCW; x >= limitCW; x--)
      {
        Dynamixel.moveSpeed(SHEAD, rmap(x), 900);
      }
    }
    digitalWrite(MOT, LOW);
    Dynamixel.moveSpeed(SHEAD, rmap(150), 900);
  }
}


void pause()
{
  while (1)
  {

  }
}

void maindebug() {
  // put your main code here, to run repeatedly:
  Serial.print("FRA1\t");
  Serial.print("FRA2\t");
  Serial.print("PROXY0\t");
  Serial.print("SHARP\t");
  Serial.print("PING\t");
  Serial.println("MIC");

  Serial.print(analogRead(FRA1));
  Serial.print("\t");
  Serial.print(analogRead(FRA2));
  Serial.print("\t");
  Serial.print(analogRead(PROXY0));
  Serial.print("\t");
  Serial.print(analogRead(SHARP));
  Serial.print("\t");
  Serial.print(Ping_sense(PING1, 1000));
  Serial.print("\t");
  Serial.println(analogRead(MIC));
}



