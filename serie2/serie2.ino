int pot = 0;
int b = 2;
int g = 3;
int y = 4;
int o = 5;
int r = 6;

void setup() {
  Serial.begin(9600);
  pinMode(b, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(y, OUTPUT);
  pinMode(r, OUTPUT);
  pinMode(o, OUTPUT);
}

void loop() {
  pot = analogRead(A0);
  Serial.println(pot);

  if (pot <= 29)
  {
    digitalWrite(b, LOW);
    digitalWrite(g, LOW);
    digitalWrite(y, LOW);
    digitalWrite(o, LOW);
    digitalWrite(r, LOW);
    delay(100);
  }

  if ((pot >= 30) && (pot <= 205))
  {
    digitalWrite(b, HIGH);
    digitalWrite(g, LOW);
    digitalWrite(y, LOW);
    digitalWrite(o, LOW);
    digitalWrite(r, LOW);
    delay(100);
  }

  if ((pot >= 206) && (pot <= 411))
  {
    digitalWrite(b, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(y, LOW);
    digitalWrite(o, LOW);
    digitalWrite(r, LOW);
    delay(100);
  }

  if ((pot >= 412) && (pot <= 617))
  {
    digitalWrite(b, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(y, HIGH);
    digitalWrite(o, LOW);
    digitalWrite(r, LOW);
    delay(100);
  }

  if ((pot >= 618) && (pot <= 822))
  {
    digitalWrite(b, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(y, HIGH);
    digitalWrite(o, HIGH);
    digitalWrite(r, LOW);
    delay(100);
  }

  if (pot >= 823)
  {
    digitalWrite(b, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(y, HIGH);
    digitalWrite(o, HIGH);
    digitalWrite(r, HIGH);
    delay(100);
  }

}

 
