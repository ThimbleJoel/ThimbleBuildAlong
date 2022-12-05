const int ledSocket = 6;
const int buttonSocket = 5; 
const int buzzerSocket = 8;
int pause = 5000;

void win(){
  digitalWrite(ledSocket, HIGH);
  tone(buzzerSocket, 250, 200);
  delay(200);
  digitalWrite(ledSocket, LOW);
  tone(buzzerSocket, 300, 200);
  delay(200);
  digitalWrite(ledSocket, HIGH);
  tone(buzzerSocket, 350, 200);
  delay(200);
  digitalWrite(ledSocket, LOW);
  tone(buzzerSocket, 400, 200);
  delay(200);
  digitalWrite(ledSocket, HIGH);
  tone(buzzerSocket, 450, 200);
  delay(200);
  digitalWrite(ledSocket, LOW);
  tone(buzzerSocket, 500, 200);
  delay(200);
}

void lose(){
  digitalWrite(ledSocket, HIGH);
  tone(buzzerSocket, 150, 500);
  digitalWrite(ledSocket, LOW);
  pause=5000;
}

void setup() {
  pinMode(ledSocket, OUTPUT);
  pinMode(buttonSocket, INPUT);
  pinMode(buzzerSocket, OUTPUT);
}

void loop() {
  while(pause>0){
    delay(5);
    if(digitalRead(buttonSocket)){
      lose();
    }
    pause = pause -5;
  }
  digitalWrite(ledSocket, HIGH);
  pause = 500;
  while(pause>0){
    delay(5);
    if(digitalRead(buttonSocket)){
      win();
      break;
    }
    pause = pause-5;
  }
  digitalWrite(ledSocket,LOW);
  pause = 5000;
}
