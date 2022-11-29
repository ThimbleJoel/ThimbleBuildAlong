const int ledSocket = 6;
const int buttonSocket = 5;

void setup(){
  pinMode(ledSocket, OUTPUT);
  pinMode(buttonSocket, INPUT);
}

void loop(){
  if(not digitalRead(buttonSocket)){
    digitalWrite(ledSocket, HIGH);
  }
  else{
    digitalWrite(ledSocket, LOW);
  }
}
