/*
UTARA = 1
TIMUR = 2
SELATAN = 3
BARAT = 4
*/
int i;
int nilaisementara = 99;
int maze[] = {2,1,3,4,1,1,2,2,3,4,1,1,1,1,
             
             1,1,1,1,1,1,1,
              1,1,1,1,1,1,1,1,1,1,
              99,99,99,99,99,99,99,99,99,99} ; //contoh perjalanan pergi
int pulang[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
  
  
  } ; // array pulang
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
}

void loop() { 
  i = 0;
  Serial.println("maze[i]  "); 
  while (maze[i] != 99 ) {
  maze[i] = random(1,4) ;
  
  if (maze [i] == maze[i-1]) {
    maze [i] = 0;
    nilaisementara = maze[i-1];
   // i = i-1;
    
    }
  else if (maze[i] != nilaisementara) {
    nilaisementara = 99;
    
    }
  else if  (maze[i] == nilaisementara ) {  
  maze[i] = 0;
  }
  Serial.println(maze[i]);
  //Serial.print(nilaisementara);  
  i = i +1;
  delay(1000);
  }
  Serial.println("-------------------------");
  Serial.println("pulang[i]  ");
  Serial.println(" -----------------------");
  delay(1000);

 i = 0;
for (int y = 49; y >= 0; y--) {
  if (maze[y] != 99 || maze[y] != 0)
  { if (maze[y] == 1) {
    pulang[i] = 3;
    Serial.println(pulang[i]);
    i = i+1;
    }
    else if (maze[y] == 2) {
      pulang[i] = 4 ;
      Serial.println(pulang[i]);
      i = i+1 ;
      }
    else if (maze[y] == 3) {
      pulang[i] = 1 ;
      Serial.println(pulang[i]);
      i = i+1;
      }
     else if (maze[y] == 4) {
      pulang[i] = 2 ;
      Serial.println(pulang[i]);
      i = i+1;
      } 
    
    }
  
  
  
  }
Serial.println("-------------------------------------");
}
