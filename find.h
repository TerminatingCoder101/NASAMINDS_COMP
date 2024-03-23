#ifndef find
#define find
void finder(int data,int tag,int antenna,int location[]){
  if(data==tag){
    location[antenna-1]=1;
    Serial.println(location[antenna]);
  }
}
#endif