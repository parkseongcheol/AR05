#include "LedControl.h"   

int xPin = A0;  
int yPin = A1;  
int zPin = 7;   
LedControl lc = LedControl(12, 11, 10, 1); 
 
byte a[8] = { B00001000, B00011000, B00111000, B11111111, B11111111, B00111000, B00011000, B00001000};   
byte b[8] = { B00010000, B00011000, B00011100, B11111111, B11111111, B00011100, B00011000, B00010000};   
byte c[8] = { B00011000, B00111100, B01111110, B11111111, B00011000, B00011000, B00011000, B00011000};   
byte d[8] = { B00011000, B00011000, B00011000, B00011000, B11111111, B01111110, B00111100, B00011000};   
byte z[8] = { B10000001, B01000010, B00100100, B00011000, B00011000, B00100100, B01000010, B10000001};   
 
void setup()
{
  pinMode(zPin,INPUT); 
  lc.shutdown(0, false);  
  lc.setIntensity(0, 8);  
  lc.clearDisplay(0);     
}
void loop()
{
  int xValue = analogRead(xPin);  
  int yValue = analogRead(yPin);  
  int zValue = digitalRead(zPin); 

  if(xValue >1000){ 
    for (int row = 0; row < 8; row++) 
    { 
      lc.setRow(0, row, a[row]);  
      delay(25);
    }
  }
  else if(xValue <10){   
    for (int row = 0; row < 8; row++)  
    {
      lc.setRow(0, row, b[row]);    
      delay(25);
    }
  }
  else if(yValue > 1000){  
    for (int row = 0; row < 8; row++) 
    {
      lc.setRow(0, row, c[row]);  
      delay(25);
    }
  }
  else if(yValue <11){   
    for (int row = 0; row < 8; row++)  
    {
      lc.setRow(0, row, d[row]);    
      delay(25);
    }
  }
  else if(zValue == HIGH){    
    for (int row = 0; row < 8; row++)  
    {
      lc.setRow(0, row, z[row]); 
      delay(30);
    }
  }
}
