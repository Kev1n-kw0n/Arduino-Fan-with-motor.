
const int ENABLE = 5;
const int DIRA = 3;
const int DIRB = 4;

void setup() {
  pinMode(ENABLE, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);

}
void loop() {
  digitalWrite(DIRA, HIGH);
  digitalWrite(DIRB, LOW);
  for(int speed = 0; speed <= 255; speed++){
    digitalWrite(ENABLE, speed);
    delay(10);
  }

}

