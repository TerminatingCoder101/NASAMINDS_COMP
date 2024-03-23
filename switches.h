#ifndef switches
#define switches
int antenna=1;
int main_switch=0;
//switcher is for the main switch to switch between the 8 antenna module switch
void switcher(){
  if (main_switch==0){
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
  }
    if (main_switch==1){
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
  }
}
//antenna switch is to switch between the different antennas connected to the 1st antenna switcher
void antenna_switch_1(){
  if (antenna==1){
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
  }
  if (antenna==2){
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
  }
  if (antenna==3){
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    digitalWrite(12,LOW);
  }
  if (antenna==4){
    digitalWrite(10,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(12,LOW);
  }
  if (antenna==5){
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(12,HIGH);
  }
  if (antenna==6){
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(12,HIGH);
  }
  if (antenna==7){
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    digitalWrite(12,HIGH);
  }
  if (antenna==8){
    digitalWrite(10,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(12,HIGH);
  }
}
//antenna switch is to switch between the different antennas connected to the second antenna switcher
void antenna_switch_2(){
  if (antenna==1){
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
  }
  if (antenna==2){
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
  }
  if (antenna==3){
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
  }
  if (antenna==4){
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
  }
  if (antenna==5){
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
  }
  if (antenna==6){
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
  }
  if (antenna==7){
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
  }
  if (antenna==8){
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
  }
}
#endif