const int buzzerSocket = 6;
const int buttonSocket = 5;

void setup(){
  pinMode(buzzerSocket, OUTPUT);
  pinMode(buttonSocket, INPUT);
}

void loop(){
  if(not digitalRead(buttonSocket)){
    digitalWrite(buzzerSocket, HIGH);
  }
  else{
    digitalWrite(buzzerSocket, LOW);
  }
}
