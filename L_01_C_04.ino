const int ledSocket = 6;
const int morseUnit = 200;

void setup() {
  pinMode(ledSocket, OUTPUT);
}

void loop() {
  for (int beep = 0; beep < 3; beep++) {
    digitalWrite(ledSocket, HIGH);
    delay(morseUnit); 
    digitalWrite(ledSocket, LOW);
    delay(morseUnit);
  }
  delay(2*morseUnit);
  for (int beep = 0; beep < 3; beep++) {
    digitalWrite(ledSocket, HIGH);
    delay(3*morseUnit);
    digitalWrite(ledSocket, LOW);
    delay(morseUnit);
  }
  delay(2*morseUnit);
  for (int beep = 0; beep < 3; beep++) {
    digitalWrite(ledSocket, HIGH);
    delay(morseUnit);
    digitalWrite(ledSocket, LOW);
    delay(morseUnit);
  }
  delay(6*morseUnit);
}
