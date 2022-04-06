#include <Wire.h>
#include "rgb_lcd.h"
int dialSocket = A0;

rgb_lcd lcd;
const int colorR = 128;
const int colorG = 128;
const int colorB = 128;

int displayNum = -1;

void setup() {
  // put your setup code here, to run once:
  pinMode(dialSocket, INPUT);
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
}

void loop() {
  // put your main code here, to run repeatedly:
  displayNum = analogRead(dialSocket)/128;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(String(displayNum));
  delay(10);
}
