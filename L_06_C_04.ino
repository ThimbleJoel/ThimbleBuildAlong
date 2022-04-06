#include <Wire.h>
#include "rgb_lcd.h"
int buttonSocket = 4;
int dialSocket = A0;

rgb_lcd lcd;
const int colorR = 255;
const int colorG = 255;
const int colorB = 255;
int diceRoll;
int diceNum;
int dialReading;
int loc;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonSocket, INPUT);
  pinMode(dialSocket, INPUT);
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
  randomSeed(analogRead(3));
}

void loop() {
  // put your main code here, to run repeatedly:
  diceNum = 1 + analogRead(dialSocket)/128;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Press to Roll " + String(diceNum));
  while(not digitalRead(buttonSocket)){
    delay(15);
    dialReading = 1+analogRead(dialSocket)/128;
    if(diceNum != dialReading){
      diceNum = dialReading;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Press to Roll " + String(diceNum));
    }
  }
  loc = 0;
  for(int x = diceNum; x > 0; x--){
    lcd.setCursor(loc, 1);
    lcd.print(random(1,7));
    loc += 2;
    delay(500);
  }
  delay(500);
  while(digitalRead(buttonSocket)){
    delay(15);
    }
  lcd.setCursor(0, 0);
  lcd.print("Press to Reset  ");
  while(not digitalRead(buttonSocket)){
    delay(15);
  }
  while(digitalRead(buttonSocket)){
    delay(15);    
  }

}
