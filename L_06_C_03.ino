#include <Wire.h>
#include "rgb_lcd.h"
int buttonSocket = 4;

rgb_lcd lcd;
const int colorR = 128;
const int colorG = 128;
const int colorB = 128;
int diceRoll; 

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonSocket, INPUT);
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
  randomSeed(analogRead(3));
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Press to Roll");
  while(not digitalRead(buttonSocket)){
    delay(15);
  }
  diceRoll = random(1, 7);
  lcd.setCursor(0, 1);
  lcd.print(diceRoll);
  delay(500);
  while(digitalRead(buttonSocket)){
    delay(15);
    }
  lcd.setCursor(0, 0);
  lcd.print("Press to Reset");
  while(not digitalRead(buttonSocket)){
    delay(15);
  }
  while(digitalRead(buttonSocket)){
    delay(15);    
  }

}
