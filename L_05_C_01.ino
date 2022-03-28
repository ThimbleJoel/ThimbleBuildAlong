const int buttonSocket = 6;
const int ledSocket = 7;
const int buzzerSocket = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonSocket, INPUT);
  pinMode(ledSocket, OUTPUT);
  pinMode(buzzerSocket, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(not digitalRead(buttonSocket)){
    delay(10);
  }
  digitalWrite(ledSocket, HIGH);
  delay(100);
  digitalWrite(ledSocket, LOW);
  while(digitalRead(buttonSocket)){
    delay(10);
  }
  digitalWrite(buzzerSocket, HIGH);
  delay(100);
  digitalWrite(buzzerSocket, LOW);
}
