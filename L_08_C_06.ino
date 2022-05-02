#include <Wire.h>
#include "rgb_lcd.h"
const int buttonSocket = 5;
const int dialSocket = A0;

rgb_lcd lcd;
const int colorR = 128;
const int colorG = 128;
const int colorB = 128;

int dialReading = -1;
int testReading;
int p1Score = 0;
int p2Score = 0;

char *messages[] = {
  "+1 to player 1",
  "+1 to player 2",
  "-1 to player 1",
  "-1 to player 2",
  "reset"
};

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonSocket, INPUT);
  pinMode(dialSocket, INPUT);
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
}

void loop() {
  // put your main code here, to run repeatedly:
  testReading = analogRead(dialSocket)/205;
  if(dialReading != testReading){
      dialReading = analogRead(dialSocket)/205;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("P1: " + String(p1Score) + " P2: " + String(p2Score));
      lcd.setCursor(0, 1);
      lcd.print(messages[dialReading]);
  }
  if(digitalRead(buttonSocket)){
    if(dialReading == 0){
      p1Score++;
    }
    else if(dialReading == 1){
      p2Score++;
    }
    else if(dialReading == 2){
      p1Score--;
    }
    else if(dialReading == 3){
      p2Score--;
    }
    else{
      p1Score = 0;
      p2Score = 0;
    }
    dialReading = -1;
    while(digitalRead(buttonSocket)){
      delay(50);
    }
  }
}
