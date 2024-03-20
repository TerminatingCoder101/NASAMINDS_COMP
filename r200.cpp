#include "r200.h"

void r200::add(LinkedList<Tag> *Tags)
{
    loopTimer = millis();
    while(millis() < loopTimer+1000)
    {
            timeSec ++ ;

            if(timeSec >= 50000)
            {
                timemin ++;
                
                timeSec = 0;
                
                if(timemin >= 20)
                {
                    timemin = 0;
                    Serial.write(ReadMulti,10);
                }
            }
            
            if(Serial.available() > 0)
            {
                incomedate = Serial.read();
                
                if((incomedate == 0x02)&(parState == 0))
                {
                    parState = 1;
                }
                
                else if((parState == 1)&(incomedate == 0x22)&(codeState == 0))
                {  
                    codeState = 1;
                    dataAdd = 3;
                }
                else if(codeState == 1)
                {
                    dataAdd ++;
                    if((dataAdd >= 9)&(dataAdd <= 20))
                    {
                    
                        if((dataAdd >= 9)&(dataAdd <= 20))
                        {
                            tagNum += incomedate;
                        }

                    }
                    
                    else if(dataAdd >= 21)
                    {
                            
                        dataAdd= 0;
                        parState = 0;
                        codeState = 0;
                        
                        for(int i = 0; i < Tags->size();i++)
                        {
                            if(Tags->get(i).ID == tagNum)
                            {
                                notDuplicate = false;
                            }
                        }
                        if(notDuplicate)
                        {
                            Tags->add({tagNum,0,0});
                        }
                        notDuplicate = true;
                
                        tagNum=0;
                    }
                }
            else
            {
                dataAdd= 0;
                parState = 0;
                codeState = 0;
            }
        }
    }
    timeSec = timemin = 0;
    return;
}

bool r200::fetch(unsigned int tagToFind)
{
    loopTimer = millis();
    while(millis() < loopTimer+1000)
    {
            timeSec ++ ;

            if(timeSec >= 50000)
            {
                timemin ++;
                
                timeSec = 0;
                
                if(timemin >= 20)
                {
                    timemin = 0;
                    Serial.write(ReadMulti,10);
                }
            }
            
            if(Serial.available() > 0)
            {
                incomedate = Serial.read();
                
                if((incomedate == 0x02)&(parState == 0))
                {
                    parState = 1;
                }
                
                else if((parState == 1)&(incomedate == 0x22)&(codeState == 0))
                {  
                    codeState = 1;
                    dataAdd = 3;
                }
                else if(codeState == 1)
                {
                    dataAdd ++;
                    if((dataAdd >= 9)&(dataAdd <= 20))
                    {
                    
                        if((dataAdd >= 9)&(dataAdd <= 20))
                        {
                            tagNum += incomedate;
                        }

                    }
                    
                    else if(dataAdd >= 21)
                    {
                            
                        dataAdd= 0;
                        parState = 0;
                        codeState = 0;
                        
                        if(tagNum == tagToFind)
                        {
                            return true;
                        }
                    }
                }
            else
            {
                dataAdd= 0;
                parState = 0;
                codeState = 0;
            }
        }
    }
    timeSec = timemin = 0;
    return false;
}