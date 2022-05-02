#include <Wire.h>
#include "rgb_lcd.h"

const int buttonSocket = 5;

rgb_lcd lcd;
const int colorR = 128;
const int colorG = 128;
const int colorB = 128;

int pick = 0;
String messages[] = {"A", "B", "C", "D", "E"};

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonSocket, INPUT);
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  lcd.setCursor(pick, 0);
  lcd.print(messages[pick]);
  lcd.setCursor(pick, 1);
  lcd.print(pick);
  while(not digitalRead(buttonSocket)){
    delay(10);
  }
  pick++;
  if(pick==5){
    pick = 0;
  }
  while(digitalRead(buttonSocket)){
    delay(10);
  }
}
