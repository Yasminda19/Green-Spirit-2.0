void belokkananpresisi() {
  
  cekarah();
  int x_awal = x_sementara ;
  Serial.println(" ");
  Serial.print("x awal  : ");
  Serial.println (x_awal);
  while (abs(abs(x_awal) - abs(x_sementara)) < 15 ) {
    belokkanan15();
    cekarah();
    }
  }
void belokkiripresisi() {
  
  cekarah();
  int x_awal = x_sementara ;
  int y_awal = y_sementara ;
  Serial.println(" ");
  Serial.print("y awal  : ");
  Serial.println (y_awal);
  Serial.println (" ");
  do {
    belokkiri15();
    cekarah();
    } while (abs(abs(y_awal) - abs(y_sementara)) < 15 ) ;
Serial.print("selisih : ");
Serial.println(abs(abs(y_awal) - abs(y_sementara)));
    if (abs(abs(x_awal) - abs(x_sementara)) < 15) {
      belokkiri15();
      Serial.println("tambah 1");
      cekarah();
      }
  }

void putarpresisi() {
  
  cekarah();
  int x_awal = x_sementara ;
  int y_awal = y_sementara ;
  Serial.println(" ");
  Serial.print("x awal  : ");
  Serial.println (x_awal);
  if (x_awal <= 0 && y_awal <= 0 ) {//utara
  while (x_sementara < 0  || y_sementara < 0 || y_sementara < abs(y_awal)) {
    belokkanan15();
    cekarah();
    }
  }

 else if (x_awal <= 0 && y_awal >= 0 ) { //barat
  while (x_sementara < 0  || y_sementara > 0 || x_sementara < abs(x_awal) ) {
    belokkanan15();
    cekarah();
    }
  }

 else if (x_awal >= 0 && y_awal <= 0 ) { //timur
  while (x_sementara >= 0  || y_sementara <= 0 || y_sementara < abs(y_awal)  ) {
    belokkanan15();
    cekarah();
    }
  }

 else if (x_awal > 0 && y_awal > 0 ) { //selatan
  while (x_sementara > 0  || y_sementara > 0 || abs(y_sementara) < (y_awal-12))   {
    belokkanan15();
    cekarah();
    }
  }
  
  }
void cekarah () {
 // myservo.end();

 sensor_t sensor;
  mag.getSensor(&sensor);
  sensors_event_t event;
  mag.getEvent(&event);
x_sementara = event.magnetic.x ;
y_sementara = event.magnetic.y ;
 // Serial.print("X: "); Serial.print(x_sementara); Serial.print("  ");
 // Serial.print("Y: "); Serial.print(event.magnetic.y); Serial.print("  ");
 // Serial.print("Z: "); Serial.print(event.magnetic.z);
//  Serial.print("  ");Serial.println("uT");
   heading = atan2(x_sementara, y_sementara) /0.0174532925; //Calculate the degree using X and Y parameters with this formulae 

 //Convert result into 0 to 360
  if(heading < 0) 
  heading+=360;
  heading = 360-heading;
//  Serial.print("X Raw: "); Serial.print(mag.raw.x); Serial.print("  ");
//  Serial.print("Y Raw: "); Serial.print(mag.raw.y); Serial.print("  ");
//  Serial.print("Z Raw: "); Serial.print(mag.raw.z); Serial.println("");
//  delay(10);
  //myservo.begin ();
  
  }

void setnilaiawal() {
  if (heading <= batas_atas_u && heading >= batas_bawah_u ) {
        arah = UTARA; //1 atau 5
        kondisiawal = false;
      }
      else if (heading <= batas_atas_b && heading >= batas_bawah_b ) {
        arah = BARAT;//4 atau 0
        kondisiawal = false;
      }
      else if (heading <= batas_atas_t && heading >= batas_bawah_t ) {
        arah = TIMUR;//2
        kondisiawal = false;
      }
      else if (heading <= batas_atas_s && heading >= batas_bawah_s ) {
        arah = SELATAN;//3
        kondisiawal = false;
      }
      else {
        belokkanan15();
      }
  
  
  }  
