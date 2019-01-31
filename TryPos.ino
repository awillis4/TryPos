#include<servo.h>

Servo serv1;Servo serv2;Servo serv3;Servo serv4;

int val1=42;int val2=90;int val3=50;int val4=111;

int n=0;int p=0;int buttonPin=4;unsigned long lastmil=0;

void setup(){

Serial.begin(9600);

serv1.attach(11);serv2.attach(10);serv3.attach(9);serv4.attach(6);

pinMode(buttonPin,INPUT_PULLUP);pinMode(5,OUTPUT);

serv1.write(val1);serv2.write(val2);serv3.write(val3);serv4.write(val4);}

void manipulator(int val1_new, int val2_new, int val3_new, int val4_new, int speedm){

int val1_route = 0;int val2_route = 0;int val3_route = 0;int val4_route = 0;

if (val1 < val1_new) val1_route = 1;if (val1 > val1_new) val1_route = -1;
if (val2 < val2_new) val2_route = 1;if (val2 > val2_new) val2_route = -1;
if (val3 < val3_new) val3_route = 1;if (val3 > val3_new) val3_route = -1;
if (val4 < val4_new) val4_route = 1;if (val4 > val4_new) val4_route = -1;

while (val1 != val1_new || val2 != val2_new || val3 != val3_new || val4 != val4_new){

val1 = val1 + val1_route;myservo1.write(val1);if (val1 == val1_new) val1_route = 0;
val2 = val2 + val2_route;myservo2.write(val2);if (val2 == val2_new) val2_route = 0;
val3 = val3 + val3_route;myservo3.write(val3);if (val3 == val3_new) val3_route = 0;
val4 = val4 + val4_route;myservo4.write(val4);if (val4 == val4_new) val4_route = 0;
delay(speedm);}}

void loop(){

int val1pos,val2pos,val3pos,val4pos;int serv1pos,serv2pos,serv3pos,serv4pos;
val1pos=analogRead(val1);val2pos=analogRead(val2);val3pos=analogRead(val3);val4pos=analogRead(val4);

serv1pos=map(val1pos,600,900,0,360);serv1pos=constrain(serv1pos,0,360);
serv2pos=map(val2pos,600,900,0,360);serv2pos=constrain(serv2pos,0,360);
serv3pos=map(val3pos,600,900,0,360);serv3pos=constrain(serv3pos,0,360);
serv4pos=map(val4pos,600,900,0,360);serv4pos=constrain(serv4pos,0,360);

val1.write(serv1pos);val2.write(serv2pos);val3.write(serv3pos);val4.write(serv4pos);

  Serial.print("Val1Sign");Serial.print(" | ");
  Serial.print("Val2Sign");Serial.print(" | ");
  Serial.print("Val3Sign");Serial.print(" | ");
  Serial.print("Val4Sign");Serial.print(" | ");
  Serial.println();

  Serial.print("     ");
  Serial.print(val1pos);Serial.print("     | ");Serial.print("     ");
  Serial.print(val2pos);Serial.print("     | ");Serial.print("     ");
  Serial.print(val3pos);Serial.print("     | ");Serial.print("     ");
  Serial.print(val4pos);Serial.println();
  
  Serial.print("serv1pos");Serial.print(" | ");
  Serial.print("serv2pos");Serial.print(" | ");
  Serial.print("serv3pos");Serial.print(" | ");
  Serial.print("serv4pos");Serial.println();
  
  Serial.print("     ");Serial.print(serv1pos);Serial.print("     | ");
  Serial.print("     ");Serial.print(serv2pos);Serial.print("     | ");
  Serial.print("     ");Serial.print(serv3pos);Serial.print("     | ");
  Serial.print("     ");Serial.print(serv4pos);Serial.println();delay(10);
  
  unsigned long currentmil=mil();float r1=10;float r2=0;float vin=5.0;
  
  if(currentmil-lastmil>=1000){
  
  lastmil=currentmil;int raw=analogRead((val1+val2+val3+val4)/4);float vout=(5.0/1023.0)*raw;
  
  r2=r1*(1/((vin/vout)-1));Serial.println(r2);}
  
  if (val1pos=val1pos)val1pos++;for(val1pos=val1pos)if(vout>0)Serial.print(vout);val1pos--;val1pos=val1pos;
  if (val2pos=val2pos)val2pos++;for(val2pos=val2pos)if(vout>0)Serial.print(vout);val2pos--;val2pos=val2pos;
  if (val3pos=val3pos)val3pos++;for(val3pos=val3pos)if(vout>0)Serial.print(vout);val3pos--;val3pos=val3pos;
  if (val4pos=val4pos)val4pos++;for(val4pos=val4pos)if(vout>0)Serial.print(vout);val4pos--;val4pos=val4pos;
  
  Serial.print("Servo1 "+serv1pos+"Servo2 "+serv2pos+"Servo3 "+serv3pos+"Servo4 "+serv4pos)}
  
  //Written by awillis4 citing Snarm motors, linuxgnuru, bobparadiso, abhisheksafui, scientist375, on 2.1.4.19 