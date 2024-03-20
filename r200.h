#include "AnttenaSwitcher.h"

class r200
{
    public:
        r200()
        {
            
        }
        //using r200 base code modified it to fill LinkedList of Tag structure 
        //prevents adding duplicate tags automaticaly 
        void add(LinkedList<Tag> *Tags);

        //using r200 base code modified it to return true or false if a given tagID is found
        bool fetch(unsigned int tagToFind);
    private:
        unsigned char ReadMulti[10] = {0XAA,0X00,0X27,0X00,0X03,0X22,0XFF,0XFF,0X4A,0XDD};
        unsigned int timeSec = 0;
        unsigned int timemin = 0;
        unsigned int dataAdd = 0;
        unsigned int incomedate = 0;
        unsigned int parState = 0;
        unsigned int codeState = 0;
        unsigned int tagNum;
        bool notDuplicate = true;
        int loopTimer;
        
};
