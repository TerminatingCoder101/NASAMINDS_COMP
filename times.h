#ifndef times
#define times
double time=0;
int antenna_number=0;
int finish=0;
int track=0;
//logic to switch the antennas 
void time_function(){
  //to create a time variable
  time=time+1;
  //function to iterate through the antennas
  if (time>50000){
    time=0;
    antenna++;
    antenna_number++;
  }
  // this statement is to switch to the second module and iterate through the other 7 antennas
  if (antenna==9 && main_switch==0){
    antenna=1;
    main_switch=1;
    }
  //this is statement is to switch back to the first module and iterate through the first antennas
  if (antenna==9 && main_switch==1){
    antenna=1;
    main_switch=0;
    //this is to reset the antenna number in the array
    antenna_number=0;
    finish=1;
  }

}
#endif