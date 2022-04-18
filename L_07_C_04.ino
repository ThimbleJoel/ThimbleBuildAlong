#include <Wire.h>
#include "rgb_lcd.h"
const int buttonSocket = 4; 

rgb_lcd lcd;
int colorR = 255;
int colorG = 255;
int colorB = 255;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonSocket, INPUT);
  lcd.begin(16, 2); 
  lcd.setRGB(colorR, colorG, colorB);
  randomSeed(analogRead(0));
}

void loop() {
  // put your main code here, to run repeatedly:
  while(not digitalRead(buttonSocket)){
    delay(15);
  }
  colorR = random(0, 51)*5;
  colorG = random(0, 51)*5;
  colorB = random(0, 51)*5;
  lcd.setRGB(colorR, colorG, colorB);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("R: " + String(colorR) + " G: " + String(colorG));
  lcd.setCursor(0, 1);
  lcd.print("B: " + String(colorB));
  while(digitalRead(buttonSocket)){
    delay(15);
  }
}
