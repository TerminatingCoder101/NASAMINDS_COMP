#ifndef times
#define times
double time=0;
int antenna_number=0;
int finish=0;
int track=0;
//logic to switch the antennas 
void time_function(int mod){
  //to create a time variable
  time=time+1;
  //function to iterate through the antennas
   if (mod==0){
    if (time>500000){
    time=0;
    antenna++;
    antenna_number++;
    }
  }
   if (mod==1){
     if (time>40000){
    time=0;
    antenna++;
    antenna_number++;
  }
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
    if (finish==0){
      finish=1;

    }
  }
//   switch(antenna_number){
//     case 0:
//       antenna_number=7;
//       break;
//     case 1:
//       antenna_number=4;
//       break;
//     case 2:
//       antenna_number=10;
//       break;
//     case 3:
//       antenna_number=8;
//       break;
//     case 4:
//       antenna_number=6;
//       break;
//     case 5:
//       antenna_number=5;
//       break;
//     case 6:
//       antenna_number=9;
//       break;
//     case 7:
//       antenna_number=1;
//       break;
//     case 8:
//       antenna_number=2;
//       break;
//     case 9:
//       antenna_number=11;
//       break;
//     case 10:
//       antenna_number=14;
//       break;
//     case 11:
//       antenna_number=0;
//       break;
//     case 12:
//       antenna_number=3;
//       break;
//     case 13:
//       antenna_number=12;
//       break;
//     case 14:
//       antenna_number=13;
//       break;
//   }
// }
}
#endif