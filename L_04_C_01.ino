const int buttonSocket = 5;
const int buzzerSocket = 6;

void setup() {
  pinMode(buttonSocket, INPUT);
  pinMode(buzzerSocket, OUTPUT);
}

void loop() {
  if (digitalRead(buttonSocket)) {
    tone(buzzerSocket, 330);
    delay(500);
    noTone(buzzerSocket);
    delay(250);
  }
}
