const int ledSocket = 6;
const int buttonSocket = 5; 
int brightness = 0;
int fadeAmount = 5;

void setup() {
  pinMode(ledSocket, OUTPUT);
  pinMode(buttonSocket, INPUT);
}

void loop() {
  while(digitalRead(buttonSocket)){
    analogWrite(ledSocket, brightness);
    brightness = brightness + fadeAmount;
    if (brightness <= 0 || brightness >= 255){
      fadeAmount = -fadeAmount;
  }
  delay(50);
  }
}
