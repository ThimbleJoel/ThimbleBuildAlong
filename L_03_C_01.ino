const int buttonSocket = 5;
const int buzzerSocket = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonSocket, INPUT);
  pinMode(buzzerSocket, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(buzzerSocket, digitalRead(buttonSocket));
}
