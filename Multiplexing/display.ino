/* display
 *  
 *  CSE 132 - Assignment 7
 *  
 *  Fill this out so we know whose assignment this is.
 *  
 *  Name: Jordyn Goldstein  
 *  WUSTL Key: jordyn.goldstein
 *  
 *  Name: Amee Rothman
 *  WUSTL Key: arothman
 *  
 */

#include "font.h"

const int TOP = A1;
const int BOTT = A0;
unsigned long deltaDebounce = 5;
unsigned long lastDebounce = 0;
unsigned long now; 
int c = 10; 

int butstat1;
int butstat2; 
int lastbutstat1 = HIGH;
int lastbutstat2 = HIGH;
unsigned long lDebounceT1 = 0; 
unsigned long lDebounceT2 = 0;
unsigned long dbnceDelay = 50;
int reading1 = -1;
int reading2  = -1; 




void setup ()
{
  // insert code here as needed
Serial.begin(9600);
pinMode(TOP, INPUT_PULLUP);
pinMode(BOTT, INPUT_PULLUP);
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);
pinMode(13, OUTPUT);

butstat1 = HIGH; 
butstat2 = HIGH; 

}

void loop ()
{
  // insert code here as needed

  topDebounce();
  bottDebounce(); 
  Serial.println(c);

   byte b;
 
   int colCount = 6;
    for (int i = 0; i<=4; i++)
    {
      b = font_5x7[c][i];
      digitalWrite(colCount, LOW);
    
        for(int j = 1; j <= 7; j++)
      { 
        digitalWrite(j+6, (b >> j) & 0x01); 
         
      }
  
    colCount--;
       delay(3);
       digitalWrite(2, HIGH);
       digitalWrite(3, HIGH);
       digitalWrite(4, HIGH);
       digitalWrite(5, HIGH);
       digitalWrite(6, HIGH);
       digitalWrite(7, LOW);
       digitalWrite(8, LOW);
       digitalWrite(9, LOW);
       digitalWrite(10, LOW);
       digitalWrite(11, LOW);
       digitalWrite(12, LOW);
       digitalWrite(13, LOW);


    }

}

void topDebounce(){
  reading1 = digitalRead(TOP);
  if (reading1 != lastbutstat1){
    lDebounceT1=millis();
    butstat1 = reading1;
  }
  if((millis()-lDebounceT1) >dbnceDelay){
    if (reading1 != butstat1){
      if (butstat1 == LOW){
        if (c == 0x5e){
          c=0x00;
        }
        else{
          c++;
        }
      }
    }
    lastbutstat1 = butstat1;
  }
}

void bottDebounce(){
  reading2 = digitalRead(BOTT);
  if (reading2 != lastbutstat2){
    lDebounceT2=millis();
    butstat2 = reading2;
  }
  if((millis()-lDebounceT2) >dbnceDelay){
    if (reading2 != butstat2){
      if (butstat2 == LOW){
        if (c == 0x00){
          c=0x5e;
        }
        else{
          c--;
        }
      }
    }
    lastbutstat2 = butstat2;
  }
}
