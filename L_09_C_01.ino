#include <Wire.h>
#include "rgb_lcd.h"
const int buttonSocket = 4;

rgb_lcd lcd;
const int colorR = 128;
const int colorG = 128;
const int colorB = 128;

int count = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonSocket, INPUT);
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
  lcd.setCursor(0, 0);
  lcd.print(count);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(buttonSocket)){
    count++;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(count);
    while(digitalRead(buttonSocket)){
      delay(50);
    }
  }
}
