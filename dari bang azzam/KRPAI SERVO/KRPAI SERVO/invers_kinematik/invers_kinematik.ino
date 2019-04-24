const float cx=2.65; //coxa
const float fm=4; //femur
const float tb=5.74; // tibia
float L, L1;
float alpha, alpha1,alpha2,beta,gama;
void setup()
{
 Serial.begin(9600); 
}
void loop()
{
  
trigono_xyz(6.65, -3, 0); //contoh x,y,z
Serial.print("gama= ");
Serial.print((gama/300)*1023);
Serial.print(", alpha= ");
Serial.print((alpha/300)*1023);
Serial.print(", beta= ");
Serial.print((beta/300)*1023);
Serial.println();
}

void trigono_xyz(float x, float y, float z)
{
 L1=sqrt(sq(x)+sq(y));
 gama=(atan2(y,x)/PI*180)+150;                               //sudut coxa
 L=sqrt(sq(L1-cx)+sq(z));
 beta=(acos((sq(tb)+sq(fm)-sq(L))/(2*tb*fm))/PI*180)+106;   //sudut tibia
 alpha1=acos(z/L)/PI*180;
 alpha2=acos((sq(fm)+sq(L)-sq(tb))/(2*fm*L))/PI*180;
 alpha=(alpha1+alpha2)-31.55;                                //sudut femur
 
}
