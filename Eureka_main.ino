/*
  NASA_MINDS PROJECT
  PROGRAM FOR EUREKA SYSTEM
  VERSION 1.0.0
  3/16/24
*/

unsigned char ReadMulti[10] = {0XAA,0X00,0X27,0X00,0X03,0X22,0XFF,0XFF,0X4A,0XDD};
unsigned int timeSec = 0;
unsigned int timemin = 0;
unsigned int dataAdd = 0;
unsigned int incomedate = 0;
unsigned int parState = 0;
unsigned int codeState = 0;
int TAG[100]; 
bool trans=false;
int add=0;
int skip=0;
int skipper=0;
int find=2;
int strength;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  Serial.begin(115200);
  
  Serial.println("Welcome to the Eureka System.");
  Serial.write(ReadMulti,10);
}

void loop() {
  timeSec++;
  
  if(timeSec >= 50000){
    timemin++;
	
    timeSec = 0;
	
    if(timemin >= 20){
      timemin = 0;
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.write(ReadMulti,10);
      digitalWrite(LED_BUILTIN, LOW); 
    }
  }
 
  if(Serial.available() > 0)
    incomedate = Serial.read();

  if((incomedate == 0x02) && (parState == 0)){
    parState = 1;
  }
  else if((parState == 1) && (incomedate == 0x22) && (codeState == 0)){  
    codeState = 1;
    dataAdd = 3;
  }
  else if(codeState == 1){
    dataAdd++;
	  
    if(dataAdd == 6){
      strength = incomedate; // STRENGTH 
    }
    else if((dataAdd == 7) || (dataAdd == 8)){
      // Handle PC data
    }
    else if((dataAdd >= 9) && (dataAdd <= 20)){
      // Handle EPC data
      add += incomedate;
    }
    else if(dataAdd >= 21){
      // Process tag data
      Serial.println(" ");
      for (int i = 0; i < 8; i++){
        if (add != 0 && add == TAG[i]){
          skip = 1;
        }
      }
      for (int j = 0; j < 8; j++){
        if (skip == 0 && TAG[j] == 0){
          TAG[j] = add;
          skip = 0;
          break;
        }
        if (skip == 1){
          skip = 0;
          break;
        }
      }
      dataAdd = 0;
      parState = 0;
      codeState = 0;
      
      Serial.print("tag 1:");
      Serial.print(TAG[0]);
      Serial.print(" tag 2:");
      Serial.print(TAG[1]);
      Serial.print(" tag 3:");
      Serial.print(TAG[2]);
      Serial.print(" tag 4:");
      Serial.println(TAG[3]);
      Serial.print(" tag 5:");
      Serial.print(TAG[4]);

      if(TAG[find] == add){
        if (strength > 180 && strength <= 200){
          digitalWrite(9, HIGH);
          digitalWrite(8, LOW);
          digitalWrite(7, LOW);
        }
        if (strength > 200 && strength <= 215){
          digitalWrite(9, LOW);
          digitalWrite(8, HIGH);
          digitalWrite(7, LOW);
        }
        if (strength > 215){
          digitalWrite(9, LOW);
          digitalWrite(8, LOW);
          digitalWrite(7, HIGH);
        }
      }
      else if(add == 0){
        digitalWrite(9, LOW);
        digitalWrite(8, LOW);
        digitalWrite(7, LOW);
      }
      else{
        digitalWrite(9, LOW);
        digitalWrite(8, LOW);
        digitalWrite(7, LOW);
      }
      add = 0;
    }
  }
  else{
    dataAdd = 0;
    parState = 0;
    codeState = 0;
  }
}
