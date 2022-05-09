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
String pick;
int score = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonSocket, INPUT);
  pinMode(dialSocket, INPUT);
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
  randomSeed(analogRead(A3));
  lcd.setCursor(0,0);
  lcd.print("Dial to select");
  lcd.setCursor(0, 1);
  lcd.print("Click to play");
  while(not digitalRead(buttonSocket)){
    
  }
  while(digitalRead(buttonSocket)){
    delay(50);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  while(not digitalRead(buttonSocket)){
    if(analogRead(dialSocket)/512 != dialReading){
      dialReading = analogRead(dialSocket)/512;
      lcd.clear();
      lcd.setCursor(0, 0);
      if(dialReading == 0){
        lcd.print("Call heads");
        pick = "Heads";
      }
      else{
        lcd.print("Call tails");
        pick = "Tails";
      }
      lcd.setCursor(0, 1);
      lcd.print("Click to flip");
    }
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("You picked " + pick);
  delay(500);
  lcd.setCursor(0, 1);
  lcd.print("flipping...");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  flip = random(0, 2);
  if(flip == 0){
    lcd.print("Coin is heads!");
  }
  else{
    lcd.print("Coin is tails!");
  }
  lcd.setCursor(0, 1);
  if(dialReading == flip){
    lcd.print("You called it!");
    score++;
  }
  else{
    lcd.print("You picked wrong!");
    score--;
  }
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Score: "+ String(score));
  lcd.setCursor(0, 1);
  lcd.print("Click to replay");
  while(not digitalRead(buttonSocket)){
    delay(50);
  }
  while(digitalRead(buttonSocket)){
    delay(50);
  }
  dialReading = -1;

}
