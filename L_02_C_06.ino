const int ledSocket = 6;
const int dialSocket = A0;
int dialReading;

void setup() {
  pinMode(ledSocket, OUTPUT);
  pinMode(dialSocket, INPUT); 
}

void loop() {
  dialReading = analogRead(dialSocket);
  if (dialReading < 512){
    analogWrite(ledSocket, dialReading/2);
  }
  if (dialReading > 512){
    analogWrite(ledSocket, 255 - (dialReading-512)/2);
  }
}

