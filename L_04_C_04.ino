const int dialSocket = A0;

void setup() {
  // put your setup code here, to run once:
  pinMode(dialSocket, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(dialSocket));
  delay(500);
}
