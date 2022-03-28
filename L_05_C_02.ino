#include <Wire.h>
#include "rgb_lcd.h"

const int buttonSocket = 6;
const int dialSocket = A0;
int seconds = -1;
int dialReading;

rgb_lcd lcd;
const int colorR = 128;
const int colorG = 128;
const int colorB = 128;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonSocket, INPUT);
  pinMode(dialSocket, INPUT);
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(not digitalRead(buttonSocket)){
    dialReading = analogRead(dialSocket)/35;
    if(seconds != 1 + dialReading){
      seconds = 1 + dialReading;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(seconds);      
    }
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("start!");
  delay(1000);
  for(int x = seconds; x >= 0; x --){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(x);
    delay(1000);
  }
  seconds = -1;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("done!");
  delay(1000);
  while(digitalRead(buttonSocket)){
    delay(10);
  }
}
