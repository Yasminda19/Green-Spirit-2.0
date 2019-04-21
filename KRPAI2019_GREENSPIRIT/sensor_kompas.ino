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
  Serial.print("X: "); Serial.print(x_sementara); Serial.print("  ");
  Serial.print("Y: "); Serial.print(event.magnetic.y); Serial.print("  ");
  Serial.print("Z: "); Serial.print(event.magnetic.z);
  Serial.print("  ");Serial.println("uT");
  
  Serial.print("X Raw: "); Serial.print(mag.raw.x); Serial.print("  ");
  Serial.print("Y Raw: "); Serial.print(mag.raw.y); Serial.print("  ");
  Serial.print("Z Raw: "); Serial.print(mag.raw.z); Serial.println("");
  delay(10);
  //myservo.begin ();
  
  }
