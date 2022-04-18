#include <Wire.h>
#include "rgb_lcd.h"
const int buttonSocket = 4; 
const int dialSocket = A0;

rgb_lcd lcd;
int colorR = 0;
int colorG = 0;
int colorB = 0;


void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2); 
  lcd.setRGB(colorR, colorG, colorB);
}

void loop() {
  // put your main code here, to run repeatedly:

}
