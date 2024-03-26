#ifndef find
#define find
void finder(int data,int tag,int antenna,int location[],int strength[],int strength_value){
  if(data==tag){
    location[antenna]=1;
    Serial.println(location[antenna]);
    strength[antenna]=strength_value;
  }
}
void tracker(int tag_id,int antenna_pinging,int tag_array[]){

}
#endif