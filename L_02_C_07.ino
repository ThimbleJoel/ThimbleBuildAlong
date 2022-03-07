const int ledSocket = 6;
int brightness = 0;
int fadeAmount = 5;

void setup() {
  pinMode(ledSocket, OUTPUT);
}

void loop() {
  analogWrite(ledSocket, brightness);
  brightness = brightness + fadeAmount;
  if (brightness <= 0 || brightness >= 255){
    fadeAmount = -fadeAmount;
  }
  delay(50);
}
