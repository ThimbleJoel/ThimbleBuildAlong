const int ledSocket = 6;

void setup() {
  pinMode(ledSocket, OUTPUT);
}

void loop() {
  digitalWrite(ledSocket, HIGH);
  delay(500);
  digitalWrite(ledSocket, LOW);
  delay(250);
}
