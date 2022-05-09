#include <Wire.h>
#include "rgb_lcd.h"
const int buttonSocket = 4;

rgb_lcd lcd;
const int colorR = 128;
const int colorG = 128;
const int colorB = 128;

int num;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonSocket, INPUT);
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
  randomSeed(analogRead(A3));
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(buttonSocket)){
    num = random(0,3);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(num);
    while(digitalRead(buttonSocket)){
      delay(50);
    }
  }
}
