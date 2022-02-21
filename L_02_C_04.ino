const int ledSocket = 6;
const int dialSocket = A0;
int pause;


void setup() {
  pinMode(ledSocket, OUTPUT);
  pinMode(dialSocket, INPUT);
}

void loop() {
  pause = 100+analogRead(dialSocket);
  digitalWrite(ledSocket, HIGH);
  delay(pause);
  pause = 100+analogRead(dialSocket);
  digitalWrite(ledSocket, LOW);
  delay(pause);
}
