/*
  NASA_MINDS PROJECT
  PROGRAM FOR ECHO SYSTEM
  VERSION 1.0.0
  3/16/24
*/
#include "switches.h"
#include "times.h"
#include "store.h"
#include "find.h"
#include "alg.h"


unsigned char ReadMulti[10] = {0XAA,0X00,0X27,0X00,0X03,0X22,0XFF,0XFF,0X4A,0XDD};
unsigned int timeSec = 0;
unsigned int timemin = 0;
unsigned int dataAdd = 0;
unsigned int incomedate = 0;
unsigned int parState = 0;
unsigned int codeState = 0;
int Result[1];
int Results[201];
int mode=1;
int count=0;
int mapArray[10][10];

// for version 2.0
//int Loc[321];
int strength_location[15];
int POS[100];
int TAG[100];
int Location[15];
int tag;
bool trans=false;
int add=0;
int strength;
void setup() {

  clearMap(mapArray);
  pinMode(LED_BUILTIN, OUTPUT);
  //pins for switch 1
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  //pins for the main switch
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  //pins for switch 2
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(115200); 
  
  Serial.println("Hello world.");// "Hello world."
  
  Serial.write(ReadMulti,10);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
}

void loop() {

  timeSec ++ ;
  switcher();
  if (main_switch==0){
     antenna_switch_1();
   }
  if(main_switch==1){
     antenna_switch_2();
   }
  time_function(mode);
  if(timeSec >= 50000){
    timemin ++;
	
    timeSec = 0;
	
    if(timemin >= 20){
      timemin = 0;
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.write(ReadMulti,10);
      digitalWrite(LED_BUILTIN, LOW); 
    }
  }
  if (finish==1){
    Serial.print("Location: [");
    for (int k=0;k<15;k++){
      Serial.print(Location[k]);Serial.print(",");
    }
    Serial.print(" ]");Serial.println(" ");
    Serial.print("Strenght: [");
    for (int a=0;a<15;a++){
      Serial.print(strength_location[a]);Serial.print(",");
    }
    Serial.print(" ]");Serial.println(" ");
    Serial.print("Tags: [");
    for (int b=0;b<40;b++){
      Serial.print(TAG[b]);Serial.print(",");
    }
    Serial.print(" ]");Serial.println(" ");
    Serial.println(count);
    finish++;
    //using the position fnction to get the coordinates
    //getPos15Sensors(Location,Result);

    //printing out the results
    Serial.print("(");Serial.print(Result[0]);Serial.print(",");Serial.print(Result[1]);Serial.println(")");
    
    fillMap(mapArray, strength_location);
    getPos(mapArray);
  }
  if(Serial.available() > 0 && finish==0)
  {
    incomedate = Serial.read();
	
    if((incomedate == 0x02)&(parState == 0))
    {
      parState = 1;
    }
    else if((parState == 1)&(incomedate == 0x22)&(codeState == 0)){  
        codeState = 1;
        dataAdd = 3;
    }
    else if(codeState == 1){
      dataAdd ++;
      if(dataAdd == 6)
      {
        //Serial.print("RSSI:"); 
        strength=incomedate;               //STRENGTH 
        }
       
       else if((dataAdd >= 9)&(dataAdd <= 20)){           //TAG ID
        add+=incomedate;
       }
       else if(dataAdd >= 21){
        Serial.println(" ");
        dataAdd= 0;
        parState = 0;
        codeState = 0;
        storing(add,TAG,count);
        //finder is the function to only locate 1 specific tag
        finder(add,1224,antenna_number,Location,strength_location,strength);
        add=0;
        Serial.println(TAG[0]); Serial.print("antenna:");Serial.println(antenna_number);Serial.println(time);
        //Serial.println(main_switch);
        //Serial.println(antenna_number);
        //Serial.println(Location[14]);
        }
    }
     else{
      dataAdd= 0;
      parState = 0;
      codeState = 0;
      add=0;
    }
  }

}

