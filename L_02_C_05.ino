const int ledSocket = 6;
const int dialSocket = A0;
int dialReading;
int brightness;

void setup() {
  pinMode(ledSocket, OUTPUT);
  pinMode(dialSocket, INPUT); 
}

void loop() {
  dialReading = analogRead(dialSocket);
  if (dialReading < 512){
    brightness = dialReading/2;
    analogWrite(ledSocket, brightness);
  }
  if (dialReading > 512){
    brightness = 255 - (dialReading-512)/2;
    analogWrite(ledSocket, brightness);
  }
}

