#include <Wire.h>
#include "rgb_lcd.h"
const int buttonSocket = 4; 
const int dialSocket = A0;

rgb_lcd lcd;
int colorR = 255;
int colorG = 255;
int colorB = 255;
int* colors[] = {colorR, colorG, colorB};
int pick = 0;
int dialReading;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonSocket, INPUT);
  pinMode(dialSocket, INPUT);
  lcd.begin(16, 2); 
  lcd.setRGB(colorR, colorG, colorB);
}

void loop() {
  // put your main code here, to run repeatedly:
  dialReading = analogRead(dialSocket)/4;
  while(dialReading != colors[pick]){
    colors[pick] = dialReading;
    colorR = colors[0];
    colorG = colors[1];
    colorB = colors[2];             
    lcd.setRGB(colors[0], colors[1], colors[2]);
    lcd.setCursor(0, 0);
    lcd.print("R: " + String(colorR) + " G: " + String(colorG) + "       ");
    lcd.setCursor(0, 1);
    lcd.print("B: " + String(colorB) + "   ");
  }
  if(digitalRead(buttonSocket)){
    pick++;
    if(pick == 3){
      pick = 0;
    }
    delay(200);
  }
  while(digitalRead(buttonSocket)){
    delay(15);
  }
}
