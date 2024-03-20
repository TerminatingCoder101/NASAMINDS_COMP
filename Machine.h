#include "r200.h"

class Machine
{
    public:
        Machine();
        //main loop to active different functions of the code by changing the active state 
        void loop();

        ////goes through each antenna and gets all the tags in a room 
        //and puts it in a dynamic linked list
        void add();

        //inventary tracking constantly updates location of all tags and displays them at the end 
        //STILL NEEDS WORK NOT READY
        void track();

        //returns array of 1 and 0 depending on which antenna picked up the tag 
        //given to it in the argument
        void fetch(unsigned int tagToFind, int *anttenaArray);
    private:
        State activeState;
        AnttenaSwitcher anttena;
        LinkedList<Tag> Tags;
        r200 reader;
        bool notDuplicate;
        bool tagFound = false;

};
