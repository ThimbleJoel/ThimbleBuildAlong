const int buttonSocket = 5;
const int buzzerSocket = 6;

void setup() {
  pinMode(buttonSocket, INPUT);
  pinMode(buzzerSocket, OUTPUT);
}

void loop() {
  if (digitalRead(buttonSocket)) {
    tone(buzzerSocket, 196);
    delay(600);
    tone(buzzerSocket, 329);
    delay(600);
    tone(buzzerSocket, 261);
    delay(600);
  } else {
    noTone(buzzerSocket);
  }
}
