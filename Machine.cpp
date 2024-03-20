#include "Machine.h"

Machine::Machine()
{
    activeState = FETCH;
    Tags = LinkedList<Tag>(); 
    notDuplicate = true;
}

//main loop to active different functions of the code by changing the active state 
void Machine::loop()
{
    switch(activeState)
    {
        case FETCH:
            int anttenaArray[12] = {};
            fetch(1362, anttenaArray); //1314
            for(int i = 0; i < 11; i++)
            {
                Serial.println(anttenaArray[i]);
            }
            while(true){}
        case ADD:
            add();
            break;
        case TRACK:
            add();
            track();
            break;
    }
}

//goes through each antenna and gets all the tags in a room 
//and puts it in a dynamic linked list
void Machine::add()
{
    for(int i = 0; i < anttena.anttenaNum; i++)
    {
        anttena.swtich(i);
        reader.add(&Tags);
    }

    //to display all the tags ID captured. 
   for(int i = 0; i < Tags.size();i++)
    {
        Serial.println(Tags.get(i).ID);
    }
    return;
}

//returns array of 1 and 0 depending on which antenna picked up the tag 
//given to it in the argument
void Machine::fetch(unsigned int tagToFind, int *anttenaArray)
{
    for(int i = 0; i < anttena.anttenaNum; i++)
    {
        anttena.swtich(i);
        if(reader.fetch(tagToFind))
        {
            anttenaArray[i] = 1;
        }
    }
    return;
}

//inventary tracking constantly updates location of all tags and displays them at the end 
//STILL NEEDS WORK NOT READY
void Machine::track()
{
    while(true)
    {   
        for(int i = 0;i < Tags.size();i++)
        {
            Tags[i].x = 0; //location x find(fetch(Tags.get(i).ID))
            Tags[i].y = 0; //location y find(fetch(Tags.get(i).ID))
            Serial.print("Tag: ");
            Serial.print(Tags.get(i).ID);
            Serial.print(" [");
            Serial.print(Tags.get(i).x);
            Serial.print(", ");
            Serial.print(Tags.get(i).y);
            Serial.println("]");
        }
    }
}
