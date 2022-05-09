#include <Wire.h>
#include "rgb_lcd.h"
const int buttonSocket = 4;

rgb_lcd lcd;
const int colorR = 128;
const int colorG = 128;
const int colorB = 128;

int flip;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonSocket, INPUT);
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
  randomSeed(analogRead(A3));
  lcd.setCursor(0,1);
  lcd.print("Click to Flip");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(buttonSocket)){
    flip = random(0,2);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("flipping...");
    delay(750);
    lcd.clear();
    lcd.setCursor(0, 0);
    if(flip == 0){
      lcd.print("Heads");
    }
    else{
      lcd.print("Tails");
    }
    while(digitalRead(buttonSocket)){
      delay(50);
    }
    delay(750);
    lcd.setCursor(0, 1);
    lcd.print("Click to flip");
  }
}
