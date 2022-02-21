const int ledSocket = 6;
const int dialSocket = A0;
int brightness;


void setup() {
  pinMode(ledSocket, OUTPUT);
  pinMode(dialSocket, INPUT);
}

void loop() {
  brightness = analogRead(dialSocket)/4;
  analogWrite(ledSocket, brightness);
}
