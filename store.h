#ifndef store
#define store
int skip=0;
void storing(int data,int TAG[],int &count){
  for (int i=0; i<100; i++){
    if (data !=0 && data==TAG[i]){
      skip=1;
    }
  }
  for (int j=0; j<100;j++){
    if (skip==0 && TAG[j]==0){
      TAG[j]=data;
      count++;
      skip=0;
      break;
    }
    if (skip==1){
      skip=0;
      break;
    }
  }
}
#endif