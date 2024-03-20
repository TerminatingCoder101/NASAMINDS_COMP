#include "Machine.h"

// Serial realted buffer and time constants

unsigned char power[9] = {0XAA, 0X00, 0XB6, 0X00, 0x02, 0x07, 0x00, 0X8F, 0XDD};
unsigned char ReadMulti[10] = {0XAA,0X00,0X27,0X00,0X03,0X22,0XFF,0XFF,0X4A,0XDD};
Machine states;

void setup() //send intructions to r200 to read multi tags
{
  Serial.begin(115200);
  Serial.println("Hello world.");
  Serial.write(ReadMulti,10);
}

void loop()
{
    states.loop();
}