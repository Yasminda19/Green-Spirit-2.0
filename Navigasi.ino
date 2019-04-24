/* Mode Navigasi 1 */
/* Robot bergerak kiri kanan depan belakang tanpa berotasi*/
/* Inputs */
/* Direction
 *  1 North
 *  2 East
 *  3 South
 *  4 West
 */
short pulang[1000];
short maze[1000];

void setup() {
  maze[0]=-9;
}

void loop() {
  mapping(0);
  mst();
  back();
}
int x=0;
int mapping(int a){
  if(isNorthOpen()){
    moveNorth();
    x++;
    maze[x]=1;
    if(isFireAround()){
      putFire();
      return 1; 
    }
    if(mapping(x)==1) return 1;
    return 0;
  }
  if(isEastOpen()){
    moveEast();
    x++;
    maze[x]=2;
    if(isFireAround()){
      putFire();
      return 1; 
    }
    mapping(x);
    if(mapping(x)==1) return 1;
    return 0;
  }
  if(isSouthOpen()){
    moveSouth();
    x++;
    maze[x]=3;
    if(isFireAround()){
      putFire();
      return 1; 
    }
    mapping(x);
    if(mapping(x)==1) return 1;
    return 0;
  }
  if(isWestOpen()){
    moveWest();
    x++;
    maze[x]=4;
    if(isFireAround()){
      putFire();
      return 1; 
    }
    mapping(x);
    if(mapping(x)==1) return 1;
    return 0;
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
