const int ledSocket = 6;

void setup() {
  pinMode(ledSocket, OUTPUT);
}

void loop() {
  analogWrite(ledSocket, 0);
  delay(500);
  analogWrite(ledSocket, 64);
  delay(500);
  analogWrite(ledSocket, 127);
  delay(500);
  analogWrite(ledSocket, 191);
  delay(500);
  analogWrite(ledSocket, 255);
  delay(500);
}
