void cekgaris() {
   nilaisensorgaris = digitalRead(linesensorpin);
  // Serial.print("nilai pin : ");
  // Serial.println(nilaisensorgaris);

}

void updatestate() {

  cekgaris();
if (ceksensorgaris) {
  if (countline == 0) {
    if (nilaisensorgaris == 1) {
      if (ruangan) {
        //jalan();
        countline =  1;
        delay(3000);
        ruangan = false;
        rumah = false;
        cekarah();
        if (orientasi) {
          orientasi_x_awal = x_sementara;
          orientasi_y_awal = y_sementara;
          orientasi = false;
          }
      }
      else if (ruangan == false) {
        countline =  1;
        delay(6000);
        ruangan = true;
       // cari_api();
        
        }
    }
  }

  else if (countline == 1) {
    if (nilaisensorgaris == 1) {
      ceksensorgaris = false;
      
      maju3();
      if (distancedepan < 6) {
      maju3();
      bacasensor();
      }
     if (distancedepan < 6) {
      maju3();
      bacasensor();
      }
      if (distancedepan < 6) {
      maju3();
      bacasensor();
      }
      ceksensorgaris = true;
      
      }
    else if(nilaisensorgaris == 0) {
      countline = 0 ;
      
    }
  }



}



}
