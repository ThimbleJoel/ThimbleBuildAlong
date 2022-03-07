const int ledSocket = 6;
const int buttonSocket = 4; 
int brightness = 0;
int fadeAmount = 5;
bool runState = false;

void setup() {
  pinMode(ledSocket, OUTPUT);
  pinMode(buttonSocket, INPUT);
}

void loop() {
  if(runState == true){
    analogWrite(ledSocket, brightness);
    brightness = brightness + fadeAmount;
    if (brightness <= 0 || brightness >= 255){
      fadeAmount = -fadeAmount;
  }
  delay(50);
  }
  if(digitalRead(buttonSocket)){
    runState = not runState;
    while(digitalRead(buttonSocket)){
      delay(10);
    }
  }
}

