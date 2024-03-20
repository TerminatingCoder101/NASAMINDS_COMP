#include <LinkedList.h>
#include <Arduino.h>
#include "define.h"

enum AnttenaArray
{
    topLeft,
    topMiddle,
    topRight,
    right,
    bottomRight,
    bottomMiddle,
    bottomLeft,
    left,
    center
};


class AnttenaSwitcher
{
    public:
        int anttenaNum = 2;
        AnttenaSwitcher()
        {
            pinMode(10, OUTPUT);
        }
        void swtich(int anttena)
        {
            switch (anttena)
            {
            case topLeft:
                Serial.println("Top Left");
                digitalWrite(10, LOW);
                break;
            case topMiddle:
                Serial.println("Top Right");
                digitalWrite(10, HIGH);
                break;
            
            default:
                break;
            }
            return;
        }

    private:

};
