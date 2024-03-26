#ifndef alg
#define alg
const int num_sensors = 15;
void clearMap(int array[10][10])
{
    for(int i = 0; i < 10 ; i++)
    {
        for(int ind = 0; ind < 10 ; ind++)
        {
            array[i][ind] = 0;

        }

    }

}

void getPos(int array[][10])
{
int max = 0;
int x1;
int x2;
int y1;
int y2;
double x;
double y;


    for(int i = 0; i < 10 ; i++)
    {
        for(int ind = 0; ind < 10 ; ind++)
        {
            if ( (array[i][ind]) > max)
            {
                max = array[i][ind];
                x1  = i;
                x2 = i;
                y1 = ind;
                y2 = ind;

            }
            else if (max == array[i][ind])
            {
                x2 = i;
                y2 = ind;
            
            }

        }

    }

    x = (x1 + x2) /2.0 ;
    y = (y1 + y2) /2.0 ;

    Serial.print("( ");
    Serial.print(x);
    Serial.print(" , ");
    Serial.print(y);
    Serial.print(" )");
}


void fillMap(int mapArray[][10] , int array[15])
{   
    if(array[0] != 0)
    {
        for(int i = 0; i < 4 ; i++) //Sensor 1's Area Filling
        {
            for(int ind = 6; ind < 10 ; ind++)
            {
                mapArray[i][ind] += array[0];

            }

        }
    }

    if(array[1] != 0)
    {
        for(int i = 0; i < 4 ; i++) ///Sensor 1's Area Filling
        {
            for(int ind = 4; ind < 8 ; ind++)
            {
                mapArray[i][ind] += array[1];

            }

        }
    }

    if(array[2] != 0)
    {
        for(int i = 1; i < 5 ; i++) //Sensor 2's Area Filling
        {
            for(int ind = 4; ind < 8 ; ind++)
            {
                mapArray[i][ind] += array[2];

            }

        }
    }

    if(array[3] != 0)
    {
        for(int i = 1; i < 5 ; i++) //Sensor 3's Area Filling
        {
            for(int ind = 6; ind < 10 ; ind++)
            {
                mapArray[i][ind] += array[3];

            }

        }
    }

    if(array[4] != 0)
    {
        for(int i = 1; i < 5 ; i++) //Sensor 4's Area Filling
        {
            for(int ind = 0; ind < 4 ; ind++)
            {
                mapArray[i][ind] += array[4];

            }

        }
    }

    if(array[5] != 0)
    {
        for(int i = 2; i < 7 ; i++) //Sensor 5's Area Filling
        {
            for(int ind = 0; ind < 4 ; ind++)
            {
                mapArray[i][ind] += array[5];

            }

        }
    }

    if(array[6] != 0)
    {
        for(int i = 0; i < 4 ; i++) //Sensor 6's Area Filling
        {
            for(int ind = 1; ind < 5 ; ind++)
            {
                mapArray[i][ind] += array[6];

            }

        }
    }
    
    if(array[7] != 0) //Sensor 7's Area Filling
    {
        for(int i = 0; i < 4 ; i++)
        {
            for(int ind = 0; ind < 4 ; ind++)
            {
                mapArray[i][ind] += array[7];

            }

        }
    }
    
    if(array[8] != 0) //Sensor 8's Area Filling
    {
        for(int i = 6; i < 10 ; i++)
        {
            for(int ind = 0; ind < 4 ; ind++)
            {
                mapArray[i][ind] += array[8];

            }

        }
    }
    
    if(array[9] != 0) //Sensor 9's Area Filling
    {
        for(int i = 6; i < 10 ; i++)
        {
            for(int ind = 1; ind < 5 ; ind++)
            {
                mapArray[i][ind] += array[9];

            }

        }
    }
    
    if(array[10] != 0) //Sensor 10's Area Filling
    {
        for(int i = 5; i < 9 ; i++)
        {
            for(int ind = 0; ind < 4 ; ind++)
            {
                mapArray[i][ind] += array[10];

            }

        }
    }
    
    if(array[11] != 0) //Sensor 11's Area Filling
    {
        for(int i = 4; i < 9 ; i++)
        {
            for(int ind = 4; ind < 8 ; ind++)
            {
                mapArray[i][ind] += array[11];

            }

        }
    }
    
    if(array[12] != 0) //Sensor 12's Area Filling
    {
        for(int i = 5; i < 9 ; i++)
        {
            for(int ind = 6; ind < 10 ; ind++)
            {
                mapArray[i][ind] += array[12];

            }

        }
    }
    
    if(array[13] != 0) //Sensor 13's Area Filling
    {
        for(int i = 6; i < 10 ; i++)
        {
            for(int ind = 6; ind < 10 ; ind++)
            {
                mapArray[i][ind] += array[13];

            }

        }
    }

    if(array[14] != 0) //Sensor 14's Area Filling
    {
        for(int i = 6; i < 10 ; i++)
        {
            for(int ind = 5; ind < 9 ; ind++)
            {
                mapArray[i][ind] += array[14];

            }

        }
    }


}
#endif