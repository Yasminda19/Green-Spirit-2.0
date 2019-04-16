/* Mode Navigasi 1 */
/* Robot bergerak kiri kanan depan belakang tanpa berotasi*/
/* Inputs */
/* Direction
 *  1 North
 *  2 East
 *  3 South
 *  4 West
 */
int pulang[1000];
int maze[1000];
void setup() {

}

void loop() {
  mapping(0);
  mst();
  back();
}
//int maze[0]=-9;
int x=0;
int mapping(int a){
  if(isNorthOpen){
    moveNorth();
    x++;
    maze[x]=1;
    if(isFireAround){
      putFire();
      return 1; 
    }
    mapping(x);
    return 0;
  }
  if(isEastOpen){
    moveEast();
    x++;
    maze[x]=1;
    if(isFireAround){
      putFire();
      return 1; 
    }
    mapping(x);
    return 0;
  }
  if(isSouthOpen){
    moveNorth();
    x++;
    maze[x]=1;
    if(isFireAround){
      putFire();
      return 1; 
    }
    mapping(x);
    return 0;
  }
  if(isWestOpen){
    moveWest();
  }
}

void putFire(){
  
}
int isFireAround(){
  
}

void mst(){
  
}

void back(){
  
}

boolean isNorthOpen(){
  
}

boolean isWestOpen(){

}
boolean isSouthOpen(){

}

boolean isEastOpen(){
  
}
void moveNorth(){
  
}
void moveWest(){

}
void moveSouth(){
   
}
void moveEast(){
  
}
