#include <Wire.h>
#include "rgb_lcd.h"
const int buttonSocket = 4;
const int dialSocket = A0;

rgb_lcd lcd;
const int colorR = 128;
const int colorG = 128;
const int colorB = 128;

int flip;
int dialReading = -1;
int compReading = 0;
int flipCount = 1;
int headsCount = 0;
int tailsCount = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonSocket, INPUT);
  pinMode(dialSocket, INPUT);
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
  randomSeed(analogRead(A3));
  lcd.setCursor(0,1);
  lcd.print("Click to Flip");
}

void loop() {
  // put your main code here, to run repeatedly:
  while(not digitalRead(buttonSocket)){
    compReading = 1000;
    if(compReading != dialReading){
      dialReading = 1000;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Sim " + String(dialReading) + " flips");
      lcd.setCursor(0, 1);
      lcd.print("Click to Run");
    }
  }
  for(int x = dialReading; x > 0; x--){
    flip = random(0, 2);
    lcd.clear();
    lcd.setCursor(0, 1);
    if(flip == 0){
      lcd.print("Flip " + String(flipCount) +  " Heads");
      headsCount++;
    }
    else{
      lcd.print("Flip " + String(flipCount) +  " Tails");
      tailsCount++;
    }
    flipCount++;
    lcd.setCursor(0, 0);
    lcd.print("H: " + String(headsCount) + " T: " + String(tailsCount));
    delay(10);
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("H: " + String(headsCount) + " T: " + String(tailsCount));
  lcd.setCursor(0, 1);
  lcd.print("Click to reset");
  while(not digitalRead(buttonSocket)){
    delay(50);
  }
  while(digitalRead(buttonSocket)){
    delay(50);
  }
  dialReading = -1;
  flipCount = 1;
  headsCount = 0;
  tailsCount = 0;
}

