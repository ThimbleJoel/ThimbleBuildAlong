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


char *messages[] = {
  "+1 to player 1",
  "+1 to player 2",
  "-1 to player 1",
  "-1 to player 2"
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
  testReading = analogRead(dialSocket)/256;
  if(dialReading != testReading){
      dialReading = analogRead(dialSocket)/256;
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print(messages[dialReading]);
  }
}
