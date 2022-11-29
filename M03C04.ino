const int ledSocket = 6;
const int buttonSocket = 5;

bool ledState = false; 

void setup(){
  pinMode(ledSocket, OUTPUT);
  pinMode(buttonSocket, INPUT);
}

void loop(){
  if(digitalRead(buttonSocket)){
    ledState = not ledState; 
    digitalWrite(ledSocket, ledState);
    while(digitalRead(buttonSocket)){
      delay(10);
    }
  }
}
