//YouTube | Tech at Home

#include "SevSeg.h"

SevSeg S;
byte CommonPins[] = {};            // common pin numbers for multi-digit display 
byte SegPins[] = {2,3,4,5,6,7,8};  // 7-segment display pins in the order,{a,b,c,d,e,f,g,dp}

int btn1=9;   //button for increment
int btn2=10;  //button for decrement
int cnt=0;
int incPrev, decPrev;

void setup()
{
  // Syntax
  // begin(COMMON_CATHODE, NumberOfDigits, CommonPins[], SevenSegPins[], resistorUsed);
  
  S.begin(COMMON_CATHODE, 1, CommonPins, SegPins, 1);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
}

void loop()
{
    int inc = digitalRead(9);
    int dec = digitalRead(10);

    //Increment
    if((inc == HIGH) && (cnt < 9) && (inc != incPrev ))
    {
      delay(100);
      cnt++;
    }
    
     //Decrement
    if((dec == HIGH) && (cnt >0) && (dec != decPrev))
    {
      delay(100);
      cnt--;
    }

    //Logic to print digit/character on 7 segment display
    S.setNumber(cnt);
    S.refreshDisplay();
    delay(100);

    //storing the button states
    incPrev = inc;
    decPrev = dec;

}
