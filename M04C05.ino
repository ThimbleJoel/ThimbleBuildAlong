const int buttonSocket = 5;
const int buzzerSocket = 6;
const int dialSocket = A0;
float note;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonSocket, INPUT);
  pinMode(buzzerSocket, OUTPUT);
  pinMode(dialSocket, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(buttonSocket)){
    note = analogRead(dialSocket)*.3 + 180;
    tone(buzzerSocket, note);
    delay(500);
    noTone(buzzerSocket);
  }
}
