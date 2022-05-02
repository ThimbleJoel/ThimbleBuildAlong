#include <Wire.h>
#include "rgb_lcd.h"

const int dialSocket = A0;

rgb_lcd lcd;
const int colorR = 128;
const int colorG = 128;
const int colorB = 128;

int dialReading = 8;
int testReading;
int pick = 0;
String messages[] = {
  "Sunday", 
  "Monday",
  "Tuesday",
  "Wednesday",
  "Thursdays",
  "Friday",
  "Saturday"};

void setup() {
  // put your setup code here, to run once:
  pinMode(dialSocket, INPUT);
  lcd.begin(16, 2);
  lcd.setRGB(colorR, colorG, colorB);
}

void loop() {
  // put your main code here, to run repeatedly:
  testReading = 6-analogRead(dialSocket)/147;
  if(dialReading != testReading){
    dialReading = 6-analogRead(dialSocket)/147;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(messages[dialReading]);
    lcd.setCursor(0, 1);
    lcd.print(dialReading);
    }
}
