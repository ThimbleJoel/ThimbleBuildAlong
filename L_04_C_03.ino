const int buttonSocket = 5;
const int buzzerSocket = 6;
const int dialSocket = A0;
float pause;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonSocket, INPUT);
  pinMode(buzzerSocket, OUTPUT);
  pinMode(dialSocket, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(buttonSocket)){
    pause = analogRead(dialSocket)*.5 + 50;
    tone(buzzerSocket, 440, pause);
    delay(pause);
    tone(buzzerSocket, 330, pause);
    delay(pause);
    tone(buzzerSocket, 220, pause);
    delay(pause);
    tone(buzzerSocket, 330, pause);
    delay(pause);
    tone(buzzerSocket, 440, pause);
    delay(pause);
  }
}
