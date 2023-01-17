//leds
int O = 6;
int G = 5;
int R = 4;
int Y = 3;
int B = 2;
int unknow = 0;
int push = 7;

void setup() {
  pinMode(O, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(R, OUTPUT);
  pinMode(Y, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(push, INPUT_PULLUP);
}

void loop() {

  if (digitalRead(push) == LOW)
  {
    unknow = random(1, 6);
    delay(300);
  }

  switch (unknow)
  {
    case 1:
      digitalWrite(O, HIGH);
      digitalWrite(G, LOW);
      digitalWrite(R, LOW);
      digitalWrite(Y, LOW);
      digitalWrite(B, LOW);
      break;

    case 2:
      digitalWrite(O, LOW);
      digitalWrite(G, HIGH);
      digitalWrite(R, LOW);
      digitalWrite(Y, LOW);
      digitalWrite(B, LOW);
      break;

    case 3:
      digitalWrite(O, LOW);
      digitalWrite(G, LOW);
      digitalWrite(R, HIGH);
      digitalWrite(Y, LOW);
      digitalWrite(B, LOW);
      break;

    case 4:
      digitalWrite(O, LOW);
      digitalWrite(G, LOW);
      digitalWrite(R, LOW);
      digitalWrite(Y, HIGH);
      digitalWrite(B, LOW);
      break;

    case 5:
      digitalWrite(O, LOW);
      digitalWrite(G, LOW);
      digitalWrite(R, LOW);
      digitalWrite(Y, LOW);
      digitalWrite(B, HIGH);
      break;

    case 6:
      digitalWrite(O, HIGH);
      digitalWrite(G, HIGH);
      digitalWrite(R, HIGH);
      digitalWrite(Y, HIGH);
      digitalWrite(B, HIGH);
      break;

  }




}
