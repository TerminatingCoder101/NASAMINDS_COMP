//This is a test code for the quadrant system for our Heat Mapping

#include <iostream>

using namespace std;

int main()
{


//Variable declarations and initialization

int SSarray[15] = {0, 0, 0, 0, 0, 0, 0, 197 , 200, 180 , 0 , 200 , 203 , 0 , 0};
int quad = 0;
int max = 0;
int relay = 0;
int maxrelay = 0;
int quadrant[40];

//Find the strongest relay from our SSarray and saves to output

for (int i = 0; i < 15 ; i++)
{
	if (SSarray[i] > maxrelay)
	{
		maxrelay = SSarray[i];
		relay = i;

	}
}

//Initializes our quadrant values

for (int i = 0; i < 40; i++)
{
	quadrant[i] = 0;
}


//Calculates each regions signal strength

quadrant[0] = SSarray[7] + SSarray[11] + SSarray[12];
quadrant[1] = SSarray[11] + SSarray[12]; 
quadrant[2] = SSarray[8] + SSarray[11] + SSarray[12];
quadrant[3] = SSarray[9] + SSarray[13] + SSarray[14];
quadrant[4] = SSarray[13] + SSarray[14];
quadrant[5] = SSarray[12] + SSarray[13] + SSarray[10];
quadrant[6] = SSarray[7] + SSarray[11];
quadrant[7] = SSarray[7] + SSarray[8] +SSarray[11] + SSarray[12];
quadrant[8] = SSarray[8] + SSarray[12];
quadrant[9] = SSarray[9] + SSarray[13];
quadrant[10] = SSarray[9] + SSarray[10] +SSarray[13] + SSarray[14];
quadrant[11] = SSarray[10] + SSarray[14];
quadrant[12] = SSarray[7] + SSarray[8] + SSarray[11];
quadrant[13] = SSarray[7] + SSarray[8];
quadrant[14] = SSarray[7] + SSarray[8] + SSarray[13];
quadrant[15] = SSarray[9] + SSarray[10] + SSarray[13];
quadrant[16] = SSarray[9] + SSarray[11];
quadrant[17] = SSarray[9] + SSarray[10] + SSarray[14];
quadrant[18] = SSarray[0] + SSarray[4] + SSarray[8];
quadrant[19] = SSarray[4] + SSarray[5];
quadrant[20] = SSarray[1] + SSarray[4] + SSarray[8];
quadrant[21] = SSarray[2] + SSarray[6] + SSarray[9];
quadrant[22] = SSarray[9] + SSarray[6];
quadrant[23] = SSarray[3] + SSarray[6] + SSarray[9];
quadrant[24] = SSarray[0] + SSarray[4];
quadrant[25] = SSarray[0] + SSarray[1] + SSarray[4] + SSarray[8];
quadrant[26] = SSarray[0] + SSarray[1] + SSarray[4] + SSarray[5];
quadrant[27] = SSarray[1] + SSarray[4] + SSarray[5];
quadrant[28] = SSarray[1] + SSarray[5];
quadrant[29] = SSarray[2] + SSarray[5];
quadrant[30] = SSarray[2] + SSarray[5] + SSarray[6];
quadrant[31] = SSarray[2] + SSarray[3] + SSarray[6] + SSarray[9];
quadrant[32] = SSarray[2] + SSarray[3] + SSarray[5] + SSarray[6];
quadrant[33] = SSarray[3] + SSarray[6];
quadrant[34] = SSarray[0] + SSarray[1] + SSarray[4];
quadrant[35] = SSarray[0] + SSarray[1];
quadrant[36] = SSarray[1] + SSarray[0] + SSarray[5];
quadrant[37] = SSarray[2] + SSarray[3] + SSarray[5];
quadrant[38] = SSarray[2] + SSarray[3];
quadrant[39] = SSarray[2] + SSarray[3] + SSarray[6];

//Goes through each quadrant to find the strongest signal value and 
//saves the quadrant and it's strength to be further tested and outputted
for (int i = 0; i < 40; i++)
{
         if (quadrant[i] > max)
		{
		max = quadrant[i];
		quad = i;
			
		}
}


//Output displayed
std::cout << "Quadrant: " << quad << "\nStrongest Relay: " << relay << "\n";

//Test Quadrant Checking for Questionable Areas
//Larger Area Checks:
// This is the check for the bottom left Large Area
if (quad == 7)
{
	int cases = 0;


	if ((SSarray[7] + SSarray[8]) > (SSarray[11] + SSarray[12]))
	{
	//Top side Cases
		if ((SSarray[7] + SSarray[11]) > (SSarray[8] + SSarray[12]))
		{
		//Left Side Case
			cases = 1;
		}
		else if((SSarray[7] + SSarray[11]) < (SSarray[8] + SSarray[12]))
		{
		//Right Side Case
			cases = 3;
		}
		else
		{
		//Middle Case
			cases = 2;
		}
	
	}
	else if ((SSarray[7] + SSarray[8]) < (SSarray[11] + SSarray[12]))
	{
	//Bottom side Cases
	        if ((SSarray[7] + SSarray[11]) > (SSarray[8] + SSarray[12]))
	        {
	        //Left Side Case
	        	cases = 7;
	        }
	        else if((SSarray[7] + SSarray[11]) < (SSarray[8] + SSarray[12]))
	        {
	        //Right Side Case
	        	cases = 9;
	        }
	        else
	        {
	        //Middle Case;
			cases = 8;
	        }
	
	}
	else
	{
	//Middle case

	if ((SSarray[7] + SSarray[11]) > (SSarray[8] + SSarray[12]))
	        {
	        //Left Side Case
			cases = 4;
	        }
	        else if((SSarray[7] + SSarray[11]) < (SSarray[8] + SSarray[12]))
	        {
	        //Right Side Case
			cases = 6;
       		}
        	else
        	{
        	//Direct Center Case
			cases = 5;
        	}
	
	}
	
	//Switch case to tell the location within the given quadrant	
	switch(cases){
	
		case 1:
		cout << "\n Top Left \n" ;
		break;
	
	        case 2:
	        cout << "\n Top Middle \n" ;
	        break;
		
		case 3:
	        cout << "\n Top Right \n" ;
	        break;
	
	        case 4:
	        cout << "\n Middle Left \n" ;
	        break;
	
	        case 5:
	        cout << "\n Center \n" ;
	        break;
	
	        case 6:
	        cout << "\n Middle Right \n" ;
	        break;
	
	        case 7:
	        cout << "\n Bottom Left \n" ;
	        break;
	
	        case 8:
	        cout << "\n Bottom Middle \n" ;
	        break;
	
	        case 9:
	        cout << "\n Bottom Right \n" ;
        	break;
	}
}

//Test Quadrant Checking for Questionable Areas
//Larger Area Checks:
// This is the check for the bottom right Large Area
if (quad == 10)
{
        int cases = 0;


        if ((SSarray[9] + SSarray[10]) > (SSarray[13] + SSarray[14]))
        {
        //Top side Cases
                if ((SSarray[9] + SSarray[10]) > (SSarray[13] + SSarray[14]))
                {
                //Left Side Case
                        cases = 1;
                }
                else if((SSarray[9] + SSarray[10]) < (SSarray[13] + SSarray[14]))
                {
                //Right Side Case
                        cases = 3;
                }
                else
                {
                //Middle Case
                        cases = 2;
                }

        }
        else if ((SSarray[9] + SSarray[10]) < (SSarray[13] + SSarray[14]))
        {
        //Bottom side Cases
                if ((SSarray[9] + SSarray[10]) > (SSarray[13] + SSarray[14]))
                {
                //Left Side Case
                        cases = 7;
                }
                else if((SSarray[9] + SSarray[10]) < (SSarray[13] + SSarray[14]))
                {
                //Right Side Case
                        cases = 9;
                }
                else
                {
                //Middle Case;
                        cases = 8;
                }
	}
        else
        {
        //Middle case

        if ((SSarray[9] + SSarray[10]) > (SSarray[13] + SSarray[14]))
                {
                //Left Side Case
                        cases = 4;
                }
                else if((SSarray[9] + SSarray[10]) < (SSarray[13] + SSarray[14]))
                {
                //Right Side Case
                        cases = 6;
                }
                else
                {
                //Direct Center Case
                        cases = 5;
                }

        }

        //Switch case to tell the location within the given quadrant
        switch(cases){

                case 1:
                cout << "\n Top Left \n" ;
                break;

                case 2:
                cout << "\n Top Middle \n" ;
                break;

                case 3:
                cout << "\n Top Right \n" ;
                break;

                case 4:
                cout << "\n Middle Left \n" ;
                break;

                case 5:
                cout << "\n Center \n" ;
                break;

                case 6:
                cout << "\n Middle Right \n" ;
                break;

                case 7:
                cout << "\n Bottom Left \n" ;
                break;

                case 8:
                cout << "\n Bottom Middle \n" ;
                break;

                case 9:
                cout << "\n Bottom Right \n" ;
                break;
	}
}

//This is the check for the bottom side left side 
//Small area check 

if (quad == 2)
{
	if(SSarray[11] > SSarray[12])
	{
		cout << "\nLeft Side \n";
	
	}
	else if (SSarray[11] < SSarray[12]) 
	{
		cout << "\nRight Side \n";
	
	}
	else
	{
		cout << "\n Center\n";
	}

}

//This is the check for the bottom side right case
//Small area check 

if (quad == 4)
{
        if(SSarray[13] > SSarray[14])
        {
                cout << "\nLeft Side \n";

        }
        else if (SSarray[13] < SSarray[14]) 
        {
                cout << "\nRight Side \n";

        }
        else
        {
                cout << "\n Center\n";
        }

}

//This is the check for the left side bottom case
//Small area check

if (quad == 6)
{
        if(SSarray[7] > SSarray[11])
        {
                cout << "\nTop Side \n";

        }
        else if (SSarray[7] < SSarray[11]) 
        {
                cout << "\nBottom Side \n";

        }
        else
        {
                cout << "\n Center\n";
        }

}

//This is the check for Right side bottom case
//Small area check 

if (quad == 11)
{
        if(SSarray[10] > SSarray[14])
        {
                cout << "\nTop Side \n";

        }
        else if (SSarray[10] < SSarray[14]) 
        {
                cout << "\nBottom Side \n";

        }
        else
        {
                cout << "\n Center\n";
        }

}

//This is the check for Left side top case
//Small Area check

if (quad == 24)
{
        if(SSarray[0] > SSarray[5])
        {
                cout << "\nTop Side \n";

        }
        else if (SSarray[0] < SSarray[5]) 
        {
                cout << "\nBottom Side \n";

        }
        else
        {
                cout << "\n Center\n";
        }

}

//This is the check for the right side top case
//Small area check 

if (quad == 33)
{
        if(SSarray[3] > SSarray[6])
        {
                cout << "\nTop Side \n";

        }
        else if (SSarray[3] < SSarray[6]) 
        {
                cout << "\nBottom Side \n";

        }
        else
        {
                cout << "\n Center\n";
        }

}

//This is the check for the Top side left case
//This is a small area check

if (quad == 35)
{
        if(SSarray[0] > SSarray[1])
        {
                cout << "\nLeft Side \n";

        }
        else if (SSarray[0] < SSarray[1]) 
        {
                cout << "\nRight Side \n";

        }
        else
        {
                cout << "\n Center\n";
        }

}

//This is the top side right case
//This is a small area check

if (quad == 38)
{
        if(SSarray[2] > SSarray[3])
        {
                cout << "\nLeft Side \n";

        }
        else if (SSarray[2] < SSarray[3]) 
        {
                cout << "\nRight Side \n";

        }
        else
        {
                cout << "\n Center\n";
        }

}

//Inner case Bottom case
//Orange Areas

if (quad == 8 || quad == 9)
{
        if(SSarray[8] + SSarray[9] >  SSarray[12] + SSarray[13])
        {
                cout << "\nTop side \n";

        }
        else if (SSarray[8] + SSarray[9] < SSarray[12] + SSarray[13]) 
        {
                cout << "\nBottom Side \n";

        }
        else
        {
                cout << "\n Center\n";
        }

}

//Inner case Left case
//Orange Areas

if (quad == 13 || quad == 19)
{
        if(SSarray[8] + SSarray[9] >  SSarray[12] + SSarray[13])
        {
                cout << "\nTop side \n";

        }
        else if (SSarray[8] + SSarray[9] < SSarray[12] + SSarray[13])
        {
                cout << "\nBottom Side \n";

        }
        else
        {
                cout << "\n Center\n";
        }

}


return 0;

}
